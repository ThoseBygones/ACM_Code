#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10

int a[MAXN];
int dp[MAXN][3];    //dp[i][0/1]表示当前第i位，前一位值是否为6的状态

int dfs(int pos,int s,bool lim)
{
    if(pos == -1)
        return 1;
    if(!lim && ~dp[pos][s])
        return dp[pos][s];
    int u = lim ? a[pos] : 9;
    int ret = 0;
    for(int i = 0; i <= u; i++)
    {
        if(i == 4)
            continue;
        if(s && (i == 2))
            continue;
        ret += dfs(pos-1, i==6, lim&(i==u));
    }
    return lim ? ret : dp[pos][s] = ret;
}

int getDigit(int val)
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
    int n,m;
    memset(dp,-1,sizeof(dp));
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        printf("%d\n",getDigit(m)-getDigit(n-1));
    }
    return 0;
}
