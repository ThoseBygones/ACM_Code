/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-15
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 最短路 dijkstra
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

#define MAXN 1005
#define MAXE 20005

typedef int Type;

class Dijkstra
{
public:
    int head[MAXN],nxt[MAXE],cnt;
    Type d[MAXN];
    struct Edge
    {
        int v;
        Type cost;
        Edge() {}
        Edge(int v,Type cost):v(v),cost(cost) {}
        bool operator <(const Edge& ed) const
        {
            return cost > ed.cost;
        }
    } e[MAXE];
    bool vis[MAXN];
    int n,m;

    //初始化，n为点数，m为边数
    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = 0;
        memset(head,-1,sizeof(head));
    }

    inline void addEdge(int u,int v,Type cost)
    {
        e[cnt] = Edge(v,cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    //void dijkstra(int s)
    Type dijkstra(int s,int t)
    {
        for(int i = 0; i<=n; i++)
            d[i] = INF,vis[i] = false;
        d[s] = 0;
        priority_queue<Edge> q;
        q.push(Edge(s,0));
        while(!q.empty())
        {
            Edge ed = q.top();
            q.pop();
            if(vis[ed.v])   //没有该判断会TLE
                continue;
            vis[ed.v] = true;
            //if(ed.v == t)
            //    return d[t];
            for(int i = head[ed.v]; ~i; i = nxt[i])
            {
                Edge ee = e[i];
                if(!vis[ee.v] && d[ee.v] > d[ed.v] + ee.cost)
                {
                    d[ee.v] = d[ed.v] + ee.cost;
                    /*
                     *  最短路树
                    	p[ee.v] = MP(u,i);
                    */
                    q.push(Edge(ee.v,d[ee.v]));
                }
            }
        }
        return d[t] == INF ? -1 : d[t];
    }
} dij;

int main()
{
    int n, m, s;
    while(~scanf("%d%d%d", &n, &m, &s))
    {
        dij.init(n, m);
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            dij.addEdge(u, v, w);
        }
        int k;
        scanf("%d", &k);
        while(k--)
        {
            int x;
            scanf("%d", &x);
            dij.addEdge(0, x, 0);
        }
        printf("%d\n", dij.dijkstra(0, s));
    }
    return 0;
}
