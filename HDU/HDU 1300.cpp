#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int a[MAXN];
int p[MAXN];
int dp[MAXN];   //买全第i种珍珠需要花的最少钱数

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d%d",&a[i],&p[i]);
        for(int i=1; i<=MAXN; i++)
            dp[i]=INF;
        dp[0]=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<i; j++)
            {
                int sum=0;
                for(int k=j+1; k<=i; k++)
                    sum+=a[k];
                dp[i]=min(dp[i],dp[j]+(sum+10)*p[i]);
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
