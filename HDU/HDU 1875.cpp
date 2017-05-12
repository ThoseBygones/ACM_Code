//Kruskal算法：
/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAXN 105
int par[MAXN],x[MAXN],y[MAXN];

struct island
{
    int code1;
    int code2;
    double len;
} is[5005];

int cmp(struct island a,struct island b)
{
    return a.len < b.len;
}

int find_set(int r)
{
    if(r!=par[r])
        return par[r]=find_set(par[r]);
    return par[r];
}

double merge_set(int x,int y,double len)
{
    int setx,sety;
    setx=find_set(x);
    sety=find_set(y);
    if(setx==sety)
        return 0;
    par[setx]=sety;
    return len*100;
}

int main()
{
    int t,n,count,node;
    double sum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1; i<=n; i++)
            par[i]=i;
        for(int i=1; i<=n; i++)
            scanf("%d %d",&x[i],&y[i]);
        count=0;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                is[count].code1=i;
                is[count].code2=j;
                is[count].len=sqrt( pow( (x[i]-x[j]) ,2) + pow( (y[i]-y[j]),2) );
                count++;
            }
        }
        sort(is,is+count,cmp);
        sum=0;
        for(int i=0; i<count; i++)
        {
            if(is[i].len>=10 && is[i].len<=1000)
            {
                sum+=merge_set(is[i].code1,is[i].code2,is[i].len);
            }
        }
        node=-1;
        for(int i=1; i<=n; i++)
        {
            if(par[i]==i)
                node++;
        }
        if(node>0)
            printf("oh!\n");
        else
            printf("%.1lf\n",sum);
    }
    return 0;
}
*/


//Prim算法：
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 105
#define INF 0x3f3f3f3f
using namespace std;

int n;
double mp[MAXN][MAXN];
bool vis[MAXN];//标记是否已经放入最小生成树的那个集合里了
double dis[MAXN];//记录不在已经加入最小生成树的这个集合里的元素到这个 集合的最小距离
int x[MAXN],y[MAXN];

double dist(int i,int j)
{
    return sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

void prim()
{
    double sum=0;
    memset(vis,0,sizeof(vis));
    int pos=1;//从1开始
    for(int i=1; i<=n; i++) //第一次给dis赋值
        dis[i]=mp[1][i];
    vis[1]=1;   //已经找到一个点1，再找n-1个
    for(int i=1; i<n; i++)
    {
        double Min=INF;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && Min>dis[j])//找下一个点到这个集合的最小值
            {
                Min=dis[j];//记下这个最小值
                pos=j;//记下这个点
            }
        }
        if(Min==INF)
        {
            printf("oh!\n");
            return ;
        }
        sum+=Min;
        vis[pos]=1;//把刚刚找到的这个点加入集合
        for(int j=1; j<=n; ++j) //更新dis数组
        {
            if(!vis[j] && dis[j]>mp[pos][j])
            {
                dis[j]=mp[pos][j];
            }
        }
    }
    printf("%.1lf\n",sum*100);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d%d",&x[i],&y[i]);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                mp[i][j]=dist(i,j);
                if(mp[i][j]>1000 || mp[i][j]<10)
                {
                    mp[i][j]=INF;
                }
            }
        }
        prim();
    }
    return 0;
}
