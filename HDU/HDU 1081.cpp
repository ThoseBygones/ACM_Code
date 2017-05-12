//前缀和+dp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int dp[MAXN][MAXN];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                int temp;
                scanf("%d",&temp);
                dp[i][j]=dp[i][j-1]+temp;   //第i行前j列和（前缀和）
            }
        }
        int Max=-INF;
        for(int i=1; i<=n; i++)
        {
            for(int j=i; j<=n; j++)
            {
                int sum=0;
                for(int k=1; k<=n; k++)
                {
                    sum=max(sum,0);
                    sum+=dp[k][j]-dp[k][i-1];   //前k行第i->j列的和
                    Max=max(Max,sum);
                }
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}
