/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-15
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 前缀和 + 后缀和
 ********************************************************************************
 *  Algo-Description:
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

const int MAXN = 2005;

struct Segment
{
    int l, r;
    bool operator < (const Segment & seg) const
    {
        return l + r < seg.l + seg.r;   //按照区间中点（乘2）排序
    }
} seg[MAXN];

int pre[MAXN];  //pre[i]表示第1~i个区间与长度为k的固定区间计算前缀相交部分长度求和后的最大值
int suf[MAXN];  //suf[i]表示第i~n个区间与长度为k的固定区间计算后缀相交部分长度求和后的最大值

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++)
        scanf("%d%d", &seg[i].l, &seg[i].r);
    sort(seg + 1, seg + 1 + m);
    //假设区间a的中点在区间b的中点的左边（始终）
    for(int i = 1; i <= n - k + 1; i++) //枚举区间的起点
    {
        int sum = 0;
        for(int j = m; j; j--)  //从右到左枚举m个区间（认为区间j~m与长度为k的固定区间后缀相交更优）
        {
            sum += max(min(i + k - 1, seg[j].r) - max(i, seg[j].l) + 1, 0);
            suf[j] = max(sum, suf[j]);  //记录第j~m个区间与长度为k的固定区间相交部分长度和的最大值
        }
    }
    for(int i = 1; i <= n - k + 1; i++) //枚举区间b的起点
    {
        int sum = 0;
        for(int j = 1; j <= m; j++) //从左到右枚举m个区间（认为区间1~j与长度为k的固定区间前缀相交更优）
        {
            sum += max(min(i + k - 1, seg[j].r) - max(i, seg[j].l) + 1, 0);
            pre[j] = max(sum, pre[j]);  //记录1~j个区间与长度为k的固定区间相交部分长度和的最大值
        }
    }
    int ans = 0;
    for(int i = 0; i <= m; i++) //枚举所有的前缀相交和后缀相交的组合情况
        ans = max(ans, pre[i] + suf[i + 1]);
    printf("%d\n", ans);
    return 0;
}
