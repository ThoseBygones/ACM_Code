//最小费用最大流
#include <bits/stdc++.h>
using namespace std;

#define MAXN 6010
#define MAXE 40000005
#define INF 0x3f3f3f3f

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

    int head[MAXN],nxt[MAXE],a[MAXN],p[MAXN];
    bool inq[MAXN];
    CostType d[MAXN];
    int cnt,s,t;
    int ss;
    int n;
    int node;
    int b[MAXN];

    void init(int z)
    {
        cnt = 0;
        n = z;
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
        ss = 0; //源点
        t = 2 * n + 1;  //汇点
        s = 2 * n + 2;  //超级源点
        node = s;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&b[i]);
            addEdge(ss,i,1,0);  //源点到入点连边
            addEdge(i,i+n,1,-1); //入点到出点连边（用于控制点的流量，即每个元素只能有效出现在一个子序列中一次）
            addEdge(i,i+n,4,0); //入点到出点连边（无效情况）
            addEdge(i+n,t,1,0);   //出点到汇点连边
        }
        addEdge(s,ss,4,0);
        for(int i=2; i<=n; i++)
        {
            for(int j=i-1; j>0; j--)    //边太多了，不能都连（采用链式建边）
            {
                if(b[j]==b[i]+1)
                {
                    addEdge(j+n,i,1,0);
                    break;
                }
            }
            for(int j=i-1; j>0; j--)
            {
                if(b[j]==b[i]-1)
                {
                    addEdge(j+n,i,1,0);
                    break;
                }
            }
            for(int j=i-1; j>0; j--)
            {
                if(b[j]%7==b[i]%7)
                {
                    addEdge(j+n,i,1,0);
                    break;
                }
            }
        }
    }
} mcmf;

int main()
{
    int n;
    scanf("%d",&n);
    mcmf.init(n);
    mcmf.buildGraph();
    int ans=mcmf.maxFlow();
    printf("%d\n",-ans);
    return 0;
}
