#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10

int x,y;
int a[MAXN];
int dp[MAXN][10000];    //f(a)最大不过是99999999的情况，假设是999999999也不过9*2^(10-1)*2<9300
//dp[i][j]表示i位数比j小的个数

int dfs(int pos, int s, bool lim)
{
    if(pos == -1)
        return s>=0;
    if(s < 0)   //如果剩下的值小于0则直接返回（不可能满足题目比f(a)小）
        return 0;
    if(!lim && ~dp[pos][s])
        return dp[pos][s];
    int ret = 0;
    int u = lim ? a[pos] : 9;
    for(int i = 0; i <= u; i++)
        ret += dfs(pos-1, s-i*(1<<pos), lim&&i==u); //注意本代码数位下标从0开始，故不是(1<<(pos-1))而是(1<<pos)
    return lim ? ret : dp[pos][s] = ret;
}

int f(int val)
{
    int ans=0;
    int cnt=1;
    while(val)
    {
        ans+=(val%10)*(1<<(cnt-1));
        cnt++;
        val/=10;
    }
    return ans;
}

int solve(int val)
{
    int cnt=0;
    while(val)
    {
        a[cnt++]=val%10;
        val/=10;
    }
    return dfs(cnt-1,f(x),true);
}

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        scanf("%d%d",&x,&y);
        printf("Case #%d: %d\n",kase++,solve(y));
    }
    return 0;
}
