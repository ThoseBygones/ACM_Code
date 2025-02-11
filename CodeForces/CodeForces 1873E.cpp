/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:2025-02-09
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 二分
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

LL a[MAXN];
int n, x;

bool check(LL val)
{
    LL sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += max(val - a[i], 0LL);
        if(sum > x)
            return false;
    }
    //printf("== %d\n", sum);
    return sum <= x ? true : false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &x);
        LL m = 1000000000;
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            m = min(a[i], m);
        }
        LL l = 1, r = m + 1000000000;
        LL ans = 0;
        while(l <= r)
        {
            LL mid = l + r >> 1;
            if(check(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
