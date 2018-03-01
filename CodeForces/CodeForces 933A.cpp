/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-28
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 前缀和 + 后缀和
 ********************************************************************************
 *  Algo-Description:
 *  > 设翻转区间为[i,j]，则最终构成我们要求的最大不下降子序列的是区间[1,i-1]中的1，区间[j+1,n]中的2和区间[i,j]中的最大不下降子序列。
 *  > 处理数字1的前缀和：pre1[i]表示区间[1,i]内有多少个数字1；
 *  > 处理数字2的后缀和：suf2[i]表示区间[i,n]内有多少个数字2；
 *  > 对于区间[i,j]，可以考虑枚举一个翻转点k（即统计数字1和2的分界点）。相当于翻转后k点之前的2变到了k点的后面，k点之后的1点变到了k点的后面。
 *  > 枚举区间的边界点i,j以及k点，答案即为 max(pre1[i-1] + suf2[i] - suf2[k+1] + suf2[j+1] + pre1[j] - pre1[k-1])
 *  > 当然，直接枚举区间的边界点i,j以及k点复杂度O(n^3)肯定超时，而其实上只需要枚举k点，然后i,j点从k点往两边扩展即可（复杂度O(n^2)）。
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
#define MAXN 2005

int a[MAXN];
int pre1[MAXN]; //数字1的前缀和（pre1[i]表示区间[1,i]内有多少个数字1）
int suf2[MAXN]; //数字2的后缀和（suf2[i]表示区间[i,n]内有多少个数字2）

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
        pre1[i]=pre1[i-1]+(a[i]==1);
    for(int i=n; i>=1; i--)
        suf2[i]=suf2[i+1]+(a[i]==2);
    int ans=0;
    for(int k=1; k<=n; k++) //枚举数字1和2的分界点k
    {
        int cnt1=0; //最长不下降子序列中1的数量
        int cnt2=0; //最长不下降子序列中2的数量
        for(int i=k; i>=1; i--) //枚举翻转区间左端点i
            cnt1=max(cnt1,pre1[i-1]+suf2[i]-suf2[k+1]); //统计区间[1,i-1]中1的数量和区间[i,k]中2的数量（因为以k为分界点翻转后区间[i,k]中2生效
        for(int j=k; j<=n; j++)
            cnt2=max(cnt2,suf2[j+1]+pre1[j]-pre1[k-1]); //统计区间[j+1,n]中2的数量和区间[k,j]中1的数量（因为以k为分界点翻转后区间[k,j]中1生效
            ans=max(ans,cnt1+cnt2);
    }
    printf("%d\n",ans);
    return 0;
}
