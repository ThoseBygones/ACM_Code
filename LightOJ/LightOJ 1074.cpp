#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 205
#define INF 0x3f3f3f3f
using namespace std;

struct Points
{
    int v;
    int w;
    int next;
} p[MAXN*MAXN];

int busy[MAXN];
int dis[MAXN];
int used[MAXN];
int head[MAXN];
int vis[MAXN];  //判断是否形成环
int cir[MAXN];  //某个点的入队次数
int cnt;
int n,m,query;

int getAmount(int x,int y)
{
    return (y-x)*(y-x)*(y-x);
}

void addEdge(int u,int v,int w)
{
    p[cnt].v=v;
    p[cnt].w=w;
    p[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int x)
{
    vis[x]=1;
    for(int i=head[x]; i!=-1; i=p[i].next)
    {
        if(!vis[p[i].v])
            dfs(p[i].v);
    }
}

void SPFA()
{
    queue <int> q;
    for(int i=1; i<=n; i++)
    {
        dis[i]=INF;
        used[i]=0;
        cir[i]=0;
        vis[i]=0;
    }
    cir[1]++;
    dis[1]=0;
    q.push(1);
    used[1]=1;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        used[temp]=0;
        for(int i=head[temp]; i!=-1; i=p[i].next)
        {
            if(dis[temp]+p[i].w<dis[p[i].v] && !vis[temp])
            {
                dis[p[i].v]=dis[temp]+p[i].w;
                if(!used[p[i].v])
                {
                    used[p[i].v]=1;
                    cir[p[i].v]++;
                    q.push(p[i].v);
                    if(cir[p[i].v]>=n && !vis[p[i].v])
                        dfs(p[i].v);
                    //else

                }
            }
        }
    }
}

int main()
{
    int t;
    int kase=1;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            head[i]=-1;
        for(int i=1; i<=n; i++)
            scanf("%d",&busy[i]);
        scanf("%d",&m);
        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d",&u,&v);
            w=getAmount(busy[u],busy[v]);
            addEdge(u,v,w);
        }
        SPFA();
        scanf("%d",&query);
        printf("Case %d:\n",kase++);
        for(int i=1; i<=query; i++)
        {
            int temp;
            scanf("%d",&temp);
            int ans=dis[temp];
            if(ans<3 || ans==INF)
                printf("?\n");
            else
                printf("%d\n",ans);
        }
    }
    return 0;
}
