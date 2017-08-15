//dp+离散化
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 2005

int a[MAXN];
int b[MAXN];    //a[i]的值范围太大，b[i]数组作为标杆数组来使a[i]调整后靠近b[i]
int dp[MAXN][MAXN]; //dp[i][j]表示前i个数构成的序列最大值为j时，所需要的最小花费

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    //正向排序，求非严格递增
    sort(b+1,b+n+1);
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        int Min=dp[i-1][1];
        for(int j=1; j<=n; j++)
        {
            Min=min(Min,dp[i-1][j]);
            dp[i][j]=Min+abs(b[j]-a[i]);
        }
    }
    int ans=*min_element(dp[n]+1,dp[n]+n+1);
    //逆向排序，求非严格递减
    sort(b+1,b+n+1,cmp);
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        int Min=dp[i-1][1];
        for(int j=1; j<=n; j++)
        {
            Min=min(Min,dp[i-1][j]);
            dp[i][j]=Min+abs(b[j]-a[i]);
        }
    }
    int res=*min_element(dp[n]+1,dp[n]+n+1);
    ans=min(ans,res);
    printf("%d\n",ans);
    return 0;
}
