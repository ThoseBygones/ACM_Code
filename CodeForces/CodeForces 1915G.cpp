/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-02-20
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 分层图最短路
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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

typedef LL Type;

const int MAXN = 1005;
const int MAXE = MAXN  << 1;

class Dijkstra
{
public:
    int head[MAXN], nxt[MAXE], cnt;
    Type d[MAXN][MAXN]; //d[i][j]表示到达i点使用减速系数为j的自行车的最短距离
    struct Edge
    {
        int v, sf;
        Type cost;
        Edge() {}
        Edge(int v, Type cost) : v(v), cost(cost) {}
        Edge(int v, Type cost, int sf) : v(v), cost(cost), sf(sf) {}
        bool operator < (const Edge& ed) const
        {
            return cost > ed.cost;
        }
    } e[MAXE];
    bool vis[MAXN][MAXN];   //vis[i][j]表示是否使用过减速系数为j的自行车到达i点
    int sf[MAXN];    //sf[i]表示第i辆自行车的减速系数
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

    void dijkstra(int s)
    {
        memset(d, 0x3f, sizeof(d));
        memset(vis, false, sizeof(vis));
        d[s][sf[s]] = 0;
        priority_queue<Edge> q;
        q.push(Edge(s, 0, sf[s]));
        while(!q.empty())
        {
            Edge ed = q.top();
            q.pop();
            if(vis[ed.v][ed.sf])   //没有该判断会TLE
                continue;
            vis[ed.v][ed.sf] = true;
            for(int i = head[ed.v]; ~i; i = nxt[i])
            {
                Edge ee = e[i];
                if(d[ee.v][ed.sf] > ed.cost + ee.cost * ed.sf)  //选择到达ed.v最优边ed.cost来往下迭代
                {
                    d[ee.v][ed.sf] = ed.cost + ee.cost * ed.sf;
                    q.push(Edge(ee.v, d[ee.v][ed.sf], ed.sf));  //继续使用之前用的自行车
                    q.push(Edge(ee.v, d[ee.v][ed.sf], sf[ee.v]));   //在该点买新的自行车
                }
            }
        }
    }

    void buildGraph()
    {
        scanf("%d%d", &n, &m);
        init(n, m);
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        for(int i = 1; i <= n; i++)
            scanf("%d", &sf[i]);
    }

    void solve()
    {
        buildGraph();   //建图
        dijkstra(1);
        LL ans = LINF;
        for(int i = 1; i <= n; i++)
            ans = min(ans, d[n][sf[i]]);
        printf("%lld\n", ans);
    }
} dij;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        dij.solve();
    return 0;
}
