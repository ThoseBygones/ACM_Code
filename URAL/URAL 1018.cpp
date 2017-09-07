#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

struct Edge
{
    int v,w;
    int next;
} e[MAXN<<1];

int head[MAXN];
int dp[MAXN][MAXN]; //dp[i][j]表示以i为根的树取j个分支获得的最大值
int cnt;
int n,q;

void addEdge(int u,int v,int w)
{
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

int dfs(int u,int fa)
{
    int ans=0;  //u的子树有多少个分支
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        int w=e[i].w;
        if(v!=fa)
        {
            ans+=(dfs(v,u)+1);
            for(int j=min(ans,q); j>=1; j--)    //类似分组背包问题？枚举取j个分支数
            {
                for(int k=min(ans,j); k>=1; k--)    //不取k个分支数
                    dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k-1]+w);
            }
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&q);
    memset(head,-1,sizeof(head));
    memset(dp,0,sizeof(dp));
    cnt=0;
    for(int i=1; i<n; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    dfs(1,-1);
    printf("%d\n",dp[1][q]);
}
