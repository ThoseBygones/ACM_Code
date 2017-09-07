//树形dp+01背包
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXM 205

struct Edge
{
    int to;
    int next;
} e[MAXN<<1];

int head[MAXN];
int val[MAXN];
int dp[MAXN][MAXM][2];  //dp[i][j][0/1]表示以i为根节点的子树最多走j步后不回到（回到）i能吃到的最大苹果数
int n,m;
int cnt;

void addEdge(int u,int v)
{
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int u,int fa)
{
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(v!=fa)
        {
            dfs(v,u);
            for(int j=m; j>=1; j--) //对子结点做一次01背包
            {
                for(int k=1; k<=j; k++)
                {
                    dp[u][j][0]=max(dp[u][j][0],dp[u][j-k][1]+dp[v][k-1][0]);   //先遍历u的其他子树后返回u，从u到v不返回（只需1步）
                    dp[u][j][0]=max(dp[u][j][0],dp[u][j-k][0]+dp[v][k-2][1]);   //先从u到v后返回，然后再遍历u的其他子树不返回（需要2步）
                    dp[u][j][1]=max(dp[u][j][1],dp[u][j-k][1]+dp[v][k-2][1]);   //遍历u的其他子树后返回u，从u到v再返回u（需要2步）
                }
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(head,-1,sizeof(head));
        memset(dp,0,sizeof(dp));
        cnt=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&val[i]);
            for(int j=0; j<=m; j++)
                dp[i][j][0]=dp[i][j][1]=val[i];
        }
        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        dfs(1,-1);
        printf("%d\n",max(dp[1][m][0],dp[1][m][1]));
    }
    return 0;
}
