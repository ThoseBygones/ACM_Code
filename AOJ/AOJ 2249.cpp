#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 20005
#define MAXE 40005
#define INF 0x3f3f3f3f

typedef int Type;

class Dijkstra
{
public:
    int head[MAXN],nxt[MAXE],cnt;
    Type d[MAXN];
    struct Edge
    {
        int v;
        Type dis;
        Type cost;
        Edge() {}
        Edge(int v,Type dis,Type cost):v(v),dis(dis),cost(cost) {}
        bool operator<(const Edge& ed) const
        {
            return dis>ed.dis;
        }
    } e[MAXE];
    bool vis[MAXN];

    //初始化，n为点数
    void init(int n)
    {
        cnt = 0;
        for(int i = 0; i<=n; i++) head[i] = -1;
    }

    inline void addEdge(int u,int v,Type dis,Type cost)
    {
        e[cnt] = Edge(v,dis,cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    void dijkstra(int s,int t,int n)
    {
        for(int i = 0; i<=n; i++) d[i] = INF,vis[i] = false;
        d[s] = 0;
        priority_queue<Edge> q;
        q.push(Edge(s,0,0));
        while(!q.empty())
        {
            Edge ed = q.top();
            q.pop();
            vis[ed.v] = true;
            for(int i = head[ed.v]; ~i; i = nxt[i])
            {
                Edge ee = e[i];
                if(!vis[ee.v]&&d[ee.v]>d[ed.v]+ee.dis)
                {
                    d[ee.v] = d[ed.v]+ee.dis;
                    /*
                     *  最短路树
                    	p[ee.v] = MP(u,i);
                    */
                    q.push(Edge(ee.v,d[ee.v],ee.cost));
                }
            }
        }
    }

    void buildGraph(int m)
    {
        for(int i=0; i<m; i++)
        {
            int u,v,d,c;
            scanf("%d%d%d%d",&u,&v,&d,&c);
            addEdge(u,v,d,c);
            addEdge(v,u,d,c);
        }
    }

    Type getMinCost(int n)
    {
        int ans=0;
        for(int u=2; u<=n; u++) //首都不能变
        {
            int Min=INF;
            for(int j=head[u]; ~j; j=nxt[j])
            {
                Edge ee = e[j];
                if(d[u]==d[ee.v]+ee.dis && ee.cost<Min) //找寻满足优先距离最短，然后费用最低的那个最低费用
                    Min=ee.cost;
            }
            ans+=Min;
        }
        return ans;
    }
} dij;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        dij.init(n);
        dij.buildGraph(m);
        dij.dijkstra(1,n,n);
        int ans=dij.getMinCost(n);
        printf("%d\n",ans);
    }
    return 0;
}
