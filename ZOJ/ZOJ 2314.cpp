#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 205
#define MAXE 100005
#define INF 0x3f3f3f3f

class Dinic
{
private:
    int d[MAXN];
    int head[MAXN],nxt[MAXE],cur[MAXN];
    int du[MAXN];
    int down[MAXE];
    struct Edge
    {
        int from,to,cap,flow;
        Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow) {}
        Edge() {}
    } e[MAXE];

    int s,t,cnt;
    //int n,m;
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
    void init()
    {
        cnt = 0;
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

    //上下界可行流
    //du[i]为i流出去的下界和减去流进来的下界和
    //求s到t的最大流，如果最大流等于所有du[i]>0的和则有可行流
    int buildGraph(int n,int m)
    {
        s = n + 1;
        t = n + 2;
        for(int i = 0; i<=t; i++)
        {
            head[i] = -1;
            du[i]=0;
        }
        for(int i = 0; i<m; i++)
        {
            int u,v,l,c;
            scanf("%d%d%d%d",&u,&v,&l,&c);
            //c为上界,l为下界
            down[i] = l;
            du[u]-=l;
            du[v]+=l;
            addEdge(u,v,c-l);
        }
        int sum = 0;
        for(int i = 1; i<=n; i++)
        {
            if(du[i]>0)
            {
                addEdge(s,i,du[i]);
                sum+=du[i];
            }
            else if(du[i]<0) addEdge(i,t,-du[i]);
        }
        return sum;
    }

    int getResult(int m)
    {
        for(int i=0; i<m; i++)
        printf("%d\n",down[i]+e[i*2].flow);
    }
} dinic;

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        dinic.init();
        int sum=dinic.buildGraph(n,m);
        //cout << sum << endl;
        int ans=dinic.maxFlow();
        //cout << ans << endl;
        if(ans!=sum)
            puts("NO");
        else
        {
            puts("YES");
            dinic.getResult(m);
        }
        puts("");
    }
    return 0;
}
