#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 15

int a[MAXN];
int dp[MAXN][MAXN][3];  //dp[i][j][k]表示第i位余数为j，k表示状态：0--前一位不含有1；1--前一位含有1；2--含有13

int dfs(int pos,int mod,int s,bool lim)
{
    if(pos == -1)
        return mod == 0 && s == 2;
    if(!lim && ~dp[pos][mod][s])
        return dp[pos][mod][s];
    int u = lim ? a[pos] : 9;
    int ret = 0;
    for(int i=0; i<=u; i++)
    {
        int have = s;
        if(s == 0 && i == 1)    //之前没有13，而这一位是1
            have = 1;   //标记末尾是1
        else if(s == 1 && i == 3)   //前一位是1，这一位是3
            have = 2;   //标记末尾是3
        else if(s == 1 && i != 1)   //前一位是1，这一位却连1都不是
            have = 0;   //标记末尾什么都不是
        ret += dfs(pos-1, (mod*10+i)%13, have, lim&&i==u);
    }
    return lim ? ret : dp[pos][mod][s] = ret;
}

int solve(int val)
{
    int cnt=0;
    while(val)
    {
        a[cnt++]=val%10;
        val/=10;
    }
    return dfs(cnt-1,0,0,true);
}

int main()
{
    int n;
    memset(dp,-1,sizeof(dp));
    while(~scanf("%d",&n))
        printf("%d\n",solve(n));
    return 0;
}
