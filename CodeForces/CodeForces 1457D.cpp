/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 异或前缀和 + 暴力 + 二进制
 ********************************************************************************
 *  Algo-Description:
 * > 对于每个数字，根据其二进制的第一个 1 分类。例如，0101 属于第 3 类，1000 属于第 4 类。
 * > 如果连续三个数字是同一类，就一定能用一次就能找到破坏的方法使得前两个数异或值小于第三个数。
 * > 设 b[i] 为题目给定数组 a[i] 属于的分类。
 * > 若存在一个 i ，满足 b[i − 1] = b[i] = b[i + 1] ​，则后两个数异或得到的数一定比 a[i − 1]​小（因为异或得到的数最高位变为 0 ）
 * > 若这样的 i 不存在，则原始数组的长度一定不超过 2 * 30 = 60；
 *   > 因为原序列保证单调递增且不存在连续三个数 b[i] 相同
 *   > 因此在 b[i] 单调不减的情况下，最长的情况下会出现的 b[i] 序列如下：
 *     > 1, 1, 2, 2, 3, 3, ..., k - 1, k - 1, k, k
 *     > 由于 a[i] <= 1e9 ，故 b[i] <= k = 30 。
 * > 此时枚举破坏点和左右两个合并区间的端点（左区间的左端点和右区间的右端点）暴力计算即可（n <= 60）：
 * > 最后的答案数组一定存在两个相邻两个数是严格递减，而这两个数是由原始数组中两个相邻段连续异或而成的；
 * > 故枚举左区间左端点 l ， 右区间右端点 r ，破坏点 i 与 i + 1 即可。
 * > 代表区间 a[l, ..., i] 的异或和大于区间 a[i + 1, ..., r] 的异或和。
 * > 用异或前缀和处理，可以把暴力枚举的复杂度从 O(n ^ 4) 降到 O(n ^ 3)，n <= 60 。
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

const int MAXN = 100005;

int a[MAXN], pref[MAXN];    //异或前缀和

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pref[i] = pref[i - 1] ^ a[i];
    }
    for(int i = 3; i < n; i++)
    {
        int sum = a[i - 1] ^ a[i];
        if(sum < a[i - 2] || sum > a[i + 1])
        {
            puts("1");
            return 0;
        }
    }
    int ans = INF;
    for(int i = 1; i < n; i++)  //枚举操作后非下降序列的破坏点
    {
        for(int l = i; l; l--)  //枚举左半边区间操作的左端点
        {
            for(int r = i + 1; r <= n; r++) //枚举右半边区间操作的右端点
            {
                int resl = pref[i] ^ pref[l - 1];
                int resr = pref[r] ^ pref[i];
                if(resl > resr) //构成了下降子序列
                    ans = min(ans, i - l + r - (i + 1));
            }
        }
    }
    if(ans == INF)
        puts("-1");
    else
        printf("%d\n", ans);
    return 0;
}
