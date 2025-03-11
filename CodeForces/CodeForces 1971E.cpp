/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-06
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

const int MAXN = 100005;

int a[MAXN], b[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k, q;
        scanf("%d%d%d", &n, &k, &q);
        for(int i = 1; i <= k; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= k; i++)
            scanf("%d", &b[i]);
        a[0] = b[0] = 0;
        vector<LL> ans;
        while(q--)
        {
            int x;
            scanf("%d", &x);
            int idx = upper_bound(a, a + 1 + k, x) - a - 1;
            //printf("pre D: %d\n", a[idx]);
            //printf("pre T: %d\n", b[idx]);
            //int ans = 0;
            if(a[idx] != n)
                ans.PB(1LL * b[idx] + 1LL * (x - a[idx]) * (b[idx + 1] - b[idx]) / (a[idx + 1] - a[idx]));
            else
                ans.PB(1LL * b[idx]);
        }
        for(int i = 0; i < ans.size(); i++)
            printf("%lld%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}
