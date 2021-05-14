/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-14
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 最短路 dijkstra + 枚举
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

const int MAXN = 1005;
const int MAXE = (MAXN * MAXN);

typedef int Type;

class Dijkstra
{
public:
    int head[MAXN], nxt[MAXE], cnt;
    Type d[MAXN][MAXN];
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
    int n, m, k;

    int u[MAXN], v[MAXN], w[MAXN], a[MAXN], b[MAXN];

    //初始化，n为点数，m为边数
    void init(int n, int m, int k)
    {
        this -> n = n;
        this -> m = m;
        this -> k = k;
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
        for(int i = 0; i <= n; i++)
        {
            d[s][i] = INF;
            vis[i] = false;
        }
        d[s][s] = 0;
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
                if(!vis[ee.v] && d[s][ee.v] > d[s][ed.v] + ee.cost)
                {
                    d[s][ee.v] = d[s][ed.v] + ee.cost;
                    /*
                     *  最短路树
                    	p[ee.v] = MP(u,i);
                    */
                    q.push(Edge(ee.v, d[s][ee.v]));
                }
            }
        }
    }

    void buildGraph()
    {
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            addEdge(u[i], v[i], w[i]);
            addEdge(v[i], u[i], w[i]);
        }
    }

    void solve()
    {
        buildGraph();   //建图
        for(int i = 1; i <= n; i++) //对每个点跑一次dijkstra
            dijkstra(i);
        for(int i = 0; i < k; i++)
            scanf("%d%d", &a[i], &b[i]);
        int ans = INF;
        for(int i = 0; i < m; i++)
        {
            int sum = 0;
            for(int j = 0; j < k; j++)
                sum += min(d[a[j]][b[j]], min(d[a[j]][u[i]] + d[v[i]][b[j]], d[a[j]][v[i]] + d[u[i]][b[j]]));   //枚举变为0的那条边
            ans = min(sum, ans);
        }
        printf("%d\n", ans);
    }
} dij;

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    dij.init(n, m, k);
    dij.solve();
    return 0;
}
