#include <bits/stdc++.h>
using namespace std;

#define MAXN 110
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
    int n,m;
    int l[MAXN],r[MAXN];

    void init(int n,int m)
    {
        cnt = 0;
        this -> n = n;
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
    //int maxFlow()
    {
        int flow = 0;
        CostType cost = 0;
        while(spfa(flow,cost));
        return flow==n?cost:-1; //如果流量不到n说明数组中有元素找不到符合要求的赋值
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        for(int i=1; i<=n; i++)
        {
            l[i]=1;
            r[i]=n;
        }
        for(int i=1; i<=m; i++)
        {
            int t,x,y,v;
            scanf("%d%d%d%d",&t,&x,&y,&v);
            if(t==1)
            {
                for(int j=x; j<=y; j++)
                    l[j]=max(l[j],v);
            }
            else
            {
                for(int j=x; j<=y; j++)
                    r[j]=min(r[j],v);
            }
        }
        s = 0;
        t = 2 * n + 1;
        node = t;
        for(int i=1; i<=n; i++)
        {
            for(int j=l[i]; j<=r[i]; j++)
                addEdge(i,j+n,1,0);
            addEdge(s,i,1,0);
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=2*n; j+=2)  //费用为1,3,5,...以实现cnt(flow)=x时，cost=x^2（1,1+3=4,1+3+5=9,...)
                addEdge(i+n,t,1,j);
        }
    }
} mcmf;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    mcmf.init(n,m);
    mcmf.buildGraph();
    int ans=mcmf.maxFlow();
    printf("%d\n",ans);
    return 0;
}
