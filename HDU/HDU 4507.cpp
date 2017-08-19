#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 20
#define LL long long
#define MOD 1000000007

struct Status
{
    LL cnt;    //符合条件的数的个数
    LL sum;    //符合条件数的和
    LL sqrsum; //符合条件数的平方和
    Status() {cnt=-1,sum=0,sqrsum=0;}
    Status(LL cnt,LL sum,LL sqrsum) : cnt(cnt),sum(sum),sqrsum(sqrsum) {}
} dp[MAXN][10][10]; //dp[i][j][k]表示当前第i位，当前位mod7余j，前i位每位和mod7余k。

int a[MAXN];
LL p[MAXN];

Status dfs(int pos, int s1, int s2, bool lim)
{
    if(pos == -1)
        return s1 && s2 ? Status(1,0,0) : Status(0,0,0);
    if(!lim && dp[pos][s1][s2].cnt != -1)
        return dp[pos][s1][s2];
    Status ret(0,0,0);
    int u = lim ? a[pos] : 9;
    for(int i = 0; i <= u; i++)
    {
        if(i == 7)
            continue;
        Status temp = dfs(pos-1, (s1+i)%7, (s2*10+i)%7, lim&&i==u);
        ret.cnt = (ret.cnt + temp.cnt) % MOD;
        ret.sum = (ret.sum + (temp.sum + (p[pos] * i) % MOD * temp.cnt % MOD) % MOD) % MOD;
        ret.sqrsum = (ret.sqrsum + ((temp.sqrsum + (2 * p[pos] * i) % MOD * temp.sum) % MOD + ((temp.cnt * p[pos]) % MOD * p[pos] % MOD * i % MOD * i % MOD))) % MOD;
    }
    return lim ? ret : dp[pos][s1][s2] = ret;
}

LL solve(LL val)
{
    int cnt=0;
    while(val)
    {
        a[cnt++]=val%10;
        val/=10;
    }
    Status ans=dfs(cnt-1,0,0,true);
    return ans.sqrsum;
}

int main()
{
    int t;
    scanf("%d",&t);
    p[0]=1;
    for(int i=1; i<20; i++)
        p[i]=(p[i-1]*10)%MOD;
    while(t--)
    {
        LL l,r;
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",((solve(r)-solve(l-1))%MOD+MOD)%MOD);    //注意可能为负数
    }
    return 0;
}
