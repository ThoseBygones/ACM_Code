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
    int vis[MAXN];  //���ɾ����˳��ʱ��¼������

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
        t = n * 2 + 1;  //��㣬�����ͳ�
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
            if(!vis[v] && e[i].cap-e[i].flow)   //�����������
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
            addEdge(i+n,t,cost);    //ɾ����ߵĻ��ѣ������������
        }
        for(int i=1; i<=n; i++)
        {
            int cost;
            scanf("%d",&cost);
            addEdge(s,i,cost);  //ɾ�����ߵĻ��ѣ�Դ�����������
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

        //i<=n�ĵ��ʾ��i����ĳ��ߣ������Դ���޷�ͨ����������Ϊ0�ı߱���������ô˵�������ĳ��������ڸ�ģ�������㡣��֮�������ܱ������ĵ㣬�϶����Ǹ�㡣
        //i>n�ĵ��ʾ��i�������ߣ�������������ˣ��϶������ڸ��ġ���Ϊ��Դ�㿪ʼ�������϶�Ҫ��ͨ��1-n�ĵ㵽��n+1~2*n�ĵ㡣���赽����i+n����㣬���Ҽ����Ǵ�j����i+n�ĵ�ģ�j�϶������ڸ�㣬��ôj�ĳ��߿϶���û��ɾ������ΪҪ��Ҫɾ�����еıߣ���Ȼ��j����ɾ����j�����ıߣ���ôֻ��ɾ��j������ıߵ�����ˡ���Ȼ�ܴ�j->i+n����ô���i��˵��������ߣ�iһ��Ҫ���ڸ����ܱ�֤ɾ�����еıߡ�
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
