/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-28
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x7fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 100005

LL r[MAXN], g[MAXN], b[MAXN];
LL ans;

LL cal(LL a[], int cnta, LL b[], int cntb, LL c[], int cntc)
{
    for(int i = 0; i < cnta; i++)   //枚举a数组中的元素
    {
        int posx = lower_bound(b, b + cntb, a[i]) - b;  //找到b数组中第一个大于等于a[i]的值的位置
        int posy = upper_bound(c, c + cntc, a[i]) - c - 1;  //找到c数组中最后一个小于等于a[i]的值的位置
        if(posx != cntb && posy != -1) //能找到这样的值
            ans = min(ans, sqr(a[i] - b[posx]) + sqr(a[i] - c[posy]) + sqr(b[posx] - c[posy]));
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int nr, ng, nb;
        scanf("%d%d%d", &nr, &ng, &nb);
        for(int i = 0; i < nr; i++)
            scanf("%d", &r[i]);
        for(int i = 0; i < ng; i++)
            scanf("%d", &g[i]);
        for(int i = 0; i < nb; i++)
            scanf("%d", &b[i]);
        sort(r, r + nr);
        sort(g, g + ng);
        sort(b, b + nb);
        ans = LINF;
        cal(r, nr, g, ng, b, nb);
        cal(r, nr, b, nb, g, ng);
        cal(g, ng, r, nr, b, nb);
        cal(g, ng, b, nb, r, nr);
        cal(b, nb, r, nr, g, ng);
        cal(b, nb, g, ng, r, nr);
        printf("%lld\n", ans);
    }
    return 0;
}
