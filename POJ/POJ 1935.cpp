#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 50010

struct Edge
{
    int to;
    int cost;
    int next;
} e[MAXN<<1];

int head[MAXN];
int vis[MAXN];
int dp[MAXN];
int cnt;
int n,k,m;
int sum;

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
        int w=e[i].cost;
        if(v!=fa)
        {
            dp[v]=dp[u]+w;
            dfs(v,u);
            if(vis[v])
            {
                sum+=2*w;
                vis[u]=1;
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    memset(head,-1,sizeof(head));
    cnt=0;
    for(int i=1; i<n; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    memset(vis,0,sizeof(vis));
    scanf("%d",&m);
    while(m--)
    {
        int temp;
        scanf("%d",&temp);
        vis[temp]=1;
    }
    sum=0;
    dfs(k,-1);
    int Max=0;
    for(int i=1; i<=n; i++)
    {
        if(vis[i])
            Max=max(Max,dp[i]);
    }
    printf("%d\n",sum-Max);
    return 0;
}
