/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-12-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 可持久化线段树（主席树）
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

const int MAXN = 100005;
const int MAXNODE = 2000005;

class Per_SegTree
{
public:
    int a[MAXN], x[MAXN];
    struct Node
    {
        Node *l, *r;
        int cnt;
        void init()
        {
            l = r = NULL;
            cnt = 0;
        }
    } nd[MAXNODE], *root[MAXN];

    int tot, m; //tot是结点数，m是离散化后值的个数
    void init(int n)
    {
        tot = 0;
        m = disconcrete(n);
        root[0] = build(1,m);
        for(int i = 1; i <= n; i++)
            root[i] = insert(root[i - 1], 1, m, a[i]);
    }

    Node* newNode()
    {
        nd[tot].init();
        return &nd[tot++];
    }

    Node* build(int l, int r)
    {
        Node *rt = newNode();
        if(l == r)
            return rt;
        int mid = (l + r) >> 1;
        rt -> l = build(l, mid);
        rt -> r = build(mid + 1, r);
        return rt;
    }

    Node *insert(Node *last, int l, int r, int val)
    {
        Node *rt = newNode();
        *rt = *last;
        rt -> cnt++;
        if(l == r)
            return rt;
        int mid = (l + r) >> 1;
        if(val <= mid)
            rt -> l = insert(last -> l, l, mid, val);
        else
            rt -> r = insert(last -> r, mid + 1, r, val);
        return rt;
    }

    int disconcrete(int n)
    {
        for(int i = 1; i <= n; i++)
            x[i - 1] = a[i];
        sort(x, x + n);
        int m = unique(x, x + n) - x;
        for(int i = 1; i <= n; i++)
            a[i] = lower_bound(x, x + m, a[i]) - x + 1;
        return m;
    }

    int query(Node *ld, Node *rd, int l, int r, int k)
    {
        if(l == r)
            return x[l - 1];
        int mid = (l + r) >> 1;
        int lcnt = rd -> l -> cnt - ld -> l -> cnt;
        if(lcnt >= k)
            return query(ld -> l, rd -> l, l, mid, k);
        else
            return query(ld -> r, rd -> r, mid + 1, r, k - lcnt);
    }
} per_seg;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &per_seg.a[i]);
    per_seg.init(n);
    while(q--)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", per_seg.query(per_seg.root[l - 1], per_seg.root[r], 1, per_seg.m, k));
    }
    return 0;
}
