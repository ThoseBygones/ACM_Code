#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f

int a[MAXN];
int p[MAXN];    //记录每个数是否为奇数
int dp[MAXN][2];    //dp[i][0/1]为前i-1个数均为偶数，第i个数为偶数（奇数）的最少操作数；

//前i-2个数都为偶数
//1.第i个数为奇数时，要把第i个数变为偶数。若第i-1个数为偶数则需要2次操作；若第i-1个数为奇数则需要1次操作。
//2.第i个数为奇数时，要把第i个数变为奇数。若第i-1个数为偶数则不需要操作；若第i-1个数为奇数则无法实现。
//3.第i个数为偶数时，要把第i个数变为偶数。若第i-1个数为偶数则不需要操作；若第i-1个数为奇数则需要2次操作。
//4.第i个数为偶数时，要把第i个数变为奇数。若第i-1个数为偶数则无法实现；若第i-1个数为奇数则无法实现。

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int ans=a[1];
    for(int i=1; i<=n; i++)
        ans=__gcd(ans,a[i]);
    if(ans==1)
    {
        dp[1][!(a[1]&1)]=INF;   //第一个数为偶数则不可能变为奇数，反之亦然
        for(int i=2; i<=n; i++)
        {
            if(a[i]&1)
            {
                dp[i][0]=min(dp[i-1][0]+2,dp[i-1][1]+1);    //1.
                dp[i][1]=dp[i-1][0];    //2.
            }
            else
            {
                dp[i][0]=min(dp[i-1][0],dp[i-1][1]+2);  //3.
                dp[i][1]=INF;   //4.
            }
        }
        if(dp[n][0]!=INF)
        {
            puts("YES");
            printf("%d\n",dp[n][0]);
        }
        else
            puts("NO");
    }
    else
    {
        puts("YES");
        puts("0");
    }
    return 0;
}
