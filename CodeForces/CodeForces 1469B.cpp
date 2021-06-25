/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-25
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
        int n, m;
        scanf("%d", &n);
        int ans1 = 0, ans2 = 0, sum = 0;
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            sum += x;
            ans1 = max(ans1, sum);
        }
        scanf("%d", &m);
        sum = 0;
        for(int i = 1; i <= m; i++)
        {
            int x;
            scanf("%d", &x);
            sum += x;
            ans2 = max(ans2, sum);
        }
        int ans = max(max(ans1, ans2), ans1 + ans2);
        printf("%d\n", ans);
    }
    return 0;
}
