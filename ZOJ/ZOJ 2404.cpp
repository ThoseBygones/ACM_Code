#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define MAXN 205
#define MAXE 30010
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

    char mp[MAXN][MAXN];

    struct Points
    {
        int x,y;
        Points(int x,int y):x(x),y(y) {}
        Points() {}
    };

    Points house[MAXN],man[MAXN];

    int head[MAXN],nxt[MAXE],a[MAXN],p[MAXN];
    bool inq[MAXN];
    CostType d[MAXN];
    int cnt,s,t;
    //int node;
    int n,m;

    void init(int a,int b)
    {
        n=a;
        m=b;
        cnt = 0;
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

    int dis(int i,int j)
    {
        return abs(house[j].x-man[i].x)+abs(house[j].y-man[i].y);
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
        int housecnt = 0,mancnt = 0;
        for(int i=1; i<=n; i++)
            scanf("%s",mp[i]+1);
        /*for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                printf("%c",mp[i][j]);
            puts("");
        }
        */
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(mp[i][j]=='H')
                {
                    housecnt++;
                    house[housecnt].x=i;
                    house[housecnt].y=j;
                }
                if(mp[i][j]=='m')
                {
                    mancnt++;
                    man[mancnt].x=i;
                    man[mancnt].y=j;
                }
            }
        }
        s = 0,t = mancnt + housecnt + 1;
        //node = mancnt + housecnt + 2;
        for(int i=1; i<=mancnt; i++)
            addEdge(s,i,1,0);
        for(int i=1; i<=housecnt; i++)
            addEdge(mancnt+i,t,1,0);
        for(int i=1; i<=mancnt; i++)
        {
            for(int j=1; j<=housecnt; j++)
            {
                //cout << dis(i,j) << endl;
                addEdge(i,mancnt+j,1,dis(i,j));
            }
        }
    }
} mcmf;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        mcmf.init(n,m);
        mcmf.buildGraph();
        int ans=mcmf.maxFlow();
        printf("%d\n",ans);
    }
    return 0;
}
