//树形dp + LCA Tarjan
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100010

struct Edge
{
    int to;
    int next;
} e[MAXN<<2];

int head1[MAXN];
int head2[MAXN];
int vis[MAXN];
int par[MAXN];  //父结点
int dp[MAXN];   //dp[i]表示i和它父亲相连的那条边被覆盖的次数
int cnt;
int n,m;

void init()
{
    memset(head1,-1,sizeof(head1));
    memset(head2,-1,sizeof(head2));
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    cnt=0;
    for(int i=1; i<=n; i++)
        par[i]=i;
}

void addEdge(int u,int v,int head[])
{
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

int findset(int x)
{
    if(x!=par[x])
        return par[x]=findset(par[x]);
    return par[x];
}

//dfs+并查集离线处理LCA
void Tarjan(int u,int fa)
{
    for(int i=head1[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(v!=fa)
        {
            Tarjan(v,u);
            par[v]=u;
        }
    }
    vis[u]=true;
    for(int i=head2[u]; ~i; i=e[i].next)  //每一询问加两条边
    {
        int v=e[i].to;
        if(vis[v])
        {
            int lca=findset(v);
            dp[u]++;
            dp[v]++;
            dp[lca]-=2;
        }
    }
}

void dfs(int u,int fa)
{
    for(int i=head1[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(v!=fa)
        {
            dfs(v,u);
            dp[u]+=dp[v];
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    init();
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v,head1);
        addEdge(v,u,head1);
    }
    for(int i=1; i<=m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v,head2);
        addEdge(v,u,head2);
    }
    Tarjan(1,-1);
    dfs(1,-1);
    int ans=0;
    for(int i=2; i<=n; i++)
    {
        if(dp[i]==0)
            ans+=m;
        if(dp[i]==1)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
