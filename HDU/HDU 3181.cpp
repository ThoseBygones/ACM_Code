//模拟大数运算... 16ms... （Java大数虽然很方便但是1500ms+显然慢多了= =）
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LIMIT 100000000000000000

// 0高位 1低位
long long dp[105][1005][2];	// dp[i][j] := 用i种价格配出金额j的方案数

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= k; i++)
    {
        dp[i][0][1] = 1;
        for(int j = 1; j <= n; j++)
        {
            if(j < i)
            {
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j][1];
            }
            else
            {
                dp[i][j][0] = dp[i-1][j][0] + dp[i][j-i][0];
                dp[i][j][1] = dp[i-1][j][1] + dp[i][j-i][1];
                // 高位进位
                dp[i][j][0] += dp[i][j][1] / LIMIT;
                // 低位限制
                dp[i][j][1] = dp[i][j][1] % LIMIT;
            }
        }
    }

    if(dp[k][n][0])
        printf("%lld",dp[k][n][0]);
    printf("%lld\n",dp[k][n][1]);
    return 0;
}
