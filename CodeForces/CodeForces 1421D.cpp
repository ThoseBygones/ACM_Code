/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-01
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

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL x, y;
        LL c1, c2, c3, c4, c5, c6;
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &x, &y, &c1, &c2, &c3, &c4, &c5, &c6);
        c1 = min(c1, c6 + c2);
        c2 = min(c2, c1 + c3);
        c3 = min(c3, c2 + c4);
        c4 = min(c4, c3 + c5);
        c5 = min(c5, c4 + c6);
        c6 = min(c6, c5 + c1);
        if(x >= 0)
        {
            if(y >= x)
                printf("%lld\n", c1 * x + c2 * (y - x));
            else if(y >= 0)
                printf("%lld\n", c1 * y + c6 * (x - y));
            else
                printf("%lld\n", c6 * x + c5 * abs(y));
        }
        else
        {
            if(y <= x)
                printf("%lld\n", c4 * abs(x) + c5 * (x - y));
            else if(y <= 0)
                printf("%lld\n", c4 * abs(y) + c3 * (y - x));
            else
                printf("%lld\n", c2 * y + c3 * abs(x));
        }
    }
    return 0;
}
