#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;

LL dp[35000];
int main()
{
    int money;
    while(~scanf("%d",&money))
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1; i<=3; i++)
        {
            for(int j=i; j<=32768; j++)
                dp[j]+=dp[j-i];
        }
        printf("%lld\n",dp[money]);
    }
    return 0;
}
