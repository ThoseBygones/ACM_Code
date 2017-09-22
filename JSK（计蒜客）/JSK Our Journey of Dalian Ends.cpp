#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define MAXN 10005
#define MAXE 100005
#define INF 1e9

class MCMF
{
public:
    typedef int CostType;
    struct Rec
    {
        int u;
        int v;
        int w;
        Rec(int u,int v,int w):u(u),v(v),w(w) {}
        Rec() {}
    } rec[MAXN];

    struct Edge
    {
        int from,to,cap,flow;
        CostType cost;
        Edge(int from,int to,int cap,int flow,CostType cost):from(from),to(to),cap(cap),flow(flow),cost(cost) {}
        Edge() {}
    } e[MAXE];

    int head[MAXN],nxt[MAXE],a[MAXN],p[MAXN];
    bool inq[MAXN];
    CostType d[MAXN];
    int cnt,s,t;
    int node;
    int n,m;
    int id;

    map <string,int> city;

    void init(int m)
    {
        cnt = 0;
        id = 0;
        city.clear();
        this -> m = m;
    }

    void addEdge(int from,int to,int cap,CostType cost)
    {
        e[cnt] = Edge(from,to,cap,0,cost);
        int tmp = head[from];
        head[from] = cnt;
        nxt[cnt++] = tmp;
        e[cnt] = Edge(to,from,0,0,-cost);
        tmp = head[to];
        head[to] = cnt;
        nxt[cnt++] = tmp;
    }

    bool spfa(int &flow,CostType &cost)
    {
        for(int i = 0; i<=node; i++)
        {
            d[i] = INF;
            inq[i] = false;
        }
        d[s] = 0,inq[s] = true,p[s] = 0,a[s] = INF;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for(int i = head[u]; ~i; i = nxt[i])
            {
                Edge &ed = e[i];
                if(ed.cap>ed.flow&&d[ed.to]>d[u]+ed.cost)
                {
                    d[ed.to] = d[u]+ed.cost;
                    p[ed.to] = i;
                    a[ed.to] = min(a[u],ed.cap-ed.flow);
                    if(!inq[ed.to])
                    {
                        inq[ed.to] = true;
                        q.push(ed.to);
                    }
                }
            }
        }
        if(d[t]==INF) return false;
        flow+=a[t];
        cost+=d[t]*a[t];
        int u = t;
        while(u!=s)
        {
            e[p[u]].flow+=a[t];
            e[p[u]^1].flow-=a[t];
            u = e[p[u]].from;
        }
        return true;
    }

    CostType maxFlow()
    {
        int flow = 0;
        CostType cost = 0;
        while(spfa(flow,cost));
        //return flow;
        return flow==2?cost:-1;
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        for(int i=1; i<=m; i++)
        {
            string u,v;
            int w;
            cin >> u >> v >> w;
            if(!city[u])
                city[u] = ++id;
            if(!city[v])
                city[v] = ++id;
            rec[i].u = city[u];
            rec[i].v = city[v];
            rec[i].w = w;
        }
        int dl = city["Dalian"];
        int xa = city["Xian"];
        int sh = city["Shanghai"];
        s = 0;
        t = 2 * id + 1;
        node = t;
        addEdge(s,dl,1,0);
        addEdge(s,xa,1,0);
        addEdge(sh+id,t,2,0);
        for(int i=1; i<=m; i++)
        {
            addEdge(rec[i].u+id, rec[i].v, INF, rec[i].w);
            addEdge(rec[i].v+id, rec[i].u, INF, rec[i].w);
        }
        for(int i=1; i<=id; i++)
        {
            if(i==sh)
                addEdge(i,i+id,2,0);
            else
                addEdge(i,i+id,1,0);
        }
    }
} mcmf;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m;
        scanf("%d",&m);
        mcmf.init(m);
        mcmf.buildGraph();
        int ans=mcmf.maxFlow();
        printf("%d\n",ans);
    }
    return 0;
}

/*
3
2
Dalian Shanghai 3
Shanghai Xian 4
5
Dalian Shanghai 7
Shanghai Nanjing 1
Dalian Nanjing 3
Nanjing Xian 5
Shanghai Xian 8
3
Dalian Nanjing 6
Shanghai Nanjing 7
Nanjing Xian 8
*/
/*
7
12
-1
*/
