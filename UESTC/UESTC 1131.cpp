#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int a[MAXN];
int sum[MAXN];  //前缀和数组
int dp[MAXN][MAXN]; //加工区间[i,j]之间的材料需要消耗的最小体力

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);

        for(int i=1; i<=n; i++)
            sum[i]=sum[i-1]+a[i];

        for(int i=n; i>=1; i--)
        {
            for(int j=i; j<=n; j++)
            {
                dp[i][j]=INF;
                if(i==j)
                    dp[i][j]=0;
                for(int k=i; k<j; k++)  //枚举区间中点k
                {
                    int x=(sum[k]-sum[i-1]+100)%100;
                    int y=(sum[j]-sum[k]+100)%100;
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+x*y);
                }
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
