#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 505
#define MAXM 10005

int p[MAXN],w[MAXN];
int dp[MAXM];
int n,e,f;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&e,&f);
        int weight=f-e;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d%d",p+i,w+i);
        for(int i=1; i<=weight; i++)
            dp[i]=INF;
        dp[0]=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=w[i]; j<=weight; j++)
                dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
        }
        if(dp[weight]==INF)
            puts("This is impossible.");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[weight]);
    }
    return 0;
}
