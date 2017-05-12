#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

int v[MAXN],w[MAXN];    //每块骨头的价值和重量
int dp[MAXN];
int n,m;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        //memset(dp,0,sizeof(dp));
        for(int i=0; i<=m; i++)
            dp[i]=0;
        for(int i=1; i<=n; i++)
            scanf("%d",&v[i]);
        for(int i=1; i<=n; i++)
            scanf("%d",&w[i]);
        for(int i=1; i<=n; i++)
        {
            for(int j=m; j>=w[i]; j--)
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
