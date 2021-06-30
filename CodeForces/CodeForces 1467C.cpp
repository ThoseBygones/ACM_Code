/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-30
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
    int n1, n2, n3;
    scanf("%d%d%d", &n1, &n2, &n3);
    LL sum1 = 0, sum2 = 0, sum3 = 0;
    LL min1 = LINF, min2 = LINF, min3 = LINF;
    for(int i = 1; i <= n1; i++)
    {
        LL a1;
        scanf("%lld", &a1);
        sum1 += a1;
        min1 = min(min1, a1);
    }
    for(int i = 1; i <= n2; i++)
    {
        LL a2;
        scanf("%lld", &a2);
        sum2 += a2;
        min2 = min(min2, a2);
    }
    for(int i = 1; i <= n3; i++)
    {
        LL a3;
        scanf("%lld", &a3);
        sum3 += a3;
        min3 = min(min3, a3);
    }
    LL ans = -LINF;
    ans = max(ans, sum1 + sum2 - sum3);
    ans = max(ans, sum1 + sum3 - sum2);
    ans = max(ans, sum2 + sum3 - sum1);
    LL sum = sum1 + sum2 + sum3;
    ans = max(ans, sum - (min1 + min2) * 2);
    ans = max(ans, sum - (min1 + min3) * 2);
    ans = max(ans, sum - (min2 + min3) * 2);
    printf("%lld\n", ans);
    return 0;
}
