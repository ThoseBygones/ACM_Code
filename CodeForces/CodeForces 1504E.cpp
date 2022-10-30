/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-10-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp / 最短路
 ********************************************************************************
 *  Algo-Description:
 * > 由于是环路，所以无所谓起点。
 * > 原式 max(c[i] , a[j] - a[i]) 可以变形为 max(0, a[j] - a[i] - c[i]) + c[i]。
 *   > 显然，当 a[j] >= a[i] 时从 i -> j 走的花费最小（为 c[i]）；
 *   > 为了尽可能减小花费，将 a[i] 从小到大排序，此时从大的点到小的点花费为 c[i]；
 *   > 也就是说，每个 c[i] 是必须要算进去答案的，最后的答案一定大于所有 c[i] 的和；
 * > 考虑到直接从 a[i] 值大的点往小的跑，最后再从最小的 a[1] 跑到 a[n] 形成环。
 * > 从 a[i] 值大的点往小的跑的花费固定，考虑求出“从最小的 a[1] 跑到 a[n] 形成环”这部分的最小花费：
 *   > 对于位置 i, j (i < j, a[i] < a[j])，如果 c[i] >= a[j] - a[i]，即 c[i] + a[i] >= a[j]，那么从 i 走到 j 的代价为 0；
 *   > 如果存在 a[i] + c[i] < a[j] < a[k]，此时需要额外花费。
 *     > 考虑 i -> k 还是 i -> j -> k：
 *       > i −> k 的代价为：a[k] - a[i] - c[i]；
 *       > i -> j -> k 的代价为：(a[j] - a[i] - c[i]) + (a[k] - a[j] - c[j]) = (a[k] - a[i] - c[i]) - c[j]。
 *     > 显然 i -> j -> k 的代价更小，因此最优策略为需要借助中间结点走则借助，即使需要很多个中间结点也不要紧。
 *   > 因此能免费走到的最大位置 j 可以用 max(a[i] + c[i]) 求出；但需要这个 max(a[i] + c[i]) 要保证 i < j （因为全局最大值不一定是最优解），
 *     > 如果该 a[i] + c[i] 是全局最大值，那么可以确定后续不会再出现 a[j] > a[i] + c[i]；
 *     > 否则一定会有 a[j] + c[j] > a[i] + c[i]，那就可以更新 max(a[j] + c[j]) 了。
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

struct City
{
    LL a, c;
    City() {}
    City(LL a, LL c) : a(a), c(c) {}
    bool operator < (const City &x) const
    {
        return a < x.a;
    }
} city[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    LL ans = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &city[i].a, &city[i].c);
        ans += city[i].c;
    }
    sort(city, city + n);
    LL tmp = city[0].a + city[0].c;
    for(int i = 1; i < n; i++)
    {
        ans += max(0LL, city[i].a - tmp);
        tmp = max(tmp, city[i].a + city[i].c);
    }
    printf("%lld\n", ans);
    return 0;
}
