#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

int p[MAXN],h[MAXN],c[MAXN];
int dp[MAXN];
int n,m;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
            scanf("%d%d%d",p+i,h+i,c+i);
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=c[i]; j++)
            {
                for(int k=n; k>=p[i]; k--)
                    dp[k]=max(dp[k],dp[k-p[i]]+h[i]);
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
