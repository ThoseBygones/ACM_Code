/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-20
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 线段树 / 树状数组 / 差分约束（SPFA 求最长路）
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

const int MAXN = 50005;

/* 解法一：树状数组 */

struct Segment
{
    int a, b, c;
    bool operator < (const Segment &seg) const
    {
        if(b == seg.b)
            return a < seg.a;
        return b < seg.b;
    }
} seg[MAXN];

int bit[MAXN];
bool vis[MAXN];

void add(int i, int x)
{
    while(i < MAXN)
    {
        bit[i] += x;
        i += lowbit(i);
    }
}

int getSum(int i)
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
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d%d", &seg[i].a, &seg[i].b, &seg[i].c);
    sort(seg, seg + n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int cnt = getSum(seg[i].b) - getSum(seg[i].a - 1);  //已经选择的个数
        if(cnt < seg[i].c)  //数量不够
        {
            int rem = seg[i].c - cnt;   //还缺少的个数
            int pos = seg[i].b;
            while(rem)
            {
                if(!vis[pos])
                {
                    vis[pos] = true;
                    add(pos, 1);
                    rem--;
                    ans++;
                }
                pos--;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}


/* 解法二：线段树 */

struct Segment
{
    int a, b, c;
    bool operator < (const Segment &seg) const
    {
        if(b == seg.b)
            return a < seg.a;
        return b < seg.b;
    }
} seg[MAXN];

bool vis[MAXN];

int sum[MAXN << 2];

void pushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int val, int pos, int l, int r, int rt)
{
    if(l == r)
    {
        sum[rt] += val;
        return ;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid)
        update(val, pos, lson);
    else
        update(val, pos, rson);
    pushUp(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if(L <= l && r <= R)
        return sum[rt];
    int mid = (l + r) >> 1;
    int res = 0;
    if(L <= mid)
        res += query(L, R, lson);
    if(R > mid)
        res += query(L, R, rson);
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d%d", &seg[i].a, &seg[i].b, &seg[i].c);
    sort(seg, seg + n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int cnt = query(seg[i].a, seg[i].b, 0, MAXN - 1, 1);    //已经选择的个数
        if(cnt < seg[i].c)  //数量不够
        {
            int rem = seg[i].c - cnt;   //还缺少的个数
            int pos = seg[i].b;
            while(rem)
            {
                if(!vis[pos])
                {
                    vis[pos] = true;
                    update(1, pos, 0, MAXN - 1, 1);
                    rem--;
                    ans++;
                }
                pos--;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}


/* 解法三：SPFA 求最长路 */

const int MAXE = MAXN * 3;

typedef int Type;

class CHA
{
public:
    int head[MAXN], nxt[MAXE], cnt;
    Type d[MAXN];
    struct Edge
    {
        int v;
        Type cost;
        Edge() {}
        Edge(int v, Type cost) : v(v), cost(cost) {}
    } e[MAXE];

    bool inq[MAXN];

    void init(int n)
    {
        cnt = 0;
        memset(head, -1, sizeof(head));
    }

    inline void addEdge(int u, int v, Type cost)
    {
        e[cnt] = Edge(v, cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    //int inqcnt[MAXN];

    /*
     * 差分约束求xi的最大值，化为xi-xj<=c的形式，加边(j->i,权值c),求最短路
     * 差分约束求xi的最小值，化为xi-xj>=c的形式，加边(j->i,权值c),求最长路
     *
     */
    Type spfa(int s, int t, int n)    //n的值一般传的大一些（至少n+1）
    {
        for(int i = 0; i <= n; i++)
        {
            inq[i] = false;
            d[i] = -INF;
            //inqcnt[i] = 0;
        }
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            inq[x] = false;
            for(int i = head[x]; ~i; i = nxt[i])
            {
                Edge ed = e[i];
                if(d[ed.v] < d[x] + ed.cost)    //求最长路的时候改为 < 号
                {
                    d[ed.v] = d[x] + ed.cost;
                    if(!inq[ed.v])
                    {
                        //if(++inqcnt[ed.v] > n)
                        //    return INF;
                        inq[ed.v] = true;
                        q.push(ed.v);
                    }
                }
            }
        }
        return d[t];
    }

    void solve(int n)
    {
        init(n);
        int s = INF, t = -1;
        for(int i = 0; i < n; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u++, v++;
            addEdge(u - 1, v, w);   //v - (u - 1) >= w
            s = min(s, u - 1);
            t = max(t, v);
        }
        for(int i = s; i < t; i++)
        {
            addEdge(i, i + 1, 0);   //(u + 1) - u >= 0
            addEdge(i + 1, i, -1);  //(u + 1) - u <= 1 => u - (u + 1) >= -1
        }
        //printf("%d %d\n", s, t);
        int ans = spfa(s, t, t);
        printf("%d\n", ans);
    }
} cha;

int main()
{
    int n;
    scanf("%d", &n);
    cha.solve(n);
    return 0;
}
