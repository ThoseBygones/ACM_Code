#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 3500
#define MAXM 13000

int w[MAXN],d[MAXN];    //小装饰品的重量和吸引力指数
int dp[MAXM];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            scanf("%d%d",&w[i],&d[i]);
        for(int i=1; i<=n; i++)
        {
            for(int j=m; j>=w[i]; j--)
                dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
