/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-04-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 前缀和
 ********************************************************************************
 *  Algo-Description:
 * > 假设第 l 个元素落在第 ldr 次循环移动里，第 r 个元素落在第 rdr 次循环移动里，
 *   > 那么第 ldr + 1 次循环到第 rdr - 1 次循环中每次都是完整的循环移动，
 *   > 一次完整的循环移动的元素没有变化，它的所有元素的和就是原本所有元素的和。
 * > 对中间完整的循环移动，可以快速地用所有元素的和乘上完整的循环移动数组的个数直接算出；
 * > 对于前面和后面分别计算：
 *   > 前面的部分在 ldr 所在的循环移动数组中相当于求个后缀的和，
 *   > 后面的部分在 rdr 所在的循环移动数组中相当于求个前缀的和。
 * > 首先分别找出 l, r 相当于在第几次循环移动数组中的什么位置上，
 * > 然后分别找出循环移动后的前后缀元素在原本数组中的位置，对它们进行求和即可。
 * > 计算 l,r 在第几次循环移动数组中的什么位置上：
 *   > l 在第 ceil(l / n) = (l - 1) / n + 1 个循环移动数组，
 *     > 减去前 ceil(l / n) - 1 = (l - 1) / n 个循环移动数组的长度，
 *     > 得到在这个循环移动数组中的位置：l - [ceil(l / n) - 1] * n = l - (l - 1) / n * n。
 *   > 同理，r 在第 ceil(r / n) = (r - 1) / n + 1 个循环移动数组，
 *     > 减去前 ceil(r / n) - 1 = (r - 1) / n 个循环移动数组的长度，
 *     > 得到在这个循环移动数组中的位置：r - [ceil(r / n) - 1] * n = r - (r - 1) / n * n。
 * > 为了迅速求和，先处理出 a 数组的前缀和数组 sum，
 *   > 算第 x 个循环移动数组的 i 位置以前的前缀和：
 *     > 先将 x 减 1，让初始的循环移动（即原始数组）对应下标 0，
 *     > 这样，第 x 次循环移动的数组的后 x 个元素就是循环移动过来的最后 x 个元素，
 *     > 即循环移动数组是 a[x + 1], a[x + 2], ... , a[n], a[1], a[2], ... , a[x - (n - x)] = sum[n] - sum[x] + sum[i + x - n]。
 * > 计算后面部分（前缀和）：
 *   > 若 i 没有超出前 n - x 个元素，即 i <= n - x，
 *     > 前缀和为：a[x + 1] + a[x + 2] + ... + a[x + i] = sum[x + i] - sum[x]​；
 *   > 若 i > n − x，
 *     > 那么前缀和为：a[id + 1] + a[id + 2] + ... + a[n] + a[1] + ... + a[i - (n - x)] = sum[n] - sum[id] + sum[i + x - n]。
 * > 同理计算前面部分（后缀和）：
 *   > 若 i > n - x，
 *     > 后缀和为：a[i - (n - x)] + ... + a[x] = sum[x] - sum[i + x - n - 1]；
 *   > 若 i <= n - x，
 *     > 后缀和为：a[x + i] + ... + a[n] + a[1] + ... + a[x] = sum[n] - sum[x + i - 1] + sum[x]。
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

LL a[MAXN], sum[MAXN];
int n, q;

LL preSum(LL x, LL i)   //前缀和
{
    x--;
    LL res = 0;
    if(i <= n - x)
        res = sum[i + x] - sum[x];
    else
        res = sum[n] - sum[x] + sum[i + x - n];
    return res;
}

LL sufSum(int x, int i) //后缀和
{
    x--;
    LL res = 0;
    if(i > n - x)
        res = sum[x] - sum[i + x - n - 1];
    else
        res = sum[x] + sum[n] - sum[i + x - 1];
    return res;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        while(q--)
        {
            LL l, r;
            scanf("%lld%lld", &l, &r);
            LL ldr = (l - 1) / n + 1, rdr = (r - 1) / n + 1;   //计算中间有几个完整的a数组和
            LL ans = sum[n] * (rdr - ldr - 1);  //中间完整轮次的数量
            ans += preSum(rdr, r - (r - 1) / n * n);    //对区间[l, r]中末尾部分的（不完整数组）求和
            ans += sufSum(ldr, l - (l - 1) / n * n);    //对区间[l, r]中前面部分的（不完整数组）求和
            printf("%lld\n", ans);
        }
    }
    return 0;
}
