#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10010
#define INF 0x3f3f3f3f

struct Edge
{
    int to;
    int next;
} e[MAXN<<1];

int head[MAXN];
int num[MAXN];  //以每个结点为根子树的结点数（包含自身）
int dp[MAXN];   //dp[i]表示沿树路径到第i个点时子树结点数的最大值（不含自身）
int cnt;
int n;

void addEdge(int u,int v)
{
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

//树的重心
void dfs(int u, int fa)
{
    dp[u] = 0;
    num[u] = 1;
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v = e[i].to;
        if(v != fa)
        {
            dfs(v, u);
            num[u] += num[v];
            dp[u] = max(dp[u], num[v]);
        }
    }
    dp[u] = max(dp[u], n - num[u]);
}

int main()
{
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    cnt=0;
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1,-1);
    bool flag=true;
    for(int i=1; i<=n; i++)
    {
        if(dp[i]<=n/2)
        {
            printf("%d\n",i);
            flag=false;
        }
    }
    if(flag)
        puts("NONE");
    return 0;
}
