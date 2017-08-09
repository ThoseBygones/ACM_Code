#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

int a[MAXN];
int dp[MAXN][MAXN]; //区间下标i到区间下标j需要的衣服的最少数量

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
                dp[i][j]=j-i+1;
        }
        for(int j=1; j<n; j++)
        {
            for(int i=j-1; i>=0; i--)
            {
                dp[i][j]=dp[i+1][j]+1;  //一件一件穿
                for(int k=i+1; k<=j; k++)   //枚举区间中间点k
                {
                    if(a[i]==a[k])
                        dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
                }
            }
        }
        printf("Case %d: %d\n",kase++,dp[0][n-1]);
    }
    return 0;
}
