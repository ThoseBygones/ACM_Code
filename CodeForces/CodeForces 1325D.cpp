/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-15
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
    LL u, v;
    scanf("%lld%lld", &u, &v);
    if(u > v || ((v - u) & 1))
    {
        puts("-1");
        return 0;
    }
    if(u == v)
    {
        if(v == 0)
            puts("0");
        else
        {
            puts("1");
            printf("%lld\n", u);
        }
        return 0;
    }
    LL a = (v - u) / 2, b = v - a;
    if((a ^ b) == u)
    {
        puts("2");
        printf("%lld %lld\n", a, b);
    }
    else
    {
        puts("3");
        printf("%lld %lld %lld\n", u, a, a);
    }
    return 0;
}
