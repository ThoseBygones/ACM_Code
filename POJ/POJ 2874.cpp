#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define PB push_back
#define MAXN 10001
#define MAXQ 1000001

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
    int head2[MAXN];
    int dep[MAXN];
    int fa[MAXN];
    int vis[MAXN];
    int ans[MAXQ];
    int cnt,cnt2;
    int n,m,q;

    void addEdge(int u,int v,int w)
    {
        e[cnt].to = v;
        e[cnt].cost = w;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    void addEdge2(int u,int v)
    {
        qry[cnt2].v = v;
        qry[cnt2].next = head2[u];
        head2[u] = cnt2++;
    }

    struct Query
    {
        int u,v;
        int next;
    } qry[MAXQ<<1];

    void init(int n,int m,int q)
    {
        this -> n = n;
        this -> m = m;
        this -> q = q;
        cnt = cnt2 = 0;
        memset(ans,-1,sizeof(ans));
        for(int i = 1; i<=n; i++)
        {
            head[i] = -1;
            head2[i] = -1;
            fa[i] = i;
            vis[i] = 0;
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

    void dfs(int u,int d,int rt)
    {
        dep[u] = d;
        vis[u] = rt;
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!vis[v])
            {
                dfs(v,d+e[i].cost,rt);
                fa[findset(v)] = findset(u);
            }
        }
        for(int i = head2[u]; ~i; i = qry[i].next)
        {
            int v = qry[i].v;
            if(vis[v]==rt)
            {
                int lca = findset(v);
                ans[i/2] = treeDis(u,v,lca);  //输入需要记录的查询内容
            }
        }
    }

    void buildGraph()
    {
        for(int i = 0; i<m; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            addEdge(u,v,w);
            addEdge(v,u,w);
        }
    }

    void initQuery()
    {
        for(int i = 0; i<q; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            addEdge2(u,v);
            addEdge2(v,u);
        }
    }

    void solve()
    {
        buildGraph();
        initQuery();
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
                dfs(i,0,i);
        }
        for(int i=0; i<q; i++)
        {
            if(~ans[i])
                printf("%d\n",ans[i]);
            else
                puts("Not connected");
        }
    }
} lca_tarjan;

int main()
{
    int n,m,q;
    while(~scanf("%d%d%d",&n,&m,&q))
    {
        lca_tarjan.init(n,m,q);
        lca_tarjan.solve();
    }
    return 0;
}
