#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 40005
using namespace std;

int par[MAXN],x[MAXN],y[MAXN];
int ans[10005]; //记录每个询问的答案

struct Road
{
    int u;
    int v;
    int len;
    char dir;
} road[MAXN];

struct Query
{
    int u;
    int v;
    int id;
    int order;  //记录原来询问的顺序，以免按照id排序后打乱原来的询问顺序
} q[10005];

bool cmp(Query a,Query b)   //对id进行排序
{
    return a.id<b.id;
}

int findset(int r)
{
    if(r!=par[r])
    {
        int temp=par[r];
        par[r]=findset(par[r]);
        x[r]+=x[temp];  //更新子节点和父节点之间的道路长度
        y[r]+=y[temp];
    }
    return par[r];
}

void unionset(int i)
{
    int uu=findset(road[i].u);
    int vv=findset(road[i].v);
    if(uu!=vv)
    {
        par[uu]=vv;
        if(road[i].dir=='N')    //四个方向遍历和道路长度计算
        {
            x[uu]=x[road[i].v]-x[road[i].u];
            y[uu]=y[road[i].v]-y[road[i].u]-road[i].len;
        }
        else if(road[i].dir=='E')
        {
            x[uu]=x[road[i].v]-x[road[i].u]+road[i].len;
            y[uu]=y[road[i].v]-y[road[i].u];
        }
        else if(road[i].dir=='S')
        {
            x[uu]=x[road[i].v]-x[road[i].u];
            y[uu]=y[road[i].v]-y[road[i].u]+road[i].len;
        }
        else if(road[i].dir=='W')
        {
            x[uu]=x[road[i].v]-x[road[i].u]-road[i].len;
            y[uu]=y[road[i].v]-y[road[i].u];
        }
    }
}

int main()
{
    int n,m,k;
    scanf("%d%d",&n,&m);
    for(int i=0; i<=n; i++)
    {
        par[i]=i;
        x[i]=0;
        y[i]=0;
    }
    for(int i=1; i<=m; i++)
        scanf("%d %d %d %c",&road[i].u,&road[i].v,&road[i].len,&road[i].dir);
    scanf("%d",&k);
    for(int i=1; i<=k; i++)
    {
        scanf("%d %d %d",&q[i].u,&q[i].v,&q[i].id);
        q[i].order=i;
    }
    sort(q+1,q+k+1,cmp);
    int cnt=1;
    for(int i=1; i<=m; i++)
    {
        unionset(i);
        while(q[cnt].id==i && cnt<=k)
        {
            int tempu=findset(q[cnt].u);
            int tempv=findset(q[cnt].v);
            if(tempu==tempv)
                ans[q[cnt].order]=abs(x[q[cnt].v]-x[q[cnt].u])+abs(y[q[cnt].v]-y[q[cnt].u]);    //求出笛卡尔长度
            else
                ans[q[cnt].order]=-1;
            cnt++;
        }
        if(cnt==k+1)
            break;
    }
    for(int i=1; i<=k; i++)
        printf("%d\n",ans[i]);
    return 0;
}
