/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-01
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 分层图最短路
 ********************************************************************************
 *  Algo-Description:
 * > 分层图最短路
 * > 分层定义如下：
 *   > 第一层（1 ~ n）：还没有把最大边的边权值变0，也没有把最小边的边权值double
 *   > 第二层（n + 1 ~ 2 * n）：把最大边的边权值变0，但还没有把最小边的边权值double
 *   > 第三层（2 * n + 1 ~ 3 * n）：还没有把最大边的边权值变0，但把最小边的边权值double
 *   > 第四层（3 * n + 1 ~ 4 * n）：把最大边的边权值变0，也把最小边的边权值double
 ********************************************************************************
 */

#include <bits/stdc++.h>
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

const int MAXN = 200010 << 2;
const int MAXE = 200010 * 9;

typedef LL Type;

class Dijkstra
{
public:
    int head[MAXN], nxt[MAXE << 1], cnt;
    Type d[MAXN];
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
    } e[MAXE << 1];
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

    void dijkstra(int s)
    {
        for(int i = 0; i <= 4 * n; i++)
        {
            d[i] = LINF;
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
                    q.push(Edge(ee.v, d[ee.v]));
                }
            }
        }
    }

    void buildGraph()
    {
        for(int i = 0; i < m; i++)
        {
            int u, v;
            LL w;
            scanf("%d%d%lld", &u, &v, &w);

            /* 分层建图 */

            /* 同一层内的转移 */
            //第一层内的转移
            addEdge(u, v, w);
            addEdge(v, u, w);
            //第二层内的转移
            addEdge(u + n, v + n, w);
            addEdge(v + n, u + n, w);
            //第三层内的转移
            addEdge(u + 2 * n, v + 2 * n, w);
            addEdge(v + 2 * n, u + 2 * n, w);
            //第四层内的转移
            addEdge(u + 3 * n, v + 3 * n, w);
            addEdge(v + 3 * n, u + 3 * n, w);

            /* 删除最大边边权值的转移 */
            //第一层到第二层的转移
            addEdge(u, v + n, 0);
            addEdge(v, u + n, 0);
            //第三层到第四层的转移
            addEdge(u + 2 * n, v + 3 * n, 0);
            addEdge(v + 2 * n, u + 3 * n, 0);

            /* 最小边边权值double的转移 */
            //第一层到第三层的转移
            addEdge(u, v + 2 * n, w * 2);
            addEdge(v, u + 2 * n, w * 2);
            //第二层到第四层的转移
            addEdge(u + n, v + 3 * n, w * 2);
            addEdge(v + n, u + 3 * n, w * 2);

            /* 某条边既当做最小边又当做最大边最后删了又补上的转移 */
            //第一层到第四层的转移
            addEdge(u, v + 3 * n, w);
            addEdge(v, u + 3 * n, w);
        }
    }

    void solve()
    {
        buildGraph();   //建图
        dijkstra(1);
        for(int i = 2; i <= n; i++)
            printf("%lld%c", d[i + 3 * n], (i == n ? '\n' : ' '));
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
