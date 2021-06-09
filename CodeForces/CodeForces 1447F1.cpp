/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-09
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 枚举 + 前缀和 + （哈希）
 ********************************************************************************
 *  Algo-Description:
 * > 如果数组有多个众数，那么直接输出 n ；
 * > 当原数组的众数唯一：
 *   > 有如下重要结论：原数组的众数一定是答案子区间的众数之一。
 *   > 反证法证明：
 *     > 如果原数组的众数 x 不是子区间的众数，那么 x 出现的次数小于子区间众数出现的次数。
 *     > 此时的区间一定可以向两端扩张，使得 x 的出现次数增大。
 *     > 由于在整个数组中 x 的出现次数严格大于子区间众数的出现次数，所以一定有一个更大的区间使得 x 和另一个数是这个子区间的众数。
 *     > 此时，这个新区间是更优的答案。
 *   > 根据上述结论，得到解法如下：
 *     > 枚举区间 [1, 100] 中的数作为子区间的另一个众数，寻找一个最大的区间使得 x 和 y 的数量相同；
 *     > 利用类似前缀和的方法，遇到 x 就 + 1，遇到 y 就 - 1，找到前缀和为 0 的最长区间；
 *   > 该这个做法仅考虑两个数，即只考虑区间众数 x 和枚举的数 y ；
 *   > 此时区间内可能会出现另一个数 z ，出现的次数大于 x 和 y 出现的次数，但是该情况求得的区间长度一定不是符合要求的长度最大的区间；
 *   > 因为该情况下把 y 换成 z 后，当前区间显然还能向两端扩张（由于此时 x < z）。
 *   > 故该解法（算法）是正确的。
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

int a[MAXN], cnt[105];
int pre[MAXN << 1];   //速度快，171ms
//unordered_map<int, int> ump;    //速度慢，1123ms

int main()
{
    int n;
    scanf("%d", &n);
    int maxcnt = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        maxcnt = max(maxcnt, cnt[a[i]]);
    }
    int mode = 0;   //众数
    int modecnt = 0;    //众数的数量
    for(int i = 1; i <= min(n, 100); i++)
    {
        if(maxcnt == cnt[i])
        {
            modecnt++;
            mode = i;
        }
    }
    if(modecnt > 1)
        printf("%d\n", n);
    else
    {
        int ans = 0;
        for(int i = 1; i <= min(n, 100); i++)   //枚举另一个众数
        {
            if(i == mode)
                continue;
            int sum = 0;
            memset(pre, 0, sizeof(pre));
            //ump.clear();
            for(int j = 1; j <= n; j++)
            {
                if(a[j] == mode)    //如果是原来的众数，+1
                    sum++;
                if(a[j] == i)   //如果是枚举的这个众数，-1抵消
                    sum--;
                if(sum && !pre[sum + MAXN]) //区间整体右移映射（[-2e5, 2e5] -> [0, 4e5]）
                    pre[sum + MAXN] = j;
                ans = max(ans, j - pre[sum + MAXN]);
                /*if(sum && !ump[sum])
                    ump[sum] = j;
                ans = max(ans, j - ump[sum]);
                */
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
