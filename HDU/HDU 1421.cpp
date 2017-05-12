#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f

int a[MAXN*2];
int dp[MAXN*2][MAXN]; //前i个物品取j对得到的最小疲劳度
int n,k;

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        memset(dp,INF,sizeof(dp));
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=0; i<=n; i++)
            dp[i][0]=0;
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j*2<=i; j++)
                dp[i][j]=min(dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]),dp[i-1][j]);
        }
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
