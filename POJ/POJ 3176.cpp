#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 355

int a[MAXN][MAXN];
int dp[MAXN][MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
            scanf("%d",&a[i][j]);
    }
    //dp[1][1]=a[1][1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(j==1)
                dp[i][j]=dp[i-1][j];
            else if(j==i)
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]);
            dp[i][j]+=a[i][j];
        }
    }
    int Max=0;
    for(int i=1; i<=n; i++)
        Max=max(Max,dp[n][i]);
    printf("%d\n",Max);
    return 0;
}
