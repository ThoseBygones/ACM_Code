/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-02-02
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

LL s[MAXN];
int n;
LL c;

bool check(LL w)
{
    LL sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += sqr(s[i] + 2 * w);
        if(sum > c)
            return false;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%lld", &n, &c);
        LL sum = 0, sqsum = 0;
        for(int i = 0; i < n; i++)
            scanf("%lld", &s[i]);
        LL l = 0, r = sqrt(c) + 1;
        //printf("%lld - %lld\n", l, r);
        LL ans = 0;
        while(l <= r)
        {
            LL mid = (l + r) >> 1;
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
