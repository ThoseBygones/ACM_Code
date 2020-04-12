/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-12
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 数论 + 贪心 + 前缀和
 ********************************************************************************
 *  Algo-Description:
 * > 考虑操作完成之后的结果，如果每一个数字都能被 k 整除，那么显然总和 S = SIGMA(a[i]) (1 <= i <= n) 也可以被k整除。所以 k 一定是 S 的一个因数。
 * > k 为合数时，要么被其质因子的情况包括，要么就劣于这种情况。故只需要考虑 k 为质数的情况，即求出 S 的所有质因子。
 * > 分解出来所有可能的 k ，问题转化成：给定一个数字 k ，问最少需要多少次操作使得这个序列里所有的数字可以被 k 整除。
 * > 从左往右贪心考虑，依次处理每一盒巧克力，使其数量满足 a[i] % k == 0 。 
 * > 显然，要么把多余的巧克力移动到右边的盒子（移走 a[i] % k 个巧克力），要么从别的盒子拿来巧克力补足（拿来 k - a[i] % k 个巧克力）。
 * > 这里不需要考虑到底从哪个盒子来的，即使当前右边的盒子巧克力并不够补足或者会破坏原有 a[i+1] % k == 0 状态。
 * > 因为在左边盒子都已经满足 a[j] % k == 0 时，巧克力的来源（或者去向）只能是右边的盒子a[j+1]。
 * > 由于右边盒子的巧克力还可以由更右边盒子的巧克力来平衡，故此时只需要满足当前盒子巧克力数量符合要求即可。
 * > 另外，由于巧克力总数 S % k == 0 ，故最终一定能使所有盒子的巧克力满足 a[i] % k == 0 （最后一个盒子尽管没有右边的盒子，但最坏的情况是在处理完倒数第二个盒子巧克力数量后，最后一个盒子里的巧克力数量也会满足要求）。
 * > 对于当前盒子，移走巧克力和补足巧克力两种方案取最小值即可。
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 1000005

int a[MAXN];
LL sum[MAXN];
int n;

LL solve(LL val)
{
    LL res = 0;
    for(int i = 1; i <= n; i++) //从左往右贪心处理每个盒子里的巧克力，使其数量满足%k==0
        res += min(sum[i] % val, val - sum[i] % val);   //把这个盒子里%k余下的巧克力拿走或者从别的盒子拿来巧克力使得该盒子里巧克力数量%k==0
    return res;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    LL tmp = sum[n];
    if(tmp < 2)
    {
        puts("-1");
        return 0;
    }
    LL ans = LINF;
    for(LL i = 2; i * i <= tmp; i++)    //枚举其质因数
    {
        if(tmp % i == 0)
        {
            ans = min(ans, solve(i));
            while(tmp % i == 0)
                tmp /= i;
        }
    }
    if(tmp > 1) //如果本身就是质因数，特殊处理
        ans = min(ans, solve(tmp));
    printf("%lld\n", ans);
    return 0;
}
