#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005

int c[5]={150,200,350};
int dp[MAXN];
int n;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(int i=0; i<=2; i++)
        {
            for(int j=c[i]; j<=n; j++)
                dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
        }
        /*int Max=0;
        for(int i=0; i<=n; i++)
            Max=max(Max,dp[i]);
        int ans=n-Max;
        */
        int ans=n-dp[n];
        printf("%d\n",ans);
    }
    return 0;
}
