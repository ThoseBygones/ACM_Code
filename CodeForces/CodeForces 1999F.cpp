/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 组合数学（Lucas定理求逆元）
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
const LL MOD = 1000000007;

/* Lucas定理求逆元 */

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

int main()
{
    initInv();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        int cnt = 0;    //1的数量
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            cnt += x;
        }
        //printf("cnt: %d\n", cnt);
        LL ans = 0;
        for(int i = k / 2 + 1; i <= k; i++) //枚举1的数量（1的数量大于0的数量即可有贡献）
        {
            //printf("-> %d %d %d %d\n", cnt, i, n - cnt, k - i);
            if(cnt >= i)  //1的数量够支撑该方案
            {
                if(n - cnt >= k - i)    //0的数量够支撑该方案
                    ans += C(cnt, i) * C(n - cnt, k - i) % MOD;//, printf("=> %lld\n", ans);
            }
            else
                break;
        }
        printf("%lld\n", (ans + MOD) % MOD);
    }
    return 0;
}
