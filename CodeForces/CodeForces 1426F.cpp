/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 200005;
const int MOD = 1000000007;

char s[MAXN];
LL dp[MAXN][3]; //dp[i][0/1/2]表示前i个字符组成的字符串包含多少个序列'a'/'ab'/'abc'

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    LL base = 1;    //当前有几种子串（初始化为3^0=1）
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 1][2];
        if(s[i] == 'a')
            dp[i][0] = (dp[i][0] + base) % MOD; //'a'串数量增加
        if(s[i] == 'b')
            dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD; //原'a'串变成'ab'串 + 原'ab'串
        if(s[i] == 'c')
            dp[i][2] = (dp[i][2] + dp[i - 1][1]) % MOD; //原'ab'串变成'abc'串 + 原'abc'串
        if(s[i] == '?')
        {
            dp[i][0] = (dp[i][0] * 3 + base) % MOD; //'?'为'a'时，新串包含dp[i][0] + base个'a'串；'?'为'b'/'c'时，新串包含dp[i][0]个'a'串
            dp[i][1] = (dp[i][1] * 3 + dp[i - 1][0]) % MOD; //'?'为'b'时，新串包含dp[i][1] + dp[i][0]（'a'变'ab'）个'ab'串，'?'为'a'/'c'时，新串包含dp[i][1]个'ab'串
            dp[i][2] = (dp[i][2] * 3 + dp[i - 1][1]) % MOD; //'?'为'c'时，新串包含dp[i][2] + dp[i][1]（'ab'变'abc'）个'abc'串，'?'为'a'/'b'时，新串包含dp[i][2]个'abc'串
            base = base * 3 % MOD;
        }
    }
    printf("%lld\n", dp[n][2]);
    return 0;
}
