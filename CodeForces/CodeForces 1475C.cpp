/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 容斥原理
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

const int MAXN = 200005;

map<PII, int> mpab;
int cnta[MAXN], cntb[MAXN];
int a[MAXN], b[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i <= n; i++)
            cnta[i] = 0;
        for(int i = 0; i <= m; i++)
            cntb[i] = 0;
        mpab.clear();
        for(int i = 1; i <= k; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= k; i++)
            scanf("%d", &b[i]);
        LL ans = 0;
        for(int i = 1; i <= k; i++)
        {
            //前i-1对的组合减去冲突的组合数量
            ans += 1LL * (i - 1) - (cnta[a[i]] + cntb[b[i]] - mpab[MP(a[i], b[i])]);    //计算冲突组合数量利用容斥原理
            cnta[a[i]]++, cntb[b[i]]++;
            mpab[MP(a[i], b[i])]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
