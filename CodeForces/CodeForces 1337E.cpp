/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-29
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 区间dp
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
using namespace std;
template<class T> inline T sqr(T x)
{
    return x * x;
}
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 3005

const int MOD = 998244353;

char s[MAXN], t[MAXN];
int dp[MAXN][MAXN]; //dp[l][r]表示s串中[l, r]区间中的字符与t串中对应区间中字符匹配的方案数

int main()
{
    scanf("%s%s", s + 1, t + 1);
    int lens = strlen(s + 1);
    int lent = strlen(t + 1);
    for(int i = 1; i <= lens; i++)
    {
        if(i > lent || s[1] == t[i])
            dp[i][i] = 2;   //题目中已说明第一个字母放在左边和右边算两种方案
    }
    for(int k = 2; k <= lens; k++)  //枚举区间长度（即枚举s串的每个字符）
    {
        for(int l = 1; l + k - 1 <= lens; l++)  //枚举区间左端点
        {
            int r = l + k - 1;  //求出区间右端点
            if(l > lent || s[k] == t[l])    //把当前取出的s串字符s[k]放到区间[l+1, r]的左边（l位置处）
                dp[l][r] = (dp[l][r] + dp[l+1][r]) % MOD;
            if(r > lent || s[k] == t[r])    //把当前取出的s串字符s[k]放到区间[l, r-1]的右边（r位置处）
                dp[l][r] = (dp[l][r] + dp[l][r-1]) % MOD;
        }
    }
    int ans = 0;
    for(int i = lent; i <= lens; i++)
        ans = (ans + dp[1][i]) % MOD;
    printf("%d\n", ans);
    return 0;
}
