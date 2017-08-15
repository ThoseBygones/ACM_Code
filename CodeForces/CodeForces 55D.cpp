#include <bits/stdc++.h>
using namespace std;

#define MAXN 20
#define MAXMOD 2520 //1~9的LCM，即5*7*8*9=2520
#define LL long long

int a[MAXN];
int Hash[MAXMOD+5];   //最小公倍数的48种情况
LL dp[MAXN][MAXMOD+5][50];    //dp[i][j][k]表示前i位数字对2520取余后值为j，所有数的最小公倍数是Hash[k]的状态
//一个数字要被它的所有非零位整除，即被他们的LCM整除，可以存已有数字的Mask，但更好的方法是存它们的LCM{digit[i]}
//另外，10以内数字的情况为5,7,8(=2^3),9(=3^2)。最小公倍数组合只有(1+1)*(1+1)*(3+1)*(2+1)=48种（1为不选该种情况）

void getLcm()
{
    int cnt=0;
    for(int i=1; i<=MAXMOD; i++)
    {
        if(MAXMOD%i==0)
            Hash[i]=cnt++;
    }
}

LL dfs(int pos, int num, int lcm, bool lim)
{
    if(pos == -1)
        return num % lcm == 0;
    if(!lim && ~dp[pos][num][Hash[lcm]])
        return dp[pos][num][Hash[lcm]];
    LL ret = 0;
    int u = lim ? a[pos] : 9;
    for(int i = 0; i <= u; i++) //first是否是最高位。有的题目条件不允许前导零，所以如果前面位已经有1可以任意放，没有1则不能。
        ret += dfs(pos-1, (num*10+i)%MAXMOD, i?(lcm*i/__gcd(lcm,i)):lcm, lim&&i==u);
    return lim ? ret : dp[pos][num][Hash[lcm]] = ret;
}

LL solve(LL val)
{
    int cnt=0;
    while(val)
    {
        a[cnt++]=val%10;
        val/=10;
    }
    return dfs(cnt-1,0,1,true);
}

int main()
{
    int t;
    scanf("%d",&t);
    getLcm();
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        LL l,r;
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",solve(r)-solve(l-1));
    }
    return 0;
}
