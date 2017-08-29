#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 6005

int n;
int fa[MAXN];   //每个结点的父节点
int vis[MAXN];
int dp[MAXN][2];    //dp[i][j]表示第i个人出席状态为j；0--不去，1--去

int dfs(int u)
{
    vis[u]=1;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i] && fa[i]==u)
        {
            dfs(i);
            dp[u][0]+=max(dp[i][0],dp[i][1]);   //不选择父节点，则从子结点中选不选两种方案中取最大值
            dp[u][1]+=dp[i][0]; //上司去则下属必定不能去（即选择了父结点则不能选择子结点）
        }
    }
}

int main()
{
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    memset(fa,0,sizeof(fa));
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
        scanf("%d",&dp[i][1]);
    int root=0;
    int l,k;
    while(~scanf("%d%d",&l,&k))
    {
        if(l==0 && k==0)
            break;
        fa[l]=k;
        root=k;
    }
    while(fa[root])
        root=fa[root];
    dfs(root);
    printf("%d\n",max(dp[root][0],dp[root][1]));
    return 0;
}
