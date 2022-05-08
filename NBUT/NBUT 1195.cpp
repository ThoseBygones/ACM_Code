/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-07
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: NBUT
 *  Algorithm: 最大流Dinic算法
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

const int MAXN = 20;
const int MAXE = 2005;

class Dinic
{
private:
    int d[MAXN];
    int head[MAXN], nxt[MAXE], cur[MAXN];
    struct Edge
    {
        int from, to, cap, flow;
        Edge(int from, int to, int cap, int flow) : from(from), to(to), cap(cap), flow(flow) {}
        Edge() {}
    } e[MAXE];

    int s, t, cnt;
    int n, m;
    int node;

    bool bfs()
    {
        for(int i = 0; i <= node; i++)
            d[i] = -1;
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(int i = head[x]; ~i; i = nxt[i])
            {
                Edge &ed = e[i];
                if(d[ed.to] == -1 && ed.cap > ed.flow)
                {
                    d[ed.to] = d[x] + 1;
                    q.push(ed.to);
                }
            }
        }
        return d[t] != -1;
    }
    int dfs(int x,int a)
    {
        if(x == t || a == 0) return a;
        int flow = 0, f;
        for(; ~cur[x]; cur[x] = nxt[cur[x]])
        {
            Edge &ed = e[cur[x]];
            if(d[ed.to] == d[x] + 1 && (f = dfs(ed.to, min(ed.cap - ed.flow,a))) > 0)
            {
                flow += f;
                ed.flow += f;
                e[cur[x] ^ 1].flow -= f;
                a -= f;
                if(a == 0)
                    break;
            }
        }
        return flow;
    }

    void addEdge(int from, int to, int cap)
    {
        e[cnt] = Edge(from, to, cap, 0);
        int tmp = head[from];
        head[from] = cnt;
        nxt[cnt++] = tmp;
        e[cnt] = Edge(to, from, 0, 0);
        tmp = head[to];
        head[to] = cnt;
        nxt[cnt++] = tmp;
    }
public:
    void init(int n,int m)
    {
        cnt = 0;
        this -> n = n;
        this -> m = m;
    }

    int maxFlow()
    {
        int flow = 0;
        while(bfs())
        {
            for(int i = 0; i <= node; i++)
                cur[i] = head[i];
            flow += dfs(s, INF);
        }
        return flow;
    }

    void buildGraph()
    {
        memset(head, -1, sizeof(head));
        s = 1;
        t = n;
        node = t;
        for(int i = 0; i < m; i++)
        {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            addEdge(u, v, c);
        }
    }

    void solve(int kase)
    {
        buildGraph();
        printf("Case %d: %d\n", kase, maxFlow());
    }
} dinic;

int main()
{
    int t, kase = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        dinic.init(n, m);
        dinic.solve(kase++);
    }
    return 0;
}
