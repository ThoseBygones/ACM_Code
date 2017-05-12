#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 105
#define MAXE 10010
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
    //int node;
    int n,m,k;
    int ord[MAXN][MAXN];  //the amount of goods each shopkeeper needs
    int sup[MAXN][MAXN];  //the amount of goods stored in that supply place
    int c[MAXN][MAXN][MAXN];  //the cost to transport one unit of k-th goods from the j-th supply place to the i-th shopkeeper
    int ordersum[MAXN],supsum[MAXN];
    bool flag;

    void init()
    {
        cnt = 0;
        memset(head,-1,sizeof(head));
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
        for(int i = 0; i<=t; i++)
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

    void buildGraph(int x,int y,int z)
    {
        n=x;
        m=y;
        k=z;
        memset(ordersum,0,sizeof(ordersum));
        memset(supsum,0,sizeof(supsum));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=k; j++)
            {
                scanf("%d",&ord[i][j]);
                ordersum[j]+=ord[i][j];
            }
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=k; j++)
            {
                scanf("%d",&sup[i][j]);
                supsum[j]+=sup[i][j];
            }
        }
        for(int i=1; i<=k; i++)
        {
            for(int j=1; j<=n; j++)
            {
                for(int h=1; h<=m; h++)
                    scanf("%d",&c[i][j][h]);
            }
        }
        //node = n + m + 2;
        s = 0,t = n + m + 1;
        flag=true;
        int ans=0;
        for(int h=1; h<=k; h++)
        {
            init();
            if(ordersum[h]>supsum[h])
            {
                flag=false;
                break;
            }
            for(int i=1; i<=n; i++)
                addEdge(i,t,ord[i][h],0);
            for(int i=1; i<=m; i++)
                addEdge(s,i+n,sup[i][h],0);
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                    addEdge(j+n,i,sup[j][h],c[h][i][j]);
            }
            ans+=maxFlow();
        }
        if(!flag)
            puts("-1");
        else
            printf("%d\n",ans);
    }
} mcmf;

int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        if(n==0 && m==0 && k==0)
            break;
        mcmf.buildGraph(n,m,k);
    }
    return 0;
}
