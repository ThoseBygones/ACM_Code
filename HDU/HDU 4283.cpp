/*
dp[i][j]表示从第i个屌丝到第j个屌丝这段区间的最小愤怒值之和（只考虑区间内这j-i+1个屌丝）
那么对于dp[i][j]的第i个屌丝，上场次序就有可能为第1个,第2个,...,第j-i+1个上场。
考虑i号屌丝第k个上场：
1.  屌丝i第k个出场之前的情况：在区间内i号屌丝本来是第1个出场，现在是第k个出场，说明原本在屌丝i之后的k-1个屌丝现在先上场。
    于是出现子问题dp[i+1][i+k-1]表示在第i个屌丝之前上场的k-1个屌丝的愤怒值情况（相当于取最小值）；
2.  屌丝i第k个出场之时的情况：由于i号屌丝是第k个上场的。
    那么其对愤怒值之和的贡献是num[i]*(k-1)；
3.  屌丝i第k个出场之后的情况：其余的人是从第k+1个开始出场。
    即子问题dp[i+k][j]。对于这个区间的屌丝们，由于从第k+1个开始出场，所以整体愤怒值相对于最优值（从第1个开始出场）要加上k*(sum[j]-sum[i+k-1])。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int a[MAXN];
int sum[MAXN];  //前缀和
int dp[MAXN][MAXN]; //区间下标在i到j之间的男屌丝的最小愤怒值

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(sum,0,sizeof(sum));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
                dp[i][j]=INF;
        }
        for(int l=1; l<n; l++)
        {
            for(int i=1; i+l<=n; i++)
            {
                int j=i+l;
                for(int k=1; k<=j-i+1; k++) //考虑区间[i,j]（(j-i+1)为区间长度）中原本第1(i)个上场的屌丝现在第k个上场
                {
                    // 在这个屌丝之前上场的k-1个屌丝的愤怒值之和的最小值【dp[i+1][i+k]】
                    // + 第k个上场的这个屌丝的新愤怒值【num*(k-1)】
                    // + 这个屌丝之后上场的屌丝的愤怒值之和（最优值+推后k+1个上场的累加愤怒值）【dp[i+k][j]+k*(sum[j-i+1]-sum[i+k-1])】
                    dp[i][j]=min(dp[i][j],dp[i+1][i+k-1]+a[i]*(k-1)+dp[i+k][j]+k*(sum[j]-sum[i+k-1]));
                }
            }
        }
        printf("Case #%d: %d\n",kase++,dp[1][n]);
    }
    return 0;
}
