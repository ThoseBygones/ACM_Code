/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-18
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 树状数组 + 离散化
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

const int MAXN = 200005;

struct Segment
{
    int l, r;
    Segment() {}
    Segment(int l, int r) : l(l), r(r) {}
    bool operator < (const Segment &seg) const
    {
        if(l == seg.l)
            return r < seg.r;
        return l < seg.l;
    }
} seg[MAXN];

int a[MAXN << 1];   //离散化下标数组

int bit1[MAXN << 1], bit2[MAXN << 1];
int cnt;

void add(int *bit, int i, int x)
{
    while(i <= cnt)   //MaxVal等于数值的最大值而不是数组的大小
    {
        bit[i] += x;
        i += lowbit(i);
    }
}

int getSum(int *bit, int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        cnt = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &seg[i].l, &seg[i].r);
            a[++cnt] = seg[i].l;
            a[++cnt] = seg[i].r;
        }
        //离散化
        sort(seg, seg + n);
        sort(a + 1, a + 1 + cnt);
        cnt = unique(a + 1, a + 1 + cnt) - a - 1;   //去重
        for(int i = 0; i <= cnt; i++)
            bit1[i] = bit2[i] = 0;
        for(int i = 0; i < n; i++)
        {
            seg[i].l = lower_bound(a + 1, a + 1 + cnt, seg[i].l) - a;
            seg[i].r = lower_bound(a + 1, a + 1 + cnt, seg[i].r) - a;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)  //第一个区间的左端点一定是最左边的那个点，其它线段左端点在该区间中的一定与该区间相交
            add(bit1, seg[i].l, 1); //插入区间左端点
        for(int i = 0; i < n; i++)
        {
            int tmp = getSum(bit1, seg[i].r) - getSum(bit1, seg[i].l - 1);  //当前区间内，有多少线段的左端点在该区间中
            tmp += getSum(bit2, cnt) - getSum(bit2, seg[i].l - 1);  //当前区间左端点到最右端那个点所构成的区间，有多少线段的右端点在该区间中
            ans = max(ans, tmp);
            add(bit1, seg[i].l, -1);    //删掉当前区间的左端点
            add(bit2, seg[i].r, 1); //加入当前区间的右端点
        }
        printf("%d\n", n - ans);
    }
    return 0;
}
