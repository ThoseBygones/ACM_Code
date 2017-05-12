#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 5005
#define MAXE 100005
#define INF 0x3f3f3f3f

class MCMF
{
public:
    typedef int CostType;
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
    int n,k;
    int mat[55][55];

    void init(int a,int b)
    {
        cnt = 0;
        n = a;
        k = b;
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

    int maxFlow()
    {
        int flow = 0;
        CostType cost = 0;
        while(spfa(flow,cost));
        //return flow;
        return cost;
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        node = 2 * n * n + 2;
        s = 0,t = 2 * n * n + 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                scanf("%d",&mat[i][j]);
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                int u=(i-1)*n+j;    //拆点：入点
                int v=u+n*n;    //拆点：出点
                addEdge(u,v,1,-mat[i][j]);   //连一条流量为1，费用为该点的权值的负值的边
                addEdge(u,v,INF,0); //再连一条流量为INF，费用为0的边（保证该点的权值只能被取一次
                if(i<n) //向下有可以连接的点
                    addEdge(v,u+n,INF,0);
                if(j<n)
                    addEdge(v,u+1,INF,0);
            }
        }
        addEdge(s,1,k,0);
        addEdge(2*n*n,t,k,0);
    }
} mcmf;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    mcmf.init(n,k);
    mcmf.buildGraph();
    int ans=mcmf.maxFlow();
    printf("%d\n",-ans);
    return 0;
}
