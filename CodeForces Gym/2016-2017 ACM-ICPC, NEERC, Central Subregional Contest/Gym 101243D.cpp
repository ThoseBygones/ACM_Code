#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define LL long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define MOD 1000000007

char s[MAXN];
int dp[MAXN];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%s",s+1);
    int len=strlen(s+1);
    //cout << len << endl;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1; i<=len; i++)
    {
        dp[i]=dp[i-1];
        if(i!=1 && (s[i-1]=='S' || s[i-1]=='N') && (s[i]=='W' || s[i]=='E'))
            dp[i]=dp[i-2]+dp[i];
        dp[i]=dp[i]%MOD;
        //cout << dp[i] << endl;
    }
    printf("%d\n",dp[len]);
    return 0;
}
