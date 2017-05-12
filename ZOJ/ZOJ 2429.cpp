#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 1005
#define MAXE 1000005
#define INF 0x3f3f3f3f


class Dinic
{
    int d[MAXN];
    int head[MAXN],nxt[MAXE],cur[MAXN];
    struct Edge
    {
        int from,to,cap,flow;
        Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow) {}
        Edge() {}
    } e[MAXE];

    int s,t,cnt;
    int n,m;
    int vis[MAXN];  //输出删除点顺序时记录的数组

    bool bfs()
    {
        for(int i=0; i<=t; i++)
            d[i]=-1;
        d[s]=0;
        queue<int>q;
        q.push(s);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int i=head[x]; ~i; i=nxt[i])
            {
                Edge &ed = e[i];
                if(d[ed.to]==-1 && ed.cap>ed.flow)
                {
                    d[ed.to]=d[x]+1;
                    q.push(ed.to);
                }
            }
        }
        return d[t]!=-1;
    }

    int dfs(int x,int a)
    {
        if(x==t || a==0)
            return a;
        int flow=0,f;
        for(; ~cur[x]; cur[x]=nxt[cur[x]])
        {
            Edge &ed=e[cur[x]];
            if(d[ed.to]==d[x]+1 && (f = dfs(ed.to,min(ed.cap-ed.flow,a)))>0)
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
        e[cnt]=Edge(from,to,cap,0);
        int tmp=head[from];
        head[from]=cnt;
        nxt[cnt++]=tmp;
        e[cnt]=Edge(to,from,0,0);
        tmp=head[to];
        head[to]=cnt;
        nxt[cnt++]=tmp;
    }

public:
    void init(int a,int b)
    {
        cnt = 0;
        n = a;
        m = b;
        s = 0;
        t = n * 2 + 1;  //拆点，拆成入和出
        memset(vis,0,sizeof(vis));
    }

    int maxFlow()
    {
        int flow = 0;
        while(bfs())
        {
            for(int i=0; i<=t; i++)
                cur[i]=head[i];
            flow+=dfs(s,INF);
        }
        return flow;
    }

    void dfsVertex(int u)
    {
        vis[u]=1;
        for(int i=head[u]; ~i; i=nxt[i])
        {
            int v=e[i].to;
            if(!vis[v] && e[i].cap-e[i].flow)   //满流则继续搜
                dfsVertex(v);
        }
    }

    void buildGraph()
    {
        for(int i=0; i<=t; i++)
            head[i]=-1;
        for(int i=1; i<=n; i++)
        {
            int cost;
            scanf("%d",&cost);
            addEdge(i+n,t,cost);    //删除入边的花费，入点向汇点连边
        }
        for(int i=1; i<=n; i++)
        {
            int cost;
            scanf("%d",&cost);
            addEdge(s,i,cost);  //删除出边的花费，源点向出点连边
        }
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v+n,INF);
        }
    }

    void print()
    {
        int ans=0;

        //i<=n的点表示第i个点的出边，如果从源点无法通过残余容量为0的边遍历到，那么说明这个点的出边是属于割集的，即所求点。反之，对于能遍历到的点，肯定不是割点。
        //i>n的点表示第i个点的入边，如果被遍历到了，肯定是属于割点的。因为从源点开始遍历，肯定要先通过1-n的点到达n+1~2*n的点。假设到达了i+n这个点，并且假设是从j到达i+n的点的，j肯定不属于割点，那么j的出边肯定就没有删除。因为要求要删掉所有的边，既然从j不能删掉从j出发的边，那么只能删掉j所到达的边的入边了。既然能从j->i+n，那么相对i来说这是条入边，i一定要属于割点才能保证删掉所有的边。
        for(int i=1; i<=n; i++)
            ans+=(!vis[i]+vis[i+n]);
        printf("%d\n",ans);
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
                printf("%d -\n",i);
            if(vis[i+n])
                printf("%d +\n",i);
        }
    }
} dinic;

int main()
{
    int n,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        dinic.init(n,m);
        dinic.buildGraph();
        printf("%d\n",dinic.maxFlow());
        dinic.dfsVertex(0);
        dinic.print();
        if(t)
            puts("");
    }
    return 0;
}
