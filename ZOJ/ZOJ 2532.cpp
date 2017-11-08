#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 205
#define MAXE 20005
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
    int n,m,l;
    int node;
    int vis[MAXN][2];

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

    void dfs2(int u,int flag)
    {
        vis[u][flag] = 1;
        for(int i = head[u]; ~i; i = nxt[i])
        {
            int v = e[i].to;
            //cout << e[i^flag].cap-e[i^flag].flow << endl;
            if(!vis[v][flag] && e[i^flag].cap-e[i^flag].flow!=0) //不是满流边则继续搜索
                dfs2(v,flag);
        }
    }
public:
    void init(int n,int m,int l)
    {
        cnt = 0;
        this -> n = n;
        this -> m = m;
        this -> l = l;
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
        s = n + m + 1;
        t = 0;
        node = n + m + 1;
        for(int i = 0; i<=node; i++) head[i] = -1;
        for(int i=0; i<l; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
        }
        for(int i=1; i<=n; i++)
            addEdge(s,i,INF);
    }

    void solve()
    {
        buildGraph();
        int val = maxFlow();
        //cout << val << endl;
        memset(vis,0,sizeof(vis));
        dfs2(s,0);
        dfs2(t,1);
        vector <int> ans;
        for(int i=0; i<l; i++)
        {
            int u=e[i<<1].from;
            int v=e[i<<1].to;
            //cout << e[i<<1].cap << " * " << e[i<<1].flow << endl;
            //cout << vis[u][0] << "^" << vis[v][1] <<endl;
            if(e[i<<1].cap==e[i<<1].flow && vis[u][0] && vis[v][1])
                ans.push_back(i+1);
        }
        int sz=ans.size();
        if(sz)
        {
            for(int i=0; i<sz; i++)
            {
                if(i)
                    printf(" %d",ans[i]);
                else
                    printf("%d",ans[i]);
            }
        }
        puts("");
    }
} dinic;

int main()
{
    int n,m,l;
    while(~scanf("%d%d%d",&n,&m,&l))
    {
        if(n==0 && m==0 && l==0)
            break;
        dinic.init(n,m,l);
        dinic.solve();
    }
}
