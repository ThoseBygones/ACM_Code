/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-14
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 数学
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

const int MAXN = 100005;

double x[MAXN], y[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int cntx = 0, cnty = 0;
        for(int i = 0; i < 2 * n; i++)
        {
            int tx, ty;
            scanf("%d%d", &tx, &ty);
            if(!tx)
                y[cnty++] = abs(ty);
            if(!ty)
                x[cntx++] = abs(tx);
        }
        sort(x, x + cntx);
        sort(y, y + cnty);
        double ans = 0.0;
        for(int i = 0; i < n; i++)
            ans += sqrt(sqr(x[i]) + sqr(y[i]));
        printf("%.15f\n", ans);
    }
    return 0;
}
