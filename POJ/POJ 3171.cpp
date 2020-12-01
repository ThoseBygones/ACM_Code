/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 线段树 + dp
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

const int MAXN = 10005;
const int MAXM = 86405;

struct Cow
{
    int l, r, s;
    Cow() {}
    Cow(int l, int r, int s) : l(l), r(r), s(s) {}
    bool operator < (const Cow &c) const
    {
        return r < c.r;
    }
} cow[MAXN];

class SegTree
{
public:
    int Min[MAXM << 2];

    void pushUp(int rt)
    {
        Min[rt] = min(Min[rt << 1], Min[rt << 1 | 1]);
    }

    void build(int l, int r, int rt)
    {
        if(l == r)
        {
            Min[rt] = INF;
            return ;
        }
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
        pushUp(rt);
    }

    void update(int x, int val, int l, int r, int rt)
    {
        if(l == r)
        {
            Min[rt] = val;
            return ;
        }
        int mid = (l + r) >> 1;
        if(x <= mid)
            update(x, val, lson);
        else
            update(x, val, rson);
        pushUp(rt);
    }

    int queryNode(int x, int l, int r, int rt)  //单点查询（相当于查询dp值）
    {
        if(l == r)
            return Min[rt];
        int mid = (l + r) >> 1;
        if(x <= mid)
            return queryNode(x, lson);
        else
            return queryNode(x, rson);
    }

    int queryMin(int L, int R, int l, int r, int rt)    //区间查询最小值
    {
        if(L <= l && r <= R)
            return Min[rt];
        int mid = (l + r) >> 1;
        int ret = INF;
        if(L <= mid)
            ret = min(ret, queryMin(L, R, lson));
        if(R > mid)
            ret = min(ret, queryMin(L, R, rson));
        return ret;
    }
} segtree;

int main()
{
    int n, m, e;
    scanf("%d%d%d", &n, &m, &e);
    e -= (m - 2);
    for(int i = 1; i <= n; i++)
    {
        int t1, t2, s;
        scanf("%d%d%d", &t1, &t2, &s);
        cow[i] = Cow(t1 - m + 2, t2 - m + 2, s);
    }
    m = 2;
    sort(cow + 1, cow + 1 + n);
    segtree.build(1, e, 1);
    segtree.update(1, 0, 1, e, 1);
    for(int i = 1; i <= n; i++)
    {
        int val = segtree.queryMin(cow[i].l - 1, cow[i].r - 1, 1, e, 1);
        int r = segtree.queryNode(cow[i].r, 1, e, 1);
        if(val + cow[i].s < r) //更新到右端点cow[i].r的最小花费（相当于dp的状态转移，更新dp[r]的值）
            segtree.update(cow[i].r, val + cow[i].s, 1, e, 1);
    }
    int ans = segtree.queryNode(e, 1, e, 1);    //相当于dp[e]的值
    if(ans == INF)
        puts("-1");
    else
        printf("%d\n", ans);
    return 0;
}
