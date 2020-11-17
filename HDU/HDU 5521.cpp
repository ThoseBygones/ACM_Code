/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-17
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 最短路dijkstra + 虚点
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

const int MAXN = 200005;
const int MAXE = 2000010;

typedef LL Type;

class Dijkstra
{
public:
    int head[MAXN], nxt[MAXE], cnt;
    Type d[2][MAXN];
    struct Edge
    {
        int v;
        Type cost;
        Edge() {}
        Edge(int v, Type cost) : v(v), cost(cost) {}
        bool operator < (const Edge& ed) const
        {
            return cost > ed.cost;
        }
    } e[MAXE];
    bool vis[MAXN];
    int n, m;

    //初始化，n为点数，m为边数
    void init(int n, int m)
    {
        this -> n = n;
        this -> m = m;
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

    void dijkstra(int s, int flag)
    {
        for(int i = 0; i <= n + m; i++)
        {
            d[flag][i] = LINF;
            vis[i] = false;
        }
        d[flag][s] = 0;
        priority_queue<Edge> q;
        q.push(Edge(s, 0));
        while(!q.empty())
        {
            Edge ed = q.top();
            q.pop();
            if(vis[ed.v])   //没有该判断会TLE
                continue;
            vis[ed.v] = true;
            for(int i = head[ed.v]; ~i; i = nxt[i])
            {
                Edge ee = e[i];
                if(!vis[ee.v] && d[flag][ee.v] > d[flag][ed.v] + ee.cost)
                {
                    d[flag][ee.v] = d[flag][ed.v] + ee.cost;
                    q.push(Edge(ee.v, d[flag][ee.v]));
                }
            }
        }
    }

    void buildGraph()
    {
        for(int u = 1; u <= m; u++) //每个集合设立一个虚点
        {
            LL val;
            int k;
            scanf("%lld%d", &val, &k);
            while(k--)
            {
                int v;
                scanf("%d", &v);
                addEdge(u + n, v, val); //将点和代表集合序号的虚点相连
                addEdge(v, u + n, val); //这样最后求出来的最短路为两倍的真实值
            }
        }

    }

    void solve(int kase)
    {
        buildGraph();   //建图
        dijkstra(1, 0); //正向dijkstra
        dijkstra(n, 1); //反向dijkstra
        LL Min = LINF;
        for(int i = 1; i <= n; i++)
            Min = min(Min, max(d[0][i], d[1][i]));
        if(Min == LINF)
            printf("Case #%d: Evil John\n", kase);
        else
        {
            printf("Case #%d: %lld\n", kase, Min / 2);    //答案为两点到虚点距离和，故要减半
            int ans = 0;
            vector<int> v;
            for(int i = 1; i <= n; i++)
            {
                if(max(d[0][i], d[1][i]) == Min)
                    v.PB(i);
            }
            for(int i = 0; i < v.size(); i++)
                printf("%d%c", v[i], (i == v.size() - 1 ? '\n' : ' '));
        }
    }
} dij;

int main()
{
    int kase = 1;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        dij.init(n, m);
        dij.solve(kase++);
    }
    return 0;
}
