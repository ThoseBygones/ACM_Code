/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-09
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 前缀和（后缀和）
 ********************************************************************************
 *  Algo-Description:
 * > 将物品权值从大到小排序，贪心的能选则选即可。
 * > 正确性证明：
 *   > 重量大于 W 的肯定无法选。
 *   > 大到小排序是为了保证如果存在 a[i] >= ceil(W / 2) 的单个物品，则一定会先被选中，以保证算法正确性。
 *   > 不这样排序可能会导致：
 *     > 虽然可能存在 a[i] >= ceil(W / 2)
 *     > 但 Sum(a[1...(i-1)]) <= ceil(W / 2)
 *     > 且 Sum(a[1...i]) > W
 *     > 此时按照这种方式解决是无解的，但实际上只选择单个物品 a[i] 是有解的。
 *     > 如果不存在这样的单个物品，那么每个物品的价值都 <= ceil(W / 2)
 *   > 只要当前已选定物品的总和 sum 不在范围 [ceil(W / 2), W] 中时，添加一个新的物品一定不会使 sum > W ；
 *   > 故贪心的添加即可。
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

PLI p[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        LL w;
        scanf("%d%lld", &n, &w);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &p[i].first);
            p[i].second = i;
        }
        sort(p + 1, p + 1 + n, greater<PLI>());
        LL sum = 0;
        vector<int> ans;
        bool flag = false;
        for(int i = 1; i <= n; i++)
        {
            if(p[i].first > w)
                continue;
            ans.PB(p[i].second);
            sum += p[i].first;
            if(sum >= (w + 1) / 2 && sum <= w)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            printf("%d\n", ans.size());
            for(int i = 0; i < ans.size(); i++)
                printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));
        }
        else
            puts("-1");
    }
    return 0;
}
