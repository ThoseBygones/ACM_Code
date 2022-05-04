/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-01
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 最短路dijkstra + A*算法
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

const int MAXN = 1005;
const int MAXE = 100005;

class Dijkstra
{
public:
    int head[MAXN], head2[MAXN], cnt, cnt2;
    int d[MAXN];
    struct Edge
    {
        int v, w, nxt;
        Edge() {}
        Edge(int v, int w) : v(v), w(w) {}
        bool operator < (const Edge& ed) const
        {
            return w > ed.w;
        }
    } e[MAXE], ne[MAXE];

    struct Node
    {
        int u, d, h;    //d为终点T到点v的距离，h为估计函数h(x)
        Node() {}
        Node(int u, int d, int h) : u(u), d(d), h(h) {}
        bool operator < (const Node &nd) const
        {
            return d + h > nd.d + nd.h;
        }
    };

    int vis[MAXN];
    int n, m;

    //初始化，n为点数，m为边数
    void init(int n, int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = cnt2 = 0;
        memset(head, -1, sizeof(head));
        memset(head2, -1, sizeof(head2));
    }

    inline void addEdge(int u, int v, int w)
    {
        e[cnt].v = v;
        e[cnt].w = w;
        e[cnt].nxt = head[u];
        head[u] = cnt++;
        ne[cnt2].v = u;
        ne[cnt2].w = w;
        ne[cnt2].nxt = head2[v];
        head2[v] = cnt2++;
    }

    void dijkstra(int s)
    {
        for(int i = 0; i <= n; i++)
        {
            d[i] = INF;
            vis[i] = false;
        }
        d[s] = 0;
        priority_queue<Edge> q;
        q.push(Edge(s, 0));
        while(!q.empty())
        {
            Edge ed = q.top();
            q.pop();
            if(vis[ed.v])   //没有该判断会TLE
                continue;
            vis[ed.v] = true;
            for(int i = head2[ed.v]; ~i; i = ne[i].nxt)
            {
                Edge ee = ne[i];
                if(!vis[ee.v] && d[ee.v] > d[ed.v] + ee.w)
                {
                    d[ee.v] = d[ed.v] + ee.w;
                    q.push(Edge(ee.v, d[ee.v]));
                }
            }
        }
    }

    int A_star(int s, int t, int k)
    {
        memset(vis, 0, sizeof(vis));
        priority_queue<Node> pq;
        pq.push(Node(s, 0, d[s]));
        while(!pq.empty())
        {
            Node nd = pq.top();
            pq.pop();
            vis[nd.u]++;
            if(nd.u == t && vis[nd.u] == k) //刚出队的点为终点t且该点已入队（出队）k次（说明是第k短路）
                return nd.d;
            for(int i = head[nd.u]; ~i; i = e[i].nxt)
            {
                int v = e[i].v, w = e[i].w;
                if(vis[v] < k)  //该点入队的次数小于k
                    pq.push(Node(v, w + nd.d, w + nd.d + d[v]));
            }
        }
        return -1;
    }

    void buildGraph()
    {
        int u, v, w;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
    }

    void solve()
    {
        buildGraph();   //建图
        int s, t, k;
        scanf("%d%d%d", &s, &t, &k);
        if(s == t)
            k++;
        dijkstra(t);
        printf("%d\n", A_star(s, t, k));
    }
} dij;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    dij.init(n, m);
    dij.solve();
    return 0;
}
