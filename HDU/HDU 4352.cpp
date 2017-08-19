#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 20
#define LL long long

int k;
int a[MAXN];
LL dp[MAXN][1<<10][10];    //dp[i][j][k]表示当前第i位数字状态为j，LIS长度为k的状态。
//j为状态压缩的表示。0~9十位数字出现的状况，出现记1未出现记0。LIS求解方法利用的是O(nlogn)的解法

int getNewS(int num, int s) //状态转移，得到新的状态
{
    for(int i=num; i<=9; i++)
    {
        if(s&(1<<i))    //LIS中有比这个数字大的，则更新：去掉这个旧的，留下新的比较小的
            return (s^(1<<i))|(1<<num);
    }
    return s|(1<<num);  //否则直接在末尾加上这个新的数字
}

int check(int s)    //计算1的个数
{
    int cnt=0;
    while(s)
    {
        if(s&1)
            cnt++;
        s>>=1;
    }
    return cnt;
}

LL dfs(int pos, int s, bool zero, bool lim)   //zero为前面是否都为零
{
    if(pos == -1)
        return check(s) == k;
    if(!lim && ~dp[pos][s][k])
        return dp[pos][s][k];
    LL ret = 0;
    int u = lim ? a[pos] : 9;
    for(int i = 0; i <= u; i++)
        ret += dfs(pos-1, zero&&(i==0)?0:getNewS(i,s), zero&&(i==0), lim&&i==u);
    return lim ? ret : dp[pos][s][k] = ret;
}

LL solve(LL val)
{
    int cnt=0;
    while(val)
    {
        a[cnt++]=val%10;
        val/=10;
    }
    return dfs(cnt-1,0,true,true);
}

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        LL l,r;
        scanf("%I64d%I64d%d",&l,&r,&k);
        printf("Case #%d: %I64d\n",kase++,solve(r)-solve(l-1));
    }
    return 0;
}
