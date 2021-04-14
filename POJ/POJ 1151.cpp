/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-14
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 线段树 + 离散化 + 扫描线
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

const int MAXN = 210;

struct Node
{
    int l, r;
    int cov;
    double sum;
} tree[MAXN << 2];

struct ScanLine
{
    double l, r, h;
    int flag;
    ScanLine() {}
    ScanLine(double l, double r, double h, int flag) : l(l), r(r), h(h), flag(flag) {}
    bool operator < (const ScanLine &l) const
    {
        return h < l.h;
    }
} sl[MAXN];

double x[MAXN];

void pushUp(int rt)   //向上更新
{
    int l = tree[rt].l, r = tree[rt].r;
    if(tree[rt].cov) //当前区间有计数
        tree[rt].sum = x[r + 1] - x[l];
    else if(l == r)
        tree[rt].sum = 0;
    else
        tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

void build(int l, int r, int rt)
{
    tree[rt].l = l, tree[rt].r = r;
    tree[rt].cov = 0;
    tree[rt].sum = 0.0;
    if(l == r)
        return ;
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int val, int L, int R, int rt)
{
    int l = tree[rt].l, r = tree[rt].r;
    if(L <= l && r <= R)
    {
        tree[rt].cov += val;
        pushUp(rt);
        return ;
    }
    int mid = (l + r) >> 1;
    if(L <= mid)
        update(val, L, R, rt << 1);
    if(R > mid)
        update(val, L, R, rt << 1 | 1);
    pushUp(rt);
}

int main()
{
    int kase = 1;
    int n;
    while(~scanf("%d", &n), n)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            x[++cnt] = x1;
            sl[cnt] = ScanLine(x1, x2, y1, 1);
            x[++cnt] = x2;
            sl[cnt] = ScanLine(x1, x2, y2, -1);
        }
        sort(x + 1, x + 1 + cnt);
        sort(sl + 1, sl + 1 + cnt);
        int m = unique(x + 1, x + 1 + cnt) - x - 1; //离散化
        build(1, m, 1);
        double ans = 0.0;
        for(int i = 1; i < cnt; i++)
        {
            int l = lower_bound(x + 1, x + 1 + m, sl[i].l) - x;
            int r = lower_bound(x + 1, x + 1 + m, sl[i].r) - x - 1;
            update(sl[i].flag, l, r, 1);
            ans += tree[1].sum * (sl[i + 1].h - sl[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", kase++, ans);
    }
    return 0;
}
