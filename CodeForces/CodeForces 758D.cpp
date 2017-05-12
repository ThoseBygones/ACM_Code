#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 65
#define INF (LL)1e18

char num[MAXN];
LL dp[MAXN];    //前i个数字划分好以后能组成的最小值

int main()
{
    LL n;
    scanf("%I64d",&n);
    scanf("%s",num+1);
    int len=strlen(num+1);
    for(int i=0; i<=len; i++)
        dp[i]=INF;
    dp[0]=0;
    for(int i=1; i<=len; i++)
    {
        LL temp=0;
        for(int j=i; j<=len; j++)
        {
            temp=temp*10+(num[j]-'0');
            if(temp>=n) //组成的数要合法
                break;
            if(num[i]=='0' && j>i)  //不能有前导零
                break;
            if(dp[i-1]*n+temp>INF || dp[i-1]*n+temp<0)  //不能超过1e18
                continue;
            dp[j]=min(dp[j],dp[i-1]*n+temp);
            //cout << dp[j] << endl;
        }
    }
    printf("%I64d\n",dp[len]);
    return 0;
}
