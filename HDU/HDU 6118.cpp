#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define MAXN 510
#define MAXM 2010
#define LL long long
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MAXE 300005

class MCMF
{
public:
    typedef int CostType;
    struct Edge
    {
        int from,to,cap,flow;
        CostType cost;
        Edge(int from,int to,int cap,int flow,CostType cost) : from(from),to(to),cap(cap),flow(flow),cost(cost) {}
        Edge() {}
    } e[MAXE];

    int head[MAXM],nxt[MAXE],a[MAXM],p[MAXM];
    bool inq[MAXM];
    CostType d[MAXM];
    int cnt,s,t;
    int node;
    int n,m;
    int dis[MAXN][MAXN];
    int A[MAXN],B[MAXN],C[MAXN],D[MAXN];

    void init(int n,int m)
    {
        cnt = 0;
        this -> n = n;
        this -> m = m;
    }

    void floyd()
    {
        for(int k=1; k<=n; k++)
        {
            dis[k][k]=0;
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
        /*for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                cout << dis[i][j] << " ";
            cout << endl;
        }*/
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
        for(int i=1; i<=n; i++)
            scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
        memset(dis,INF,sizeof(dis));
        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            dis[u][v]=dis[v][u]=min(dis[u][v],w);
        }
        floyd();
        memset(head,-1,sizeof(head));
        s = 0;
        t = 4 * n + 1;
        node = t;
        for(int i=1; i<=n; i++)
        {
            addEdge(s,i,B[i],0);
            addEdge(i+n,t,D[i],0);
            for(int j=1; j<=n; j++)
            {
                if(C[j]-A[i]-dis[i][j]>0)   //注意，不加这句会TLE。亏本运输我们要排除，不然连边太多！
                    addEdge(i,j+n,INF,-(C[j]-A[i]-dis[i][j]));
            }
            addEdge(i,t,INF,0); //注意，不加这句WA。因为不一定最大流的时候费用最小
        }
    }
} mcmf;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        mcmf.init(n,m);
        mcmf.buildGraph();
        int ans=mcmf.maxFlow();
        printf("%d\n",-ans);
    }
    return 0;
}
