//树形dp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f

struct Edge
{
    int to;
    int cost;
    int next;
} e[MAXN<<1];

int head[MAXN];
int w[MAXN];
int d[MAXN];    //距离该点最近防火站的最远距离的限制
int dis[MAXN][MAXN];    //两点之间的距离
int dp[MAXN][MAXN]; //dp[i][j]表示在j点建消防站保护i点时的需要的最小花费
int best[MAXN];
int cnt;
int n;
int cur;    //计算两点之间距离时的点

void addEdge(int u,int v,int w)
{
    e[cnt].to=v;
    e[cnt].cost=w;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int u,int fa)
{
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(v!=fa)
            dfs(v,u);
    }
    for(int i=1; i<=n; i++)
    {
        if(dis[u][i]<=d[u])  //符合保护要求
        {
            dp[u][i]=w[i];
            for(int j=head[u]; ~j; j=e[j].next)
            {
                int v=e[j].to;
                if(v!=fa)
                {
                    dp[u][i]+=min(dp[v][i]-w[i],best[v]);    //u的子结点v也依靠i点，故不需要重复计算花费
                }
            }
            best[u]=min(best[u],dp[u][i]);  //对于u点选择最省钱的保护方案
        }
    }
}

void getDis(int u,int fa)
{
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        int w=e[i].cost;
        if(v!=fa)
        {
            dis[cur][v]=dis[cur][u]+w;  //求出两点间最短距离
            getDis(v,u);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(head,-1,sizeof(head));
        memset(dis,0,sizeof(dis));
        cnt=0;
        for(int i=1; i<=n; i++)
        {
            best[i]=INF;
            for(int j=1; j<=n; j++)
                dp[i][j]=INF;
        }
        for(int i=1; i<=n; i++)
            scanf("%d",&w[i]);
        for(int i=1; i<=n; i++)
            scanf("%d",&d[i]);
        for(int i=1; i<n; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
            addEdge(v,u,w);
        }
        for(int i=1; i<=n; i++)
        {
            cur=i;
            getDis(i,-1);
        }
        dfs(1,-1);
        printf("%d\n",best[1]);
    }
    return 0;
}
