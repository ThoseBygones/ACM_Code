/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-06
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 组合数学
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

const int MAXN = 300010;
const LL MOD = 998244353;

LL inv[MAXN];
LL fac[MAXN];

void initInv()
{
    inv[0] = fac[0] = inv[1] = fac[1] = 1;
    for(int i = 1; i < MAXN; i++)
    fac[i] = fac[i - 1] * i % MOD;
    for(int i = 2; i < MAXN; i++)
    inv[i] = (MOD - (MOD / i)) * inv[MOD % i] % MOD;    //Lucas定理
    for(int i = 1; i < MAXN; i++)
    inv[i] = inv[i - 1] * inv[i] % MOD;
}

LL C(int n, int m)  //求组合数C(n,m)
{
    if(n < m || m < 0)  //过滤不合法的输入
        return 0;
    return (fac[n] * inv[m] % MOD) * inv[n - m] % MOD;
}

LL a[MAXN << 1];

int main()
{
    initInv();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + 2 * n);
    LL sum = 0;
    for(int i = 1; i <= n; i++)
        sum = (sum + a[i + n] - a[i]) % MOD;
    printf("%lld\n", sum * C(2 * n, n) % MOD);
    return 0;
}
