#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

int a[MAXN][MAXN];
int dp[MAXN][MAXN];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
                scanf("%d",&a[i][j]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(j==1)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);
                dp[i][j]+=a[i][j];
            }
        }
        int ans=0;
        for(int j=1; j<=n; j++)
            ans=max(ans,dp[n][j]);
        printf("%d\n",ans);
    }
    return 0;
}
