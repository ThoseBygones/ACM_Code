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

const int MAXN = 10010;

struct Node
{
    int l, r;
    bool lc, rc;    //左右端点是否被覆盖
    int cov, cnt, len;  //被覆盖的次数，包含区间的数量，区间长度
    Node() {}
    Node(int l, int r, bool lc, bool rc, int cov, int cnt, int len) : l(l), r(r), lc(lc), rc(rc), cov(cov), cnt(cnt), len(len) {}
} tree[MAXN << 2];

struct ScanLine
{
    int l, r, h;
    int flag;
    ScanLine() {}
    ScanLine(int l, int r, int h, int flag) : l(l), r(r), h(h), flag(flag) {}
    bool operator < (const ScanLine &l) const
    {
        return h < l.h;
    }
} sl[MAXN];

int x[MAXN];   //离散化后的坐标

void pushUp(int rt)   //向上更新
{
    int l = tree[rt].l, r = tree[rt].r;
    if(tree[rt].cov)    //该区间被线段覆盖
    {
        tree[rt].len = x[r + 1] - x[l];
        tree[rt].cnt = 1;   //此时，垂直于扫描线方向有cnt*2条竖线
        tree[rt].lc = tree[rt].rc = true;
    }
    else if(l == r)
    {
        tree[rt].len = 0;
        tree[rt].cnt = 0;
        tree[rt].lc = tree[rt].rc = false;
    }
    else
    {
        tree[rt].len = tree[rt << 1].len + tree[rt << 1 | 1].len;
        tree[rt].cnt = tree[rt << 1].cnt + tree[rt << 1 | 1].cnt - tree[rt << 1].rc * tree[rt << 1 | 1].lc; //若该结点左子树的右端点和右子树的左端点被覆盖了，则不再重复计算
        tree[rt].lc = tree[rt << 1].lc, tree[rt].rc = tree[rt << 1 | 1].rc; //更新区间合并后左右端点被覆盖的情况
    }
}

void build(int l, int r, int rt)    //建树
{
    tree[rt].l = l, tree[rt].r = r;
    tree[rt].lc = tree[rt].rc = false;
    tree[rt].cov = tree[rt].cnt = tree[rt].len = 0;
    if(l == r)
        return ;
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
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
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x[++cnt] = x1;
        sl[cnt] = ScanLine(x1, x2, y1, 1);
        x[++cnt] = x2;
        sl[cnt] = ScanLine(x1, x2, y2, -1);
    }
    sort(x + 1, x + 1 + cnt);
    sort(sl + 1, sl + 1 + cnt);
    int m = unique(x + 1, x + 1 + cnt) - x - 1; //离散化
    build(1, m, 1);
    int ans = 0, pre = 0;   //答案，前一条扫描线所在位置边的长度和
    for(int i = 1; i <= cnt; i++)
    {
        int l = lower_bound(x + 1, x + 1 + m, sl[i].l) - x;
        int r = lower_bound(x + 1, x + 1 + m, sl[i].r) - x - 1;
        update(sl[i].flag, l, r, 1);
        //printf("cnt: %d\n", tree[1].cnt);
        //printf("len: %d\n", tree[1].len);
        if(i != cnt)    //计算垂直于扫描线的边的边长和
            ans += 2 * tree[1].cnt * (sl[i + 1].h - sl[i].h);
        ans += abs(tree[1].len - pre);  //计算平行于扫描线的边的边长和
        pre = tree[1].len;  //更新前一条扫描线的长度
    }
    printf("%d\n", ans);
    return 0;
}
