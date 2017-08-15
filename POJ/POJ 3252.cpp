#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 35

int a[MAXN];
int dp[MAXN][MAXN][MAXN];   //dp[i][j][k]为前i位，0的个数为j，1的个数为k

int dfs(int pos,int cnt0,int cnt1,int first,bool lim)   //first表示是否是最高位，因为二进制不允许前导零，所以如果前面位已经有1可以任意放，没有1则不能。
{
    if(pos == -1)
    {
        if(first || cnt0>=cnt1)
            return 1;
        return 0;
    }
    if(!lim && !first && ~dp[pos][cnt0][cnt1])
        return dp[pos][cnt0][cnt1];
    int ret = 0;
    int u = lim ? a[pos] : 1;
    for(int i = 0; i <= u; i++)
    {
        if(first)   //是最高位
        {
            if(i==0)
                ret += dfs(pos-1, 0, 0, 1, lim&&i==u);  //最高位还未放，继续往后观察
            else
                ret += dfs(pos-1, cnt0, cnt1+1, 0, lim&&i==u);  //最高位已放，则在这个位置放下1，
        }
        else    //不是最高位
        {
            if(i==0)
                ret += dfs(pos-1, cnt0+1, cnt1, 0, lim&&i==u);  //放0
            else
                ret += dfs(pos-1, cnt0, cnt1+1, 0, lim&&i==u);  //放1
        }
    }
    if(!lim && !first)
        dp[pos][cnt0][cnt1] = ret;
    return ret;
}

int solve(int val)
{
    int cnt=0;
    while(val)
    {
        a[cnt++]=val&1;
        val>>=1;
    }
    return dfs(cnt-1,0,0,1,true);
}

int main()
{
    int s,f;
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&s,&f);
    printf("%d\n",solve(f)-solve(s-1));
    return 0;
}
