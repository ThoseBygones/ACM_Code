#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 1010
#define MAXE 200005
#define INF 0x3f3f3f3f

class Dinic
{
private:
    int d[MAXN];
    int head[MAXN],nxt[MAXE],cur[MAXN];
    int g[MAXN][MAXN];  //动态关系图
    int sg[5][MAXN]; //保存的删除某条边之前的关系图
    struct Edge
    {
        int from,to,cap,flow;
        Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow) {}
        Edge() {}
    } e[MAXE];

    vector <int> v;

    int s,t,cnt;
    int st,tm;
    //int node;
    int n;

    bool bfs()
    {
        for(int i = 0; i<=2*n; i++) d[i] = -1;
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
        if(x==t||a==0)
            return a;
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
    bool init()
    {
        scanf("%d%d%d",&n,&st,&tm);
        s=n+st;
        t=tm;
        bool flag=false;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                scanf("%d",&g[i][j]);
        }
        if(g[st][tm])
            return false;
        return true;
    }

    int maxFlow()
    {
        int flow = 0;
        while(bfs())
        {
            for(int i = 0; i<=2*n; i++)
                cur[i] = head[i];
            flow+=dfs(s,INF);
        }
        return flow;
    }

    void buildGraph()
    {
        cnt = 0;
        for(int i = 0; i<=2*n; i++)
            head[i] = -1;
        for(int i=1; i<=n; i++)
        {
            //if(st!=i && tm!=i)
            addEdge(i,i+n,1); //拆点建边，只有拆点后的两点之间连的边能作为割边，只能被割一次
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(g[i][j] && i!=j)
                    addEdge(i+n,j,INF);   //保证其余点不会成为割边
            }
        }
    }

    void cutEdge(int x)
    {
        for(int i=1; i<=n; i++)
        {
            if(i==st || i==tm)
                continue;
            for(int j=1; j<=n; j++)
            {
                sg[0][j]=g[i][j];
                sg[1][j]=g[j][i];
                g[i][j]=g[j][i]=0;
            }
            buildGraph();
            int temp=maxFlow();
            //cout << temp << endl;
            if(x>temp)
            {
                v.push_back(i);
                x--;
            }
            else
            {
                for(int j=1; j<=n; j++)
                {
                    g[i][j]=sg[0][j];
                    g[j][i]=sg[1][j];
                }
            }
            if(x==0)
                break;
        }
        printf("%d\n",v.size());
        for(int i=0; i<v.size(); i++)
            printf("%d ",v[i]);
    }
} dinic;

int main()
{
    if(!dinic.init())
    {
        puts("NO ANSWER!");
        return 0;
    }
    dinic.buildGraph();
    int ans=dinic.maxFlow();
    //cout << ans << endl;
    dinic.cutEdge(ans);
    return 0;
}
