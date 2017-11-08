#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define PB push_back
#define MAXN 1005
#define MAXQ 100005

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
    int ind[MAXN];
    int ans[MAXQ];
    int cnt;
    int n,q;

    void addEdge(int u,int v,int w)
    {
        e[cnt].to = v;
        e[cnt].cost = w;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    int qry[MAXN][MAXN];

    void init(int n)
    {
        this -> n = n;
        cnt = 0;
        for(int i = 1; i<=n; i++)
        {
            head[i] = -1;
            fa[i] = i;
            vis[i] = false;
            ind[i] = 0;
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
        for(int v = 1; v<=n; v++)
        {
            if(vis[v] && qry[u][v])
            {
                int lca = findset(v);
                ans[lca] += qry[u][v];
                qry[u][v] = qry[v][u] = 0;
            }
        }
    }

    void buildGraph()
    {
        for(int i = 1; i<=n; i++)
        {
            int u,num,v;
            scanf("%d:(%d)",&u,&num);
            while(num--)
            {
                scanf("%d",&v);
                addEdge(u,v,1);
                addEdge(v,u,1);
                ind[v]++;
            }
        }
    }

    void initQuery()
    {
        for(int i=0; i<q; i++)
        {
            int u,v;
            scanf(" (%d,%d)",&u,&v);
            qry[u][v]++;
            qry[v][u]++;
        }
    }

    void solve()
    {
        buildGraph();
        memset(qry,0,sizeof(qry));
        scanf("%d",&q);
        initQuery();
        memset(ans,0,sizeof(ans));
        int root=1;
        for(int i=1; i<=n; i++)
        {
            if(!ind[i])
                root=i;
        }
        dfs(root,0);
        for(int i=1; i<=n; i++)
        {
            if(ans[i])
                printf("%d:%d\n",i,ans[i]);
        }
    }
} lca_tarjan;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        lca_tarjan.init(n);
        lca_tarjan.solve();
    }
    return 0;
}
