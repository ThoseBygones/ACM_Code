#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1000005
#define MOD 1000000000

int dp[MAXN];

int main()
{
    dp[1]=1;
    int n;
    scanf("%d",&n);
    for(int i=2; i<=n; i++)
    {
        if(i%2)
            dp[i]=dp[i-1];
        else
        {
            dp[i]=dp[i-1]+dp[i/2];
            dp[i]%=MOD;
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
