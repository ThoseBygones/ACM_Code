//解法一：划分
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int c[50005];   //车厢的数量
int sum[50005]; //将相邻的k个车厢组合后的乘客数量（相当于放进三个背包的物品）
int dp[50005][5];   //前i节车厢用j个火车头能拉的最多乘客数
int n,k;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&c[i]);
        scanf("%d",&k);
        memset(sum,0,sizeof(sum));
        for(int i=1; i<=n-k+1; i++)
        {
            for(int j=i; j<i+k; j++)
                sum[i]+=c[j];
        }
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n-k+1; i++)
        {
            for(int j=1; j<=3; j++)
            {
                int m=max(0,i-k);
                dp[i][j]=max(dp[i-1][j],dp[m][j-1]+sum[i]);
            }
        }
        printf("%d\n",dp[n-k+1][3]);
    }
    return 0;
}
*/

//解法二：累加
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int c[50005];   //车厢的数量
int dp[50005][5];   //前i节车厢用j个火车头能拉的最多乘客数
int n,k;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        c[0]=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&c[i]);
            c[i]+=c[i-1];
        }
        scanf("%d",&k);
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=3; j++)
            {
                int m=max(0,i-k);
                dp[i][j]=max(dp[i-1][j],dp[m][j-1]+c[i]-c[m]);
            }
        }
        printf("%d\n",dp[n][3]);
    }
    return 0;
}
