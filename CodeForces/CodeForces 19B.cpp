#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

#define MAXN 2005
#define INF 1e18

LL c[MAXN];    //每件物品的价格
LL t[MAXN];    //售货员折腾每件物品的时间
LL dp[MAXN];    //对于第i件物品，已经购买了j件物品所需要的最小价值
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%I64d%I64d",&t[i],&c[i]);
    for(int i=0; i<=n; i++)
        dp[i]=INF;
    dp[0]=0LL;
    for(int i=1; i<=n; i++)
    {
        for(int j=n; j>=1; j--)
        {
            if(j<t[i]+1)
                dp[j]=min(dp[j],c[i]);
            else
                dp[j]=min(dp[j],dp[j-1-t[i]]+c[i]);
        }
    }
    printf("%I64d\n",dp[n]);
    return 0;
}
