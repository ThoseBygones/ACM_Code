/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-06
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 线段树rmq
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
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

const int MAXN = 100005;

int a[MAXN], cnt[MAXN];
int lm[MAXN], rm[MAXN];  //lm/rm[i]表示对应a[i]所在连续区间的左边界和右边界

class SegTree
{
public:
    int Max[MAXN << 2];

    void init()
    {
        memset(Max, 0, sizeof(Max));
    }

    void pushUp(int rt)
    {
        Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
    }

    void build(int l, int r, int rt)
    {
        if(l == r)
        {
            Max[rt] = cnt[l];
            return ;
        }
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
        pushUp(rt);
    }

    int query(int L, int R, int l, int r, int rt)
    {
        if(L <= l && r <= R)
            return Max[rt];
        int mid = (l + r) >> 1;
        int ret = -INF;
        if(L <= mid)
            ret = max(ret, query(L, R, lson));
        if(R > mid)
            ret = max(ret, query(L, R, rson));
        return ret;
    }
} segtree;

int main()
{
    int n, q;
    while(~scanf("%d", &n), n)
    {
        scanf("%d", &q);
        int lp = 1, rp = n;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if(i != 1 && a[i] == a[i - 1])
                cnt[i] = cnt[i - 1] + 1;
            else
                cnt[i] = 1;
        }
        for(int i = 1; i <= n; i++) //计算每个区间的左边界
        {
            if(i != 1 && a[i] != a[i - 1])
                lp = i;
            lm[i] = lp;
        }
        for(int i = n; i; i--)  //计算每个区间的右边界
        {
            if(i != n && a[i] != a[i + 1])
                rp = i;
            rm[i] = rp;
        }
        segtree.build(1, n, 1);
        int ans = 0;
        while(q--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int lr = rm[l]; //求出[l,r]区间中a[l]所在区间的右边界（设为区间1）
            int rl = lm[r]; //求出[l,r]区间中a[r]所在区间的左边界（设为区间2）
            if(lr + 1 < rl) //如果两个区间之间还有别的数构成的区间
                ans = max(segtree.query(lr + 1, rl - 1, 1, n, 1), max(lr - l + 1, r - rl + 1));
            else if(lr + 1 == rl)   //如果两个区间边界相连
                ans = max(lr - l + 1, r - rl + 1);
            else    //如果两个区间都是同一个数所在的区间
                ans = r - l + 1;
            printf("%d\n", ans);
        }
    }
    return 0;
}
