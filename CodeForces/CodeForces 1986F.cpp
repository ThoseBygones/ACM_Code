/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-04-29
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 边-双连通分量/桥
 ********************************************************************************
 *  Algo-Description:
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

const int MAXN = 100005;
const int MAXE = MAXN << 1;

class Edge_BCC
{
public:
    int head[MAXN];
    struct Edge
    {
        int to, next;
        Edge() {}
        Edge(int to, int next) : to(to), next(next) {}
    } e[MAXE];

    int bridge[MAXE];
    int dfn[MAXN], low[MAXN], belong[MAXN];
    int sz[MAXN];
    int cnt;
    int bcc_cnt, dfs_clock;

    int n, m;
    LL ans;

    void init(int n, int m)
    {
        cnt = 0;
        this -> n = n;
        this -> m = m;
        for(int i = 0; i <= n; i++)
            head[i] = -1;
        for(int i = 0; i <= n; i++)
            dfn[i] = 0;
        for(int i = 0; i <= n; i++)
            sz[i] = 0;
        dfs_clock = bcc_cnt = 0;
    }

    void addEdge(int u, int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    void tarjan(int u, int fa)
    {
        low[u] = dfn[u] = ++dfs_clock;
        sz[u] = 1;
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(v == fa) continue;
            if(!dfn[v])
            {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                sz[u] += sz[v];   //累计连通分量内结点数量
                if(low[v] > dfn[u])
                    bridge[i] = bridge[i ^ 1] = true;
            }
            else if(dfn[v] < dfn[u])
                low[u] = min(low[u], dfn[v]);
        }
        if(low[u] == dfn[u])    //找到每个边-双联通分量的边界结点
        {
            LL sum = calc(sz[u]) + calc(n - sz[u]);
            ans = min(ans, sum);
        }
    }

    void dfs(int u, int fa)
    {
        belong[u] = bcc_cnt;
        for(int i = head[u]; ~i; i = e[i].next)
        {
            if(i == fa) continue;
            int v = e[i].to;
            if(!bridge[i] && !belong[v])
                dfs(v, i ^ 1);
        }
    }

    //找边-双连通分量
    void find_bcc()
    {
        for(int i = 0; i < cnt; i++)  //cnt是边数
            bridge[i] = false;
        for(int i = 1; i <= n; i++)
        {
            if(!dfn[i])
                tarjan(i, -1);
            belong[i] = 0;
        }
        //belong表示所属的边联通分量的id
        for(int i = 1; i <= n; i++)
        {
            if(!belong[i])
            {
                bcc_cnt++;
                dfs(i, -1);
            }
        }
    }

    void buildGraph()
    {
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
    }

    LL calc(int x)
    {
        return 1LL * x * (x - 1) / 2;
    }

    void solve(int n, int m)
    {
        init(n, m);
        buildGraph();
        ans = calc(n);
        find_bcc();
        printf("%lld\n", ans);
    }
} edge_bcc;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        edge_bcc.solve(n, m);
    }
    return 0;
}
