#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10005];
int dp[10005][105]; ///dp[i][j]为前i个数加减运算后值是否等于j（实质上dp数组是个bool数组，这也是这题最巧妙的地方！！！）
int n,k;

int mod(int x)  //负数取正
{
    x%=k;
    while(x<0)
        x+=k;
    return x;
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        dp[1][mod(a[1])]=1;
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<k; j++)  //两种模拟方式
            {
                //dp[i][j]=dp[i-1][mod(j+a[i])] || dp[i-1][mod(j-a[i])];    //dp[i][j]由dp[i-1][[mod(j+a[i])]或dp[i-1][mod(j-a[i])]得出
                if(dp[i-1][j])  //dp[i-1][j]推出dp[i][mod(j+a[i])]和dp[i][mod(j-a[i])]
                {
                    dp[i][mod(j+a[i])]=1;
                    dp[i][mod(j-a[i])]=1;
                }
            }
        }
        if(dp[n][0])
            printf("Divisible\n");
        else
            printf("Not divisible\n");
    }
    return 0;
}
