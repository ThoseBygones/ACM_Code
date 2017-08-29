#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 6005

int n;
int in[MAXN];   //入度
vector <int> g[MAXN];
int dp[MAXN][2];    //dp[i][j]表示第i个人出席状态为j；0--不去，1--去

int dfs(int u)
{
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        dfs(v);
        dp[u][0]+=max(dp[v][0],dp[v][1]);   //不选择父节点，则从子结点中选不选两种方案中取最大值
        dp[u][1]+=dp[v][0]; //上司去则下属必定不能去（即选择了父结点则不能选择子结点）
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        memset(in,0,sizeof(in));
        memset(dp,0,sizeof(dp));
        for(int i=0; i<=n; i++)
            g[i].clear();
        for(int i=1; i<=n; i++)
            scanf("%d",&dp[i][1]);
        int l,k;
        while(~scanf("%d%d",&l,&k))
        {
            if(l==0 && k==0)
                break;
            g[k].push_back(l);
            in[l]++;
        }
        int root=0;
        for(int i=1; i<=n; i++)
        {
            if(!in[i])
                root=i;
        }
        dfs(root);
        printf("%d\n",max(dp[root][0],dp[root][1]));
    }
    return 0;
}
