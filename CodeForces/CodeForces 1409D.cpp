/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-07
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

LL getSum(LL val)
{
    LL sum = 0;
    while(val)
    {
        sum += val % 10;
        val /= 10;
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL n, s;
        scanf("%lld%lld", &n, &s);
        LL ans = 0, base = 1;
        while(getSum(n) > s)
        {
            if(n % 10)
            {
                ans += (10 - n % 10) * base;
                n /= 10;
                n++;
                //printf("n: %lld, ans: %lld\n", n, ans);
                //printf("sum: %lld\n", getSum(n));
            }
            else
                n /= 10;
            base *= 10;
        }
        printf("%lld\n", ans);
        //}
    }
    return 0;
}
