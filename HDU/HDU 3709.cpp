#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 20
#define LL long long

int a[MAXN];
LL dp[MAXN][MAXN][2000];   //dp[i][j][k]表示当前为第i位，枢轴（支点）在第j为，力矩为k的状态

LL dfs(int pos,int pivot,int sum,bool lim)
{
    if(pos == -1)
        return sum == 0 ? 1 : 0;
    if(sum < 0) //力矩已经小于零，结束
        return 0;
    if(!lim && ~dp[pos][pivot][sum])
        return dp[pos][pivot][sum];
    int u = lim ? a[pos] : 9;
    LL ret = 0;
    for(int i = 0; i <= u; i++)
        ret += dfs(pos-1, pivot, sum+(pos-pivot)*i, lim&&i==u);
    return lim ? ret : dp[pos][pivot][sum] = ret;
}

LL solve(LL val)
{
    int cnt=0;
    while(val)
    {
        a[cnt++]=val%10;
        val/=10;
    }
    LL ans=0;
    for(int i=0; i<cnt; i++)    //枚举枢轴（支点）位置
        ans+=dfs(cnt-1,i,0,true);
    return ans-(cnt-1); //0,00,000,0000,...都符合要求，但是计算的时候全零状态算一个，数位dp的dfs中计算重复了，所以把重复的排除
}

int main()
{
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        LL x,y;
        scanf("%I64d%I64d",&x,&y);
        printf("%I64d\n",solve(y)-solve(x-1));
    }
    return 0;
}
