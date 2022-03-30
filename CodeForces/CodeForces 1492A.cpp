/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-03-28
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

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL p, a, b, c;
        scanf("%lld%lld%lld%lld", &p, &a, &b, &c);
        LL ta = (p / a + (p % a ? 1 : 0)) * a;
        LL tb = (p / b + (p % b ? 1 : 0)) * b;
        LL tc = (p / c + (p % c ? 1 : 0)) * c;
        LL ans = min(a, min(b, c));
        printf("%lld\n", min(ta - p, min(tb - p, tc - p)));
    }
    return 0;
}
