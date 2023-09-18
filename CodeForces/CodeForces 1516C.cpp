/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-09-18
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp + gcd
 ********************************************************************************
 *  Algo-Description:
 * > 对整个序列求和得到 sum，
 *   > 若 sum 为奇数：那么无论如何划分，最后都会划分为一个奇数一个偶数的和，所以此时该序列一定为好序列；
 *   > 若 sum 为偶数，就需要判断是否存在一个子序列可以组成 sum / 2​，这里需要用01背包进行处理判断是否可以构成一个和为 sum / 2 的子序列。
 * > 若不能构成 sum / 2，
 *   > 说明任意一个子序列的和都不会等于 sum / 2，所以其互补的部分也一定不会等于 sum / 2，此时这个序列一定为好序列；
 * > 若能构成 sum / 2，
 *   > 若序列中含有奇数，直接去掉一个奇数项即可。
 *   > 证明如下：
 *     > 假设可以将该序列分为 a[i_1] + a[i_2] + ... + a[i_n] = a[j_1] + a[j_2] + ... + a[j_m]，
 *     > 若原序列存在一个奇数项，那么一定在两个序列中，存在某个元素 x， 所以当删去 x 时，需要另一个序列删去 x / 2 以补给该序列，
 *     > 又因为 x 为奇数，所以无法做到删去 x / 2，
 *     > 故删去t后一定为好序列。
 *   > 若序列中不含有奇数项，那么：
 *     > 将 a[i_1] + a[i_2] + ... + a[i_n] = a[j_1] + a[j_2] + ... + a[j_m] 转化为 x * (b[i_1] + b[i_2] + ... + b[i_n]) = x * (b[j_1] + b[j_2] + ... + b[j_m])，
 *     > （设 x 为 a[i_1], ..., a[i_n] 和 a[j_1], ..., a[j_m] 的最大公因数，即 x = gcd(a[i_1], ..., a[i_n], a[j_1], ..., a[j_m])，
 *     > 此时两边序列中至少有一个数为奇数，若不存在奇数，那么 x 可以继续乘以 2, 即说明此时 x 不为 a[i_1], ..., a[i_n], a[j_1], ..., a[j_m] 的最大公因数，与前提条件矛盾，
 *     > 当 x 为 a[i_1], ..., a[i_n], a[j_1], ..., a[j_m] 的最大公因数时，问题转化为了序列中含有奇数的情况；
 *     > 故此时只需要删除序列除以 x 后序列中出现的某一个奇数即可。
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

const int MAXN = 100;
const int MAXV = 2000;

int a[MAXN + 5];
bool dp[MAXN * MAXV + 5];  //dp[i]表示是否存在一个子序列和为i

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if(sum & 1) //所有元素和为奇数，因此不能被划分为元素和相等的两个不相交子序列（该序列一定为好序列）
        puts("0");
    else
    {
        dp[0] = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = sum; j >= a[i]; j--)
                dp[j] |= dp[j - a[i]];
        }
        if(dp[sum / 2] == 0)    //不存在和为sum/2的子序列（该序列一定为好序列）
            puts("0");
        else
        {
            int gcd = a[1];
            for(int i = 2; i <= n; i++) //求最大公约数
                gcd = __gcd(gcd, a[i]);
            for(int i = 1; i <= n; i++)
            {
                a[i] /= gcd;
                if(a[i] & 1)    //除以最小公约数以后为奇数，则删除该数后序列为好序列
                {
                    printf("1\n%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
