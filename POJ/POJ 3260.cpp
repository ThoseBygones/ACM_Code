/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-09
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 背包问题（dp）+ 鸽巢原理的应用（组合数学）
 ********************************************************************************
 *  Algo-Description:
 * > 付钱阶段：硬币的面值作为重量，硬币的个数 1 作为价值，则给定某个 T 作为背包容量W，问题转化为“物品价值总和最小”的多重背包问题。
 * > 找钱阶段：硬币数量不限，在与付钱阶段同样的表示下转化为完全背包问题。
 * > 难点在于背包容量 W 的确定，即最优方案金额的最大值（上界）。
 *   > 最优方案金额的最大值（上界）为 MAXT * MAXV * MAXV ；
 *   > 其中 MAXT 表示支付商品的最大总价值，MAXV 表示硬币面值的最大值。
 *   > 要凑足（大于等于）价格 T 的商品且硬币数最少，最多只能多给面值为 maxv * maxv 的硬币（maxv 为硬币的最大面值）。
 *   > 证明如下（反证法）：
 *     > 假设存在一种最优支付方案，给了总面值多于 t + maxv * maxv 的硬币，那么找回的零钱总面值就会多于 maxv * maxv ；
 *     > 这些硬币的个数将会大于 maxv ；设这些硬币的面值分别为 a[i]；
 *     > 根据鸽巢原理的应用，硬币序列中存在至少两个子序列，这两个子序列的和分别都能被 maxv 整除。
 *     > 如果直接用这些子序列中长度更小的那个子序列换算为面值为 maxv 的硬币某整数个，再去替换母序列，就能用更少的硬币买到同样价值的商品。
 *     > 与假设矛盾，证毕。
 *   > 关于上述鸽巢原理应用的证明，参见《组合数学》中的证明：
 *     > 应用：给定 m 个整数 a[1], a[2], ..., a[m]，存在整数 k 和 l，0 <= k < l <= m，
 *       使得 a[k + 1] + a[k + 2] + ... + a[l] 能够被 m 整除。
 *       通俗地说，就是在序列 a[1], a[2], ..., a[m] 中存在连续个 a[i]，这些 a[i] 的和能被 m 整除。
 *     > 证明：考虑 m 个和：
 *          a[1], a[1] + a[2], a[1] + a[2] + a[3], ..., a[1] + a[2] + a[3] + ... + a[m]
 *       > 若这些和当中的任意一个可以被 m 整除，那么结论成立。
 *       > 假设这些和中的每一个数除以 m 都有一个非零余数，余数等于 1, 2, ..., m - 1 。
 *         由于存在 m 个和而只有 m - 1 个余数，则必然有两个和数除以 m 有相同的余数。
 *         因此，存在整数 k 和 l，k < l，使得 a[1] + a[2] + ... + a[k] 与 a[1] + a[2] + ... + a[l] 有相同的余数 r ：
 *          a[1] + a[2] + ... + a[k] = b * m + r    ...(1)
 *          a[1] + a[2] + ... + a[l] = c * m + r    ...(2)
 *       > 将等式(1)与等式(2)相减，得到 a[k + 1] + ... + a[l] = (c - b) * m ，
 *       > 因此，a[k + 1] + a[k + 2] + ... + a[l] 能够被 m 整除。
 *       > 证毕。
 *   > 综上所述，存在子序列能够被 maxv 整除。
 ********************************************************************************
 */

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
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

const int MAXN = 105;
const int MAXT = 10005;
const int MAXV = 125;
const int MAXM = MAXT + MAXV * MAXV;

int v[MAXN], c[MAXN];
int dp_p[MAXM]; //支付过程的dp：dp_p[i]表示商店找钱金额为i时最少硬币数
int dp_c[MAXM]; //找零过程的dp：dp_c[i]表示顾客付钱金额为i时最少硬币数
int n, m;

void ZeroOnePack(int weight, int cost, int *dp) //01背包
{
    for(int i = m; i >= cost; i--)
        dp[i] = min(dp[i], dp[i - cost] + weight);
}

void CompletePack(int weight, int cost, int *dp)    //完全背包
{
    for(int i = cost; i <= m; i++)
        dp[i] = min(dp[i], dp[i - cost] + weight);
}

void MultiPack(int weight, int cost, int cnt, int *dp)
{
    if(cost * cnt >= m)   //转化为完全背包
        CompletePack(weight, cost, dp);
    else    //转化为01背包
    {
        int k = 1;
        while(k <= cnt) //二进制优化
        {
            ZeroOnePack(weight * k, cost * k, dp);
            cnt -= k;
            k *= 2;
        }
        for(int i = m; i >= cnt * cost; i--)
            dp[i] = min(dp[i], dp[i - cnt * cost] + cnt * weight);
    }
}

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    int maxv = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        maxv = max(maxv, v[i]);
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    fill(dp_p, dp_p + MAXM, INF);
    fill(dp_c, dp_c + MAXM, INF);
    dp_p[0] = dp_c[0] = 0;
    m = t + maxv * maxv;
    for(int i = 0; i < n; i++)  //支付过程是个多重背包问题
        MultiPack(1, v[i], c[i], dp_p);
    for(int i = 0; i < n; i++)  //找零过程是个完全背包问题
        CompletePack(1, v[i], dp_c);
    int ans = INF;
    for(int i = 0; i <= maxv * maxv; i++)
        ans = min(ans, dp_p[t + i] + dp_c[i]);
    if(ans != INF)
        printf("%d\n", ans);
    else
        puts("-1");
    return 0;
}
