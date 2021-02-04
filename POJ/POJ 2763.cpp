/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-02-03
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 树链剖分
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

/**
    fa[]表示结点的父亲
    pos[]表示树剖分以后结点的dfs序
    dep[]表示结点的深度
    top[]表示结点所在的重链的顶端结点
    son[]表示结点的重儿子（size[]值最大的子结点）
    sz[]表示以该结点为根的子树的结点数
    rk[]表示当前dfs序在树中所对应的结点
 */

const int MAXN = 100005;
typedef int Type;

class TreeChain
{
public:
    struct Edge
    {
        int u, v;
        Edge() {}
        Edge(int u, int v) : u(u), v(v) {}
    } e[MAXN << 1];
    int cnt, n;
    int fa[MAXN], pos[MAXN], dep[MAXN], top[MAXN], son[MAXN], sz[MAXN], rk[MAXN];
    int head[MAXN], nxt[MAXN << 1];
    int sum[MAXN << 2];
    int seg_nd;

    void init(int n)
    {
        this -> n = n;
        cnt = seg_nd = 0;
        fa[1] = -1;
        memset(head, -1, sizeof(head));
    }

    void addEdge(int u, int v)
    {
        e[cnt] = Edge(u, v);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    void dfs1(int u, int d)
    {
        dep[u] = d;
        sz[u] = 1;
        son[u] = -1;
        int Max = 0;
        for(int i = head[u]; ~i; i = nxt[i])
        {
            Edge &ed = e[i];
            if(ed.v == fa[u])
                continue;
            fa[ed.v] = u;
            dfs1(ed.v, d + 1);
            sz[u] += sz[ed.v];
            if(Max < sz[ed.v])
            {
                son[u] = ed.v;
                Max = sz[ed.v];
            }
        }
    }

    void dfs2(int u, int tp)
    {
        pos[u] = ++seg_nd;
        rk[seg_nd] = u;
        top[u] = tp;
        if(~son[u])
            dfs2(son[u], tp);
        for(int i = head[u]; ~i; i = nxt[i])
        {
            int v = e[i].v;
            if(v == fa[u] || v == son[u])
                continue;
            dfs2(v, v);
        }
    }

    void pushUp(int rt)
    {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }

    void build(int l, int r, int rt)
    {
        if(l == r)
        {
            sum[rt] = 0;
            return ;
        }
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
        pushUp(rt);
    }

    void update(int val, int p, int l, int r, int rt)
    {
        if(l == r)
        {
            sum[rt] = val;
            return ;
        }
        int mid = (l + r) >> 1;
        if(p <= mid)
            update(val, p, lson);
        else
            update(val, p, rson);
        pushUp(rt);
    }

    Type query(int L, int R, int l, int r, int rt)
    {
        if(L <= l && r <= R)
            return sum[rt];
        int mid = (l + r) >> 1;
        Type ret = 0;
        if(L <= mid)
            ret += query(L, R, lson);
        if(R > mid)
            ret += query(L, R, rson);
        return ret;
    }

    int find(int u, int v)
    {
        int ans = 0;
        int fu = top[u], fv = top[v];
        int ql, qr;
        while(fu != fv) //当两个结点所属重链不同
        {
            if(dep[fu] < dep[fv])
            {
                swap(u, v);
                swap(fu, fv);
            }
            ql = pos[fu], qr = pos[u];
            ans += query(ql, qr, 1, n, 1); //区间查询该结点所在重链对应线段树的区间[fu, u]（u的深度一定不小于fu，所以dfs序一定不小于fu）
            u = fa[fu];
            fu = top[u];
        }
        if(u == v)
            return ans;
        if(dep[u] > dep[v])
            swap(u, v);
        ql = pos[son[u]], qr = pos[v];
        return ans + query(ql, qr, 1, n, 1);
    }

    void p2e(int u, int v, int w)
    {
        if(dep[u] > dep[v])
            update(w, pos[u], 1, n, 1);
        else
            update(w, pos[v], 1, n, 1);
    }
} tc;

int u[MAXN], v[MAXN], w[MAXN];

int main()
{
    int n, q, s;
    scanf("%d%d%d", &n, &q, &s);
    tc.init(n);
    for(int i = 1; i < n; i++)
    {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        tc.addEdge(u[i], v[i]);
        tc.addEdge(v[i], u[i]);
    }
    tc.dfs1(1, 0);
    tc.dfs2(1, 1);
    tc.build(1, n, 1);
    //点权转边权并单点更新
    for(int i = 1; i < n; i++)
        tc.p2e(u[i], v[i], w[i]);
    while(q--)
    {
        int op;
        scanf("%d", &op);
        if(op)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            tc.p2e(u[x], v[x], y);
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", tc.find(x, s));
            s = x;
        }
    }
    return 0;
}
