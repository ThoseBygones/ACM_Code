#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define PB push_back
#define MAXN 40005
#define MAXQ 10005

class LCA_Offline_Tarjan
{
public:
    struct Edge
    {
        int to,cost,next;
        Edge() {}
        Edge(int to,int cost,int next):to(to),cost(cost),next(next) {}
    } e[MAXN<<1];

    int head[MAXN];
    int dep[MAXN];
    int fa[MAXN];
    bool vis[MAXN];
    int ans[MAXQ];
    int cnt;
    int n,m,q;

    void addEdge(int u,int v,int w)
    {
        e[cnt].to = v;
        e[cnt].cost = w;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    struct Query
    {
        int idx;
        int u,v;
    };

    vector <Query> qry[MAXN];

    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = 0;
        for(int i = 1; i<=n; i++)
        {
            head[i] = -1;
            qry[i].clear();
            fa[i] = i;
            vis[i] = false;
        }
    }

    int findset(int u)
    {
        return u==fa[u]?u:fa[u] = findset(fa[u]);
    }

    int treeDis(int u,int v,int lca)
    {
        return dep[u] + dep[v] - 2 * dep[lca];
    }

    void dfs(int u,int d)
    {
        dep[u] = d;
        vis[u] = true;
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!vis[v])
            {
                dfs(v,d+e[i].cost);
                fa[findset(v)] = findset(u);
            }
        }
        int sz = qry[u].size();
        for(int i = 0; i<sz; i++)
        {
            int v = qry[u][i].v;
            if(vis[v])
            {
                int lca = findset(v);
                ans[qry[u][i].idx] = treeDis(u,v,lca);
            }
        }
    }

    void buildGraph()
    {
        for(int i = 0; i<m; i++)
        {
            int u,v,w;
            char ch;
            scanf("%d %d %d %c",&u,&v,&w,&ch);
            addEdge(u,v,w);
            addEdge(v,u,w);
        }
    }

    void initQuery()
    {
        for(int i = 0; i<q; i++)
        {
            Query query;
            scanf("%d %d",&query.u,&query.v);
            query.idx = i;
            qry[query.u].PB(query);
            swap(query.u,query.v);
			qry[query.u].PB(query);
        }
    }

    void solve()
    {
        buildGraph();
        scanf("%d",&q);
        initQuery();
        dfs(1,0);
        for(int i=0; i<q; i++)
            printf("%d\n",ans[i]);
    }
} lca_tarjan;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    lca_tarjan.init(n,m);
    lca_tarjan.solve();
    return 0;
}
