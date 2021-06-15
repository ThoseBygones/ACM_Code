/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-15
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 斐波那契数列 / dp + 费马小定理（快速幂 + 逆元）
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 200005;
const LL MOD = 998244353;

LL f[MAXN];

LL quickPow(LL x, LL k, LL mod)
{
    LL res = 1;
    while(k > 0)
    {
        if(k & 1)
            res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

//费马小定理求a关于b的逆元
LL Fermat(LL a, LL p)
{
    return quickPow(a, p - 2, p);
}

int main()
{
    int n;
    scanf("%d", &n);
    f[1] = f[2] = 1;
    for(int i = 3; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    LL ans = f[n] * Fermat(quickPow(2, n, MOD), MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}
