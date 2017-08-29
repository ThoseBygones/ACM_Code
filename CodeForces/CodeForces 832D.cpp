//LCA在线倍增
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define MAXE 1000005

class Tree
{
public:
    int head[MAXN],nxt[MAXE],e[MAXE];
    int cnt;

    void init(int n)
    {
        cnt = 0;
        for(int i = 0; i<=n; i++) head[i] = -1;
        this->n = n;
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
            int offset = dep[v]-dep[u];
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

    int dis(int u,int v)
    {
        return dep[u]+dep[v]-2*dep[LCA(u,v)];
    }
} lca;

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    lca.init(n);
    for(int i=2; i<=n; i++)
    {
        int x;
        scanf("%d",&x);
        lca.addEdge(i,x);
        lca.addEdge(x,i);
    }
    lca.dfs(1,0,1);
    while(q--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int x=lca.LCA(a,b);
        int y=lca.LCA(a,c);
        int z=lca.LCA(b,c);
        int ans=lca.dep[x]>lca.dep[y]?x:y;
        ans=lca.dep[ans]>lca.dep[z]?ans:z;
        printf("%d\n",max(lca.dis(ans,a),max(lca.dis(ans,b),lca.dis(ans,c)))+1);
    }
    return 0;
}
