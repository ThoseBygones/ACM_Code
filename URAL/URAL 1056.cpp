#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005
#define INF 0x3f3f3f3f

struct Edge
{
    int to;
    int cost;
    int next;
} e[MAXN<<1];

int head[MAXN];
int dp[MAXN][2];    //dp[i][0/1]表示以i点为树根（从i点出发）能到最远儿子的距离和到次远儿子的距离
int d[MAXN];    //某点通过父节点向上能走到的最远距离
int ans[MAXN];
int n;
int cnt;

void addEdge(int u,int v,int w)
{
    e[cnt].to=v;
    e[cnt].cost=w;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs1(int u, int fa)
{
    dp[u][0] = dp[u][1] = 0;
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v = e[i].to;
        int w = e[i].cost;
        if(v != fa)
        {
            dfs1(v, u);
            if(dp[u][0] < dp[v][0] + w) //更新到最远儿子的距离
            {
                dp[u][1] = dp[u][0];    //到最远儿子的距离更新为到次远儿子的距离
                dp[u][0] = dp[v][0] + w;
            }
            else if(dp[u][1] < dp[v][0] + w)    //到最远儿子的距离不需要更新，只需要更新到次远儿子的距离
                dp[u][1] = dp[v][0] + w;
        }
    }
}

void dfs2(int u, int fa)
{
    if(fa != -1)
    {
        if(dp[u][0] + 1 == dp[fa][0])
            d[u] = max(dp[fa][1], d[fa]) + 1;
        else
            d[u] = max(dp[fa][0], d[fa]) + 1;
    }
    ans[u] = max(d[u], dp[u][0]);
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v = e[i].to;
        if(v != fa)
            dfs2(v, u);
    }
}

int main()
{
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    cnt=0;
    for(int i=2; i<=n; i++)
    {
        int v;
        scanf("%d",&v);
        addEdge(i,v,1);
        addEdge(v,i,1);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    int Min=INF;
    for(int i=1; i<=n; i++)
        Min=min(Min,ans[i]);
    bool flag=true;
    for(int i=1; i<=n; i++)
    {
        if(ans[i]==Min)
        {
            if(flag)
            {
                printf("%d",i);
                flag=false;
            }
            else
                printf(" %d",i);
        }
    }
    puts("");
    return 0;
}
