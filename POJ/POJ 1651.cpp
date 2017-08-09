#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int a[MAXN];
int dp[MAXN][MAXN]; //dp[i][j]表示取走区间下标在i到j之间（不包括i,j）的卡片获得的最小得分

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n-2; i++)
        dp[i][i+2]=a[i]*a[i+1]*a[i+2];
    for(int l=3; l<n; l++)
    {
        for(int i=1; i+l<=n; i++)
        {
            int j=i+l;
            dp[i][j]=INF;
            for(int k=i+1; k<j; k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
