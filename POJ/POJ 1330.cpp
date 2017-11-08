//离线Tarjan算法
/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define PB push_back
#define MAXN 10005

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
    int ind[MAXN];  //求入度，以此得到真正的树根
    int ans;
    int cnt;
    int n;

    void addEdge(int u,int v,int w)
    {
        e[cnt].to = v;
        e[cnt].cost = w;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    struct Query
    {
        int u,v;
    };

    vector <Query> qry[MAXN];

    void init(int n)
    {
        this -> n = n;
        cnt = 0;
        for(int i = 1; i<=n; i++)
        {
            head[i] = -1;
            qry[i].clear();
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
        int sz = qry[u].size();
        for(int i = 0; i<sz; i++)
        {
            int v = qry[u][i].v;
            if(vis[v])
            {
                ans = findset(v);
                return ;
            }
        }
    }

    void buildGraph()
    {
        for(int i = 1; i<n; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            addEdge(u,v,1);
            addEdge(v,u,1);
            ind[v]++;
        }
    }

    void initQuery()
    {
        Query query;
        scanf("%d %d",&query.u,&query.v);
        qry[query.u].PB(query);
        swap(query.u,query.v);
        qry[query.u].PB(query);
    }

    void solve()
    {
        buildGraph();
        initQuery();
        int root=1;
        for(int i=1; i<=n; i++)
        {
            if(!ind[i])
                root=i;
        }
        dfs(root,0);
        printf("%d\n",ans);
    }
} lca_tarjan;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        lca_tarjan.init(n);
        lca_tarjan.solve();
    }
    return 0;
}
*/

//在线倍增算法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define MAXN 100005
#define MAXE 200005

class LCA_Online_Multiplication
{
public:


    int head[MAXN],nxt[MAXE],e[MAXE];
    int ind[MAXN];
    int cnt;

    void init(int n)
    {
        this -> n = n;
        cnt = 0;
        memset(head,-1,sizeof(head));
        memset(ind,0,sizeof(ind));
    }

    inline void addEdge(int u,int v)
    {
        e[cnt] = v;
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    int dep[MAXN];
    int p[MAXN][20];
    int n;

    void dfs(int u,int fa,int d)
    {
        dep[u] = d;
        p[u][0] = fa;
        for(int i = 1; (1<<i)<=n; i++)
        {
            if(~p[u][i-1]) p[u][i] = p[p[u][i-1]][i-1];
            else p[u][i] = -1;
        }
        for(int i = head[u]; ~i; i = nxt[i])
        {
            int v = e[i];
            if(v==fa) continue;
            dfs(v,u,d+1);
        }
    }

    int LCA(int u,int v)
    {
        if(dep[u]>dep[v]) swap(u,v);
        if(dep[u]<dep[v])
        {
            int offset = dep[v] - dep[u];
            for(int i = 0; (1<<i)<=n; i++) if(offset&(1<<i)) v = p[v][i];
        }
        if(u!=v)
        {
            for(int i = log2(n); i>=0; i--)
            {
                if(p[u][i]!=p[v][i])
                    u = p[u][i],v = p[v][i];
            }
            u = p[u][0],v = p[v][0];
        }
        return u;
    }

    //求树上两点距离
    int treeDis(int u,int v)
    {
        return dep[u] + dep[v] - 2 * dep[LCA(u,v)];
    }

    void buildGraph()
    {
        for(int i = 1; i<n; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
            ind[v]++;
        }
    }

    void solve()
    {
        buildGraph();
        int u,v;
        scanf("%d%d",&u,&v);
        int root=1;
        for(int i=1; i<=n; i++)
        {
            if(!ind[i])
                root=i;
        }
        dfs(root,-1,0);
        int ans=LCA(u,v);
        printf("%d\n",ans);
    }
} lca_multi;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        lca_multi.init(n);
        lca_multi.solve();
    }
    return 0;
}
