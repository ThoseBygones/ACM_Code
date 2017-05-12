#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 105
#define MAXE 2005
#define INF 1e7

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

    int n,m;
    int s,t,cnt;
    //int node;
    bool bfs()
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
    void init()
    {
        cnt = 0;
    }

    int maxFlow()
    {
        int flow = 0;
        while(bfs())
        {
            for(int i = 0; i<=n; i++)
                cur[i] = head[i];
            flow+=dfs(s,INF);
        }
        return flow;
    }

    void buildGraph()
    {
        scanf("%d%d",&n,&m);
        s = n;  //新建编号为n的点为超级源点
        t = m;  //要保护的房间为超级汇点
        for(int i = 0; i<=n; i++)
            head[i] = -1;
        for(int i=0; i<n; i++)
        {
            int num;
            char intru[3];  //是否有入侵者
            scanf("%s%d",intru,&num);
            if(intru[0]=='I')
                addEdge(s,i,INF);
            while(num--)
            {
                int v;
                scanf("%d",&v);
                addEdge(i,v,INF);   //控制面板在房间内，流量为INF
                addEdge(v,i,1); //控制面板不在房间内，流量为1
            }
        }
    }
} dinic;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        dinic.init();
        dinic.buildGraph();
        int ans=dinic.maxFlow();
        if(ans>=INF)
            puts("PANIC ROOM BREACH");
        else
            printf("%d\n",ans);
    }
    return 0;
}
