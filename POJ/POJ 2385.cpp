#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

int a[MAXN];
int dp[MAXN][35];   //第i分钟走j步能摘到的最大苹果数

//初始的时候，牛在第1棵数下，故可以知道它走偶数步的时候一定在第1棵树下，走奇数步的时候一定在第2棵树下

int main()
{
    int t,w;
    scanf("%d%d",&t,&w);
    for(int i=1; i<=t; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=t; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(j==0)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);
            if(j%2+1==a[i])
                dp[i][j]++;
        }
    }
    int ans=dp[t][0];
    for(int i=1; i<=w; i++)
        ans=max(ans,dp[t][i]);
    printf("%d\n",ans);
    return 0;
}
