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
        LL a, b, x, y, n;
        scanf("%lld%lld%lld%lld%lld", &a, &b, &x, &y, &n);
        LL ans1, ans2;
        if(a - x > n)
            ans1 = (a - n) * b;
        else
            ans1 = max((b - n + a - x), y) * x;
        if(b - y > n)
            ans2 = (b - n) * a;
        else
            ans2 = max((a - n + b - y), x) * y;
        //cout << ans1 << " - " << ans2 << endl;
        printf("%lld\n", min(ans1, ans2));
    }
    return 0;
}
