#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005
#define MAXE 1000005

class BCC
{
public:
    int head[MAXN];
    struct Edge
    {
        int to,next;
        Edge() {}
        Edge(int to,int next):to(to),next(next) {}
    } e[MAXE];

    int dfn[MAXN];
    int low[MAXN];
    int belong[MAXN];
    int cnt;
    int bcc_cnt;
    int dfs_clock;
    int par[MAXN];
    int pre[MAXN];
    int ans;
    int n,m;

    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = 0;
        ans = 0;
        memset(dfn,0,sizeof(dfn));
        memset(head,-1,sizeof(head));
        memset(pre,0,sizeof(pre));
        for(int i=1; i<=n; i++)
            par[i] = i;
    }

    void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    int findset(int x)
    {
        return x==par[x]?par[x]:par[x]=findset(par[x]);
    }

    void unionset(int x,int y)
    {
        int xx = findset(x);
        int yy = findset(y);
        if(xx!=yy)
            par[xx] = yy;
    }

    void tarjan(int u,int fa)
    {
        low[u] = dfn[u] = ++dfs_clock;
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(v==fa) continue;
            if(!dfn[v])
            {
                pre[v] = u;
                tarjan(v,u);
                low[u] = min(low[u],low[v]);
                if(low[v]>dfn[u])
                    ans++;
                else
                    unionset(u,v);
            }
            else if(dfn[v]<dfn[u])
                low[u] = min(low[u],dfn[v]);
        }
    }

    void lca(int u,int v)
    {
        if(dfn[u]>dfn[v])
            swap(u,v);
        while(dfn[v]>dfn[u])
        {
            if(findset(v)!=findset(pre[v])) //加新边以后形成环，原来的桥失去桥的性质
            {
                unionset(v,pre[v]);
                ans--;
            }
            v = pre[v];  //继续向上回溯
        }
        while(u!=v)
        {
            if(findset(u)!=findset(pre[u]))
            {
                unionset(u,pre[u]);
                ans--;
            }
            u = pre[u];
        }
    }

    void solve(int kase)
    {
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        tarjan(1,-1);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",kase);
        while(q--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            lca(u,v);
            printf("%d\n",ans);
        }
    }
} bcc;

int main()
{
    int kase=1;
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        bcc.init(n,m);
        bcc.solve(kase++);
    }
    return 0;
}
