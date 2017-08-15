#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 25
#define LL long long

int a[MAXN];
LL dp[MAXN][60000];    //0~9每个数有三个状态：0--没有；1--奇数个；2--偶数个。共3^10<60000
//表示当前处理第i位，数字j(0~9)的状态

int check(int s)    //计算是否符合平衡数的要求，即奇数有偶数个，偶数有奇数个
{
    for(int i=0; i<=9; i++)
    {
        if((i&1)==1 && s%3==1)  //奇数有奇数个
            return 0;
        if((i&1)==0 && s%3==2)  //偶数有偶数个
            return 0;
        s/=3;
    }
    return 1;
}

int newState(int i,int s)
{
    int temp=s;
    int j=i;
    while(j--)
        temp/=3;
    int x=temp%3;
    if(x==0) //该数字之前没有
        s+=(int)pow(3,i);  //现在变为1个（状态0->1）
    else if(x==1)    //该数字之前有奇数个
        s+=(int)pow(3,i);  //现在变为偶数个（状态1->2）
    else    //该数字之前有偶数个
        s-=(int)pow(3,i);  //现在变为奇数个（状态2->1）
    //注意，pow(3,i)前面不加int会有精度问题
    return s;
}

LL dfs(int pos, int s, bool lim)
{
    if(pos == -1)
        return check(s);
    if(!lim && ~dp[pos][s])
        return dp[pos][s];
    LL ret = 0;
    int u = lim ? a[pos] : 9;
    for(int i = 0; i <= u; i++) //first是否是最高位。有的题目条件不允许前导零，所以如果前面位已经有1可以任意放，没有1则不能。
        ret += dfs(pos-1, i==0&&s==0?0:newState(i,s), lim&&i==u);
    return lim ? ret : dp[pos][s] = ret;
}

LL solve(LL val)
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
        LL l,r;
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",solve(r)-solve(l-1));
    }
    return 0;
}


//打三进制表法
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int num[22];
ll f[22][60000];
int T;
int news[60000][10];
int exp[10];
bool ok[60000];
ll l, r;

ll dfs(int i, int s, bool e)
{
    if (i==-1) return ok[s];
    if (!e && ~f[i][s]) return f[i][s];
    ll res = 0;
    int u = e?num[i]:9;
    for (int d = s?0:1; d <= u; ++d)
        res += dfs(i-1, news[s][d], e&&d==u);
    return e?res:f[i][s]=res;
}

int getnum(ll x, int num[])
{
    int len = 0;
    for (; x; x/=10)
        num[len++] = x%10;
    return len;
}

ll solve(ll x)
{
    int len = getnum(x, num);
    ll res = 0;
    for (int i = 1; i < len; ++i)
        res += dfs(i-1, 0, 0);
    return res+=dfs(len-1, 0, 1);
}

bool judge(int exp[])
{
    for (int i = 0; i < 10; ++i)
    {
        if (!exp[i]) continue;
        if (i&1)
        {
            if (exp[i]&1) return 0;
        }
        else
        {
            if (~exp[i]&1) return 0;
        }
    }
    return 1;
}

int main()
{
    int i, j, k;
    memset(f, -1, sizeof f);
    for (int s = 0; s < 59049; ++s)
    {
        j = s;
        for (i = 0; i < 10; ++i, j/=3)
            exp[i] = j%3;
        if (s) ok[s] = judge(exp);
        else ok[s] = 0;
        for (i = 0; i < 10; ++i)
        {
            int t = exp[i];
            if (exp[i]&1) exp[i] = 2;
            else exp[i] = 1;
            for (j = 9; j >= 0; --j, news[s][i]*=3)
                news[s][i] += exp[j];
            news[s][i] /= 3;
            exp[i] = t;
        }
    }
    //printf("#%d\n", news[0][3]);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", solve(r)-solve(l-1));
    }
    return 0;
}
