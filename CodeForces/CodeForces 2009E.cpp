/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-04-22
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 二分/三分
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

/* 二分法 */
LL calc(LL val, LL n, LL k)
{
    LL sum = val * k + (val - 1) * val / 2 - (n - val) * k - (n - val) * (val + n - 1) / 2;
    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL n, k;
        scanf("%lld%lld", &n, &k);
        LL l = 1, r = n;
        LL ans = LINF;
        while(l <= r)
        {
            LL mid = (l + r) >> 1;
            if(calc(mid, n, k) <= 0)    //二分零点位置
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        printf("%lld\n", min(abs(calc(ans, n, k)), abs(calc(ans + 1, n, k))));
    }
    return 0;
}


/* 三分法 */
LL calc(LL val, LL n, LL k)
{
    LL sum = val * k + (val - 1) * val / 2 - (n - val) * k - (n - val) * (val + n - 1) / 2;
    return abs(sum);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL n, k;
        scanf("%lld%lld", &n, &k);
        LL l = 1, r = n;
        while(l <= r)
        {
            LL lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
            if(calc(lmid, n, k) <= calc(rmid, n, k))    //三分最低点（零点）位置
                r = rmid - 1;
            else
                l = lmid + 1;
        }
        printf("%lld\n", min(calc(l, n, k), calc(r, n, k)));
    }
    return 0;
}
