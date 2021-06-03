/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm:
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

const int MAXN = 1005;
const int MOD = 1000000007;

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
    if(n < m || m < 0)
        return 0;
    return (fac[n] * inv[m] % MOD) * inv[n - m] % MOD;
}

int flag[MAXN];

void biSearch(int pos, int n)
{
    int l = 0, r = n;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(mid > pos)
        {
            flag[mid] = 1;  //向右查找
            r = mid;
        }
        else
        {
            if(mid != pos)
                flag[mid] = -1;
            l = mid + 1;
        }
    }
}

int main()
{
    initInv();
    int n, x, pos;
    scanf("%d%d%d", &n, &x, &pos);
    biSearch(pos, n);
    int cntl = 0, cntr = 0;
    for(int i = 0; i < n; i++)
    {
        if(flag[i] == -1)   //必须填比x小的数的位置计数
            cntl++;
        else if(flag[i] == 1)   //必须填比x大的数的位置计数
            cntr++;
    }
    LL ans = C(x - 1, cntl) * fac[cntl] % MOD * C(n - x, cntr) % MOD * fac[cntr] % MOD * fac[n - cntl - cntr - 1] % MOD;
    printf("%lld\n", ans);
    return 0;
}
