#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 105
#define MAXE 5005
#define INF 0x3f3f3f3f

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
    int u[MAXE],v[MAXE];

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
    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
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

    void buildGraph(int s,int t)
    {
        cnt = 0;
        memset(head,-1,sizeof(head));
        this -> s = s;
        this -> t = t + n;
        for(int i=0; i<n; i++)
        {
            if(i==s || i==t)
                addEdge(i,i+n,INF);
            else
                addEdge(i,i+n,1);
        }
        for(int i=0; i<m; i++)
        {
            addEdge(u[i]+n,v[i],INF);
            addEdge(v[i]+n,u[i],INF);
        }
    }

    void solve()
    {
        int ans=INF;
        node = n * 2;
        for(int i=0; i<m; i++)
            scanf(" (%d,%d)",&u[i],&v[i]);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                    buildGraph(i,j);
                    ans=min(ans,maxFlow());
                }

            }
        }
        printf("%d\n",ans==INF?n:ans);
    }
} dinic;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        dinic.init(n,m);
        dinic.solve();
    }
    return 0;
}
