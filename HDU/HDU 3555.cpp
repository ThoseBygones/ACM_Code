#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 20
#define LL long long

int a[MAXN];
LL dp[MAXN][2];    //dp[i][0/1]表示当前第i位，前一位是否为4的状态

LL dfs(int pos,int s,bool lim)
{
    if(pos == -1)
        return 1;
    if(!lim && ~dp[pos][s])
        return dp[pos][s];
    LL ret = 0;
    int u = lim ? a[pos] : 9;
    for(int i = 0; i <= u; i++)
    {
        if(s && i==9)
            continue;
        ret += dfs(pos-1, i==4, lim&(i==u));
    }
    return lim ? ret : dp[pos][s] = ret;
}

LL getDigit(LL val)
{
    int cnt=0;
    while(val)
    {
        a[cnt++]=val%10;
        val/=10;
    }
    return dfs(cnt-1,0,true);
}

int main()
{
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        LL n;
        scanf("%I64d",&n);
        printf("%I64d\n",n-(getDigit(n)-getDigit(0))); //统计的是有多少个含有“49”的数
    }
    return 0;
}
