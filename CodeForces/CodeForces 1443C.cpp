/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-07
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 前缀和
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

PLL t[MAXN];
LL sum[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &t[i].first);   //外送时间
        for(int i = 1; i <= n; i++)
            scanf("%lld", &t[i].second);   //走路时间
        sort(t + 1, t + 1 + n);
        for(int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + t[i].second;
        LL ans = sum[n];
        for(int i = n; i; i--)
            ans = min(ans, max(sum[n] - sum[i], t[i].first));
        printf("%lld\n", ans);
    }
    return 0;
}
