#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 35

int a[MAXN];
int dp[MAXN][MAXN]; //前i位数中有j位是1,（因为不管多少进制只有该位是1才能表示成题目要求的形式
int k,b;

int dfs(int pos, int s, bool lim)
{
    if(pos == -1)
        return s == k;  //1的数量达到k个则满足要求
    if(!lim && ~dp[pos][s])
        return dp[pos][s];
    int ret = 0;
    int u = lim ? a[pos] : b - 1;
    for(int i = 0; i <= u && i <= 1; i++) //first是否是最高位。有的题目条件不允许前导零，所以如果前面位已经有1可以任意放，没有1则不能。
        ret += dfs(pos-1, s+i, lim&&i==u);  //所有位只有为0或者为1才能把数字表示成题目要求的形式
    return lim ? ret : dp[pos][s] = ret;
}

int solve(int val)
{
    int cnt=0;
    while(val)
    {
        a[cnt++]=val%b;
        val/=b;
    }
    return dfs(cnt-1,0,true);
}

int main()
{
    int l,r;
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&l,&r);
    scanf("%d%d",&k,&b);
    printf("%d\n",solve(r)-solve(l-1));
    return 0;
}
