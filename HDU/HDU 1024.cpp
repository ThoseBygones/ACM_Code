#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1000005
#define INF 0x3f3f3f3f

int a[MAXN];
int dp[MAXN];   //dp[j]表示第j个元素在第i组里面的最优值
int pre[MAXN];  //pre[j]表示第j个元素在上一组（第i-1组）里面的最优值

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=m; i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        int Max;
        for(int i=1; i<=n; i++) //枚举子序列
        {
            Max=-INF;
            for(int j=i; j<=m; j++) //每组子序列里至少要有一个元素
            {
                dp[j]=max(dp[j-1],pre[j-1])+a[j];
                pre[j-1]=Max;
                Max=max(dp[j],Max);
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}
