#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 1005
#define MAXM 100005
#define MAXE 1000005
#define INF 0x3f3f3f3f

typedef int Type;

int a[MAXM],b[MAXM],c[MAXM];

class Dijkstra
{
public:
    int head[MAXN],nxt[MAXE],cnt;
    Type d[MAXN][2];
    struct Edge
    {
        int v;
        Type cost;
        Edge() {}
        Edge(int v,Type cost):v(v),cost(cost) {}
        bool operator<(const Edge& ed) const
        {
            return cost>ed.cost;
        }
    } e[MAXE];
    bool vis[MAXN];

    //初始化，n为点数
    void init(int n)
    {
        cnt = 0;
        for(int i = 0; i<=n; i++) head[i] = -1;
    }

    inline void addEdge(int u,int v,Type cost)
    {
        e[cnt] = Edge(v,cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    Type dijkstra(int s,int t,int n,int flag)
    {
        for(int i = 0; i<=n; i++) d[i][flag] = INF,vis[i] = false;
        d[s][flag] = 0;
        priority_queue<Edge> q;
        q.push(Edge(s,0));
        while(!q.empty())
        {
            Edge ed = q.top();
            q.pop();
            vis[ed.v] = true;
            if(ed.v==t) return d[t][flag];
            for(int i = head[ed.v]; ~i; i = nxt[i])
            {
                Edge ee = e[i];
                if(!vis[ee.v]&&d[ee.v][flag]>d[ed.v][flag]+ee.cost)
                {
                    d[ee.v][flag] = d[ed.v][flag]+ee.cost;
                    /*
                     *  最短路树
                    	p[ee.v] = MP(u,i);
                    */
                    q.push(Edge(ee.v,d[ee.v][flag]));
                }
            }
        }
        return d[t][flag];
    }
} dij;


class Dinic
{
private:
    int d[MAXN];
    int head[MAXN],nxt[MAXE],cur[MAXN];
    struct Edge
    {
        int from,to,cap,flow;
        Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow) {}
        Edge() {}
    } e[MAXE];

    int s,t,cnt;
    int n,m;
    int node;
    int A,B;

    bool bfs()
    {
        for(int i = 0; i<=node; i++) d[i] = -1;
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(int i = head[x]; ~i; i = nxt[i])
            {
                Edge &ed = e[i];
                if(d[ed.to]==-1&&ed.cap>ed.flow)
                {
                    d[ed.to] = d[x]+1;
                    q.push(ed.to);
                }
            }
        }
        return d[t]!=-1;
    }
    int dfs(int x,int a)
    {
        if(x==t||a==0) return a;
        int flow = 0,f;
        for(; ~cur[x]; cur[x] = nxt[cur[x]])
        {
            Edge &ed = e[cur[x]];
            if(d[ed.to]==d[x]+1&&(f = dfs(ed.to,min(ed.cap-ed.flow,a)))>0)
            {
                flow+=f;
                ed.flow+=f;
                e[cur[x]^1].flow-=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }

    void addEdge(int from,int to,int cap)
    {
        e[cnt] = Edge(from,to,cap,0);
        int tmp = head[from];
        head[from] = cnt;
        nxt[cnt++] = tmp;
        e[cnt] = Edge(to,from,0,0);
        tmp = head[to];
        head[to] = cnt;
        nxt[cnt++] = tmp;
    }
public:
    void init(int n,int m,int A,int B)
    {
        cnt = 0;
        this -> n = n;
        this -> m = m;
        this -> A = A;
        this -> B = B;
    }

    int maxFlow()
    {
        int flow = 0;
        while(bfs())
        {
            for(int i = 0; i<=node; i++) cur[i] = head[i];
            flow+=dfs(s,INF);
        }
        return flow;
    }

    void buildGraph()
    {
        s = A;
        t = B;
        node = n;
        for(int i = 0; i<=node; i++) head[i] = -1;
        for(int i=0; i<m; i++)
        {
            if(dij.d[a[i]][0]+c[i]+dij.d[b[i]][1]==dij.d[t][0])
                addEdge(a[i],b[i],1);
        }
    }

    void solve()
    {
        buildGraph();
        int ans=maxFlow();
        printf("%d\n",ans);
    }
} dinic;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        int A,B;
        scanf("%d%d",&A,&B);
        dij.init(n);
        for(int i=0; i<m; i++)
        {
            if(a[i]==b[i]) continue;
            dij.addEdge(a[i],b[i],c[i]);
        }
        dij.dijkstra(A,B,n,0);
        dij.init(n);
        for(int i=0; i<m; i++)
        {
            if(a[i]==b[i]) continue;
            dij.addEdge(b[i],a[i],c[i]);
        }
        dij.dijkstra(B,A,n,1);
        dinic.init(n,m,A,B);
        dinic.solve();
    }
    return 0;
}
