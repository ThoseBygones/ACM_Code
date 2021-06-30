/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-30
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

const int MAXN = 5005;
const LL MOD = 1000000007;

LL a[MAXN];
LL c[MAXN]; //在所有的好路径中，点i被经过多少次
LL dp[MAXN][MAXN];  //dp[i][j]表示当前在点i，走j步以后的好路径总数（或走j步到达点i的好路径总数）

int main()
{
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++)
        dp[i][0] = 1;
    for(int j = 1; j <= k; j++)
    {
        for(int i = 1; i <= n; i++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i + 1][j - 1]) % MOD;
    }
    for(int i = 1; i <= n; i++) //枚举会经过的中间结点
    {
        for(int j = 0; j <= k; j++) //枚举其中一段走法的步长
            c[i] = (c[i] + dp[i][j] * dp[i][k - j] % MOD) % MOD;    //乘法原理
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++)
        ans = (ans + a[i] * c[i] % MOD) % MOD;
    while(q--)
    {
        int pos;
        LL x;
        scanf("%d%lld", &pos, &x);
        ans = (ans - a[pos] * c[pos] % MOD + MOD) % MOD;
        a[pos] = x;
        ans = (ans + a[pos] * c[pos] % MOD + MOD) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
