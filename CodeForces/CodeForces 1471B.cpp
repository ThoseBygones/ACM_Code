/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-28
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
        int n, x;
        scanf("%d%d", &n, &x);
        LL ans = 0;
        vector<PII> a;
        for(int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            a.PB(MP(val, val));
            ans += val;
        }
        int cnt = 0;
        while(cnt < n)
        {
            if(a[cnt].first % x == 0)
            {
                ans += a[cnt].second;
                a.PB(MP(a[cnt].first / x, a[cnt].second));
                n++;
                cnt++;
            }
            else
                break;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
