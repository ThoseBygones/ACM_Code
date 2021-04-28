/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 组合数
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

const int MOD = 1000000007;
const int MAXN = 1005;

LL inv[MAXN];
LL res[MAXN];
LL fac[MAXN];

void initInv()  //线性预处理逆元
{
    inv[1] = 1;
    fac[1] = 1;
    res[1] = 1;
    for(int i = 2; i<MAXN; i++)
    {
        inv[i] = 1LL * MOD / i * (MOD - inv[MOD % i]) % MOD;
        res[i] = (inv[i] * res[i - 1]) % MOD;
        fac[i] = 1LL * (fac[i - 1] * i) % MOD;
    }
}

LL C(int n, int m)  //求组合数C(n,m)
{
    if (m == 0 || m == n)
        return 1;
    return fac[n] * res[n - m] % MOD * res[m] % MOD;
}

int cnt[MAXN];

int main()
{
    initInv();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 0; i <= n; i++)
            cnt[i] = 0;
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            cnt[x]++;
        }
        int ans = 0, tmp = 0;
        for(int i = n; i >= 1; i--)
        {
            if(ans + cnt[i] >= k)
            {
                tmp = cnt[i];
                break;
            }
            else
                ans += cnt[i];
        }
        //cout << tmp << " " << k - ans << endl;
        printf("%lld\n", C(tmp, k - ans));
    }
    return 0;
}
