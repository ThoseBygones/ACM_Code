#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int a[25][1005];
int dp[25][1005];
int n,m;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                scanf("%d",&a[i][j]);
        }
        for(int i=0; i<=n; i++)
            dp[i][0]=-INF;
        for(int j=0; j<=m; j++)
            dp[0][j]=-INF;
        dp[0][1]=dp[1][0]=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                for(int k=1; k<=m; k++)
                {
                    if(j%k==0)
                        dp[i][j]=max(dp[i][j],dp[i][j/k]);
                }
                dp[i][j]+=a[i][j];
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
