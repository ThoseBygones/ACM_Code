#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 405
#define MAXE 25005    //源点->食物：100*2 + 食物到牛的入点：100*100*2 + 牛的入点到牛的出点：100*2 + 牛的出点到饮料：100*100*2 + 饮料到汇点：100*2
#define INF 0x3f3f3f3f

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

    int n,m,k;
    int s,t,cnt;
    //int node;
    bool bfs()
    {
        for(int i = 0; i<=t; i++) d[i] = -1;
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
        if(x==t||a==0) return a;
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
                if(a==0) break;
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
    void init(int a,int b,int c)
    {
        cnt = 0;
        n = a;
        m = b;
        k = c;
    }

    int maxFlow()
    {
        int flow = 0;
        while(bfs())
        {
            for(int i = 0; i<=t; i++) cur[i] = head[i];
            flow+=dfs(s,INF);
        }
        return flow;
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));

        s = 0;
        t = 2 * n + m + k + 1;    //拆点，每头牛拆成两个点：入点和出点

        for(int i=1; i<=m; i++)
            addEdge(s,2*n+i,1);  //源点与食物建边

        for(int i=1; i<=k; i++)
            addEdge(2*n+m+i,t,1);    //饮料与汇点建边

        for(int i=1; i<=n; i++)
        {
            int fnum,dnum;
            scanf("%d%d",&fnum,&dnum);
            while(fnum--)
            {
                int temp;
                scanf("%d",&temp);
                addEdge(2*n+temp,i,1);  //食物与牛的入点建边
            }

            addEdge(i,n+i,1);   //牛的入点与牛的出点建边

            while(dnum--)
            {
                int temp;
                scanf("%d",&temp);
                addEdge(n+i,2*n+m+temp,1);  //牛的出点与饮料建边
            }
        }
    }
} dinic;

int main()
{
    int n,f,d;
    scanf("%d%d%d",&n,&f,&d);
    dinic.init(n,f,d);
    dinic.buildGraph();
    int ans=dinic.maxFlow();
    printf("%d\n",ans);
    return 0;
}
