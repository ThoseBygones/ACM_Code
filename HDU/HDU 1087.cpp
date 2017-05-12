#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

int a[MAXN];
int dp[MAXN];

int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            dp[i]=a[i];
        }
        int Max=0;
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=i-1; j++)
            {
                if(dp[j]<dp[i] && dp[i]<dp[j]+a[i])
                    dp[i]=dp[j]+a[i];
            }
            Max=max(Max,dp[i]);
        }
        printf("%d\n",Max);
    }
    return 0;
}
