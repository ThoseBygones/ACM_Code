/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-04-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 滑动窗口 + STL map + STL multiset
 ********************************************************************************
 *  Algo-Description:
 * > 若 a[i] - i = a[j] − j，则 a[j] - a[i] = j - i，此时下标的距离即为这两个值的差值，
 * > 则可以同时不修改 a[i] 和 a[j]​，使得 a[i], a[j] 存在在同一个连续子数组里面，因此可以构造一个新数组 b[i] = a[i] - i。
 * > 如果 b[i] = b[j]，​则，a[i] 和 a[j]​ 可以存在于同一个连续子数组里面，
 * > 那么如果数组 b 在 [l, r] 中同一个元素的最多出现次数为 x，那么把 [l, r] 修改为连续子数组的最少次数，即为 r - l + 1 - x。
 * > 因为每次查询都是查询长度为 k 的区间修改为连续子数组的最少次数，所以可以处理出数组 a 中所有长度为 k 的区间修改为连续子数组的最少次数。
 * > 具体的做法：
 *   > 从左到右对数组 b 进行遍历，然后记录下 b[i] 的出现次数，维护每个长度为 k 的窗口中元素的最大出现次数。
 *   > 用 multiset 记录所有元素出现次数的数值集合，然后用 map 记录某个元素在当前窗口的出现次数。
 *   > 当遍历到第 i 个窗口时，新添加了 b[i]​ 进入窗口，map 中 b[i]​ 的出现次数 +1，同时 multiset 中删去 b[i]​ 原先的出现次数，加入更新后的次数（原次数 - 1）。
 *   > multiset 的 .rbegin() 方法得到最大的出现次数 x，k − x 即为把 [i, i + k − 1] 修改成连续子数组的最小操作次数。
 *   > 接着，移动到第 i + 1 个窗口，删去窗口最左端元素 b[i − k + 1]​，map 中对应的该元素出现次数 -1，multiset 中也是对应的删旧增新。
 * > 这样就处理出了每个长度为 k 的区间修改为连续子数组的最小操作次数，ans 数组记录在对应右端点的位置，每次离线查询即可。
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

int b[MAXN], ans[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k, q;
        scanf("%d%d%d", &n, &k, &q);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
            b[i] -= i;
        }
        map<int, int> cnt;
        multiset<int> ms;
        for(int i = 1; i <= n; i++)
        {
            int curcnt = cnt[b[i]]++;   //当前枚举到的元素在当前滑动窗口范围内的数量
            auto it = ms.find(curcnt);
            if(it != ms.end())
                ms.erase(it);
            ms.insert(curcnt + 1);  //更新数量
            if(i >= k)  //滑动窗口开始移动
            {
                ans[i] = k - *ms.rbegin();  //记录当前滑动窗口内相同元素数量的最大值，计算需要修改的元素数量
                int cntl = cnt[b[i - k + 1]]--;   //滑动窗口最左侧的元素（即将离开滑动窗口范围的元素）在滑动窗口内的数量
                if((it = ms.find(cntl)) != ms.end())    //删除该元素，并更新当前滑动窗口内该元素对应的数量
                {
                    ms.erase(it);
                    ms.insert(cntl - 1);
                }
            }
        }
        while(q--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", ans[r]);
        }
    }
    return 0;
}
