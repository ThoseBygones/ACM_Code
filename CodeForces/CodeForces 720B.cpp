#include <bits/stdc++.h>
using namespace std;

#define MAXN 40005
#define MAXE 2000005
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

    int nhead[MAXN];
    int fa[MAXN],depth[MAXN],vis[MAXN],color[MAXN];   //结点的父节点，深度，访问状况，颜色
    int colex[MAXN];    //某种颜色是否存在于图中
    int que[MAXN];
    int top;
    int cycid;  //环或者不在换上的边的编号
    struct Node
    {
        int from,to,col,next;
        Node(int from,int to,int col,int next):from(from),to(to),col(col),next(next) {}
        Node() {}
    } node[MAXN];

    int s,t,cnt,tot;
    int n,m;

    bool bfs()
    {
        memset(d,-1,sizeof(d));
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

    void addNode(int from,int to,int col)
    {
        node[tot].from = from;
        node[tot].to = to;
        node[tot].col = col;
        node[tot].next = nhead[from];
        nhead[from] = tot++;
        node[tot].from = to;
        node[tot].to = from;
        node[tot].col = col;
        node[tot].next = nhead[to];
        nhead[to] = tot++;
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

    void dfsNode(int x,int pre,int col)  //判环
    {
        fa[x]=pre;
        que[++top]=x;
        color[x]=col;
        vis[x]=1;
        depth[x]=depth[pre]+1;
        for(int i=nhead[x]; ~i; i=node[i].next)
        {
            int y=node[i].to;
            if(y==pre)
                continue;
            if(!vis[y])
                dfsNode(y,x,node[i].col);
            else if(depth[y]<depth[x])  //出现回边
            {
                int sum=0;
                cycid++;
                int p=top;
                while(que[p]!=y)
                {
                    addEdge(cycid,color[que[p]],1);   //环与颜色建边，容量为1
                    sum++;
                    colex[que[p]]=1;
                    p--;
                }
                addEdge(s,cycid,sum);
                addEdge(cycid,node[i].col,1);
            }
        }
        top--;
        if(!colex[x] && fa[x]!=-1)  //终点（且不是孤立点）对应的边
        {
            addEdge(s,++cycid,1);
            addEdge(cycid,color[x],1);
        }
    }
public:
    void init(int a,int b)
    {
        cnt = tot = 0;
        n = a;
        m = b;
        top = 0;
        cycid = 0;
        memset(que,0,sizeof(que));
        memset(vis,0,sizeof(vis));
        memset(fa,-1,sizeof(fa));
        memset(depth,0,sizeof(depth));
        memset(colex,0,sizeof(colex));
        memset(color,0,sizeof(color));
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
        s = 0;
        t = n + m + 1;
        memset(nhead,-1,sizeof(nhead));
        memset(head,-1,sizeof(head));
        for(int i=1; i<=m; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            addNode(u,v,c+n);
        }
        dfsNode(1,-1,0);
        for(int i=n+1; i<=n+m; i++) //每种颜色最多算出现一次
            addEdge(i,t,1);
    }
} dinic;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    dinic.init(n,m);
    dinic.buildGraph();
    int ans=dinic.maxFlow();
    printf("%d\n",ans);
    return 0;
}
