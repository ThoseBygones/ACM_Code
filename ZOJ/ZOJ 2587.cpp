#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 1605
#define MAXE 50010
#define INF 0x3f3f3f3f

class Dinic
{
private:
    int d[MAXN];
    int head[MAXN],nxt[MAXE],cur[MAXN];
    int vis1[MAXN];
    int vis2[MAXN];
    struct Edge
    {
        int from,to,cap,flow;
        Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow) {}
        Edge() {}
    } e[MAXE];

    int s,t,cnt;
    //int node;
    bool bfs(int n)
    {
        for(int i = 0; i<=n; i++)
            d[i] = -1;
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
        if(x==t||a==0)
            return a;
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
                if(a==0)
                    break;
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
    int cnt1,cnt2;

    void init()
    {
        cnt = 0;
        cnt1 = 0;
        cnt2 = 0;
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
    }

    int maxFlow(int n)
    {
        int flow = 0;
        while(bfs(n))
        {
            for(int i = 0; i<=n; i++)
                cur[i] = head[i];
            flow+=dfs(s,INF);
        }
        return flow;
    }

    void buildGraph(int n,int m,int a,int b)
    {
        s = a;
        t = b;
        for(int i = 0; i<=n; i++)
            head[i] = -1;
        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
            addEdge(v,u,w);
        }
    }

    void dfs1(int x)   //从源点开始搜索
    {
        vis1[x]=1;
        cnt1++;
        for(int i = head[x]; ~i; i = nxt[i])
        {
            //cout << i << " " << e[i].from << "->" << e[i].to << "=" << e[i].cap << endl;
            if(!vis1[e[i].to] && e[i].cap>e[i].flow)
                dfs1(e[i].to);
        }
    }

    void dfs2(int x)   //从汇点开始搜索
    {
        vis2[x]=1;
        cnt2++;
        for(int i = head[x]; ~i; i = nxt[i])
        {
            //Edge &ed = e[i];
            //Edge &ee = e[i^1];
            if(!vis2[e[i].to] && e[i^1].cap>e[i^1].flow)
                dfs2(e[i].to);
        }
    }
} dinic;

int main()
{
    int n,m,A,B;
    while(~scanf("%d%d%d%d",&n,&m,&A,&B))
    {
        if(n==0 && m==0 && A==0 && B==0)
            break;
        dinic.init();
        dinic.buildGraph(n,m,A,B);
        int ans=dinic.maxFlow(n);
        //cout << ans << endl;
        dinic.dfs1(A);
        dinic.dfs2(B);
        //cout << dinic.cnt1 << " " << dinic.cnt2 << endl;
        if(dinic.cnt1+dinic.cnt2==n)
            puts("UNIQUE");
        else
            puts("AMBIGUOUS");
    }
    return 0;
}
