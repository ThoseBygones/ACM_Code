/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:2018-03-11
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp + 线段树区间求最值
 ********************************************************************************
 *  Algo-Description:
 *  > 首先证明一个前提条件：任何划分出来的一个区间的长度不应该超过c。
 *  > 证明如下：
 *    > 如果这个区间长度大于c：设 len = n * c + k，那么这个区间被分成n个长度为c的区间和一个长度为k的区间的方式更优；
 *    > 因为这样去掉的元素数量是相同的，而如果长度为k的区间中如果有更小的值则不会被取到；
 *    > 因为每次去掉的最小值仅仅是局部最小值，不一定是全局最小值；
 *    > 因此应该尽量使划分出来的区间长度为c（这样才能删除值）。
 *  > 前缀和+线段树求出某个长度为c区间的最小值：
 *    > 某个连续区间求和使用前缀和预处理（复杂度O(n)）；
 *    > 给定区间的最小值使用线段树（复杂度O(nlogn)）；
 *    > 所求的 sum = (pre[i+c] - pre[i]) - query(i-c+1,i,1,n,1)；
 *    > 其中pre[i]为前缀和数组，query(L,R,l,r,rt)为线段树查询区间最值函数。
 *  > 剩下的问题用dp解决：
 *    > dp[i]表示前i个数划分后题目要求的sum的最小值。
 *    > 状态转移方程：
 *      > 若第i个数与前c-1个数能构成一个长为c的区间，则 dp[i] = min(dp[i−1] + a[i], dp[i−c+1] + sum[i] − sum[i−c] + query(i-c+1,i,1,n,1))；
 *      > 否则直接单个数划分一个区间：dp[i] = dp[i-1] + a[i]。
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
#define MAXN 100005

typedef LL Type;

LL a[MAXN];
LL sum[MAXN];  //前缀和
LL dp[MAXN];   //dp[i]表示前i个数划分后题目要求的sum的最小值

Type Min[MAXN<<2];

void init()
{
    memset(Min,0,sizeof(Min));
}

void pushUp(int rt)
{
    Min[rt] = min(Min[rt<<1], Min[rt<<1|1]);
}

void build(int l,int r,int rt)  //建树
{
    if(l == r)
    {
        Min[rt] = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(rt);
}

Type queryMin(int L,int R,int l,int r,int rt)   //区间求最小值（不需要pushdown）
{
    if(L <= l && r <= R)
        return Min[rt];
    int mid = (l + r) >> 1;
    Type ret = INF;
    if(L <= mid)
        ret = min(ret, queryMin(L, R, lson));
    if(R > mid)
        ret = min(ret, queryMin(L, R, rson));
    return ret;
}

int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    init();
    build(1,n,1);
    for(int i=1; i<=n; i++)
    {
        if(i-c>=0)
            dp[i]=min(dp[i-1]+a[i],dp[i-c]+sum[i]-sum[i-c]-queryMin(i-c+1,i,1,n,1));
        else
            dp[i]=dp[i-1]+a[i];
    }
    printf("%I64d\n",dp[n]);
    return 0;
}
