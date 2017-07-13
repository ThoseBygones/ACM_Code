//贪心+优先队列
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 2505

pair <int,int> cow[MAXN];
pair <int,int> bottle[MAXN];
priority_queue <int, vector<int>, greater<int> > pq;

int main()
{
    int c,l;
    scanf("%d%d",&c,&l);
    for(int i=0; i<c; i++)
        scanf("%d%d",&cow[i].first,&cow[i].second);
    for(int i=0; i<l; i++)
        scanf("%d%d",&bottle[i].first,&bottle[i].second);
    sort(cow,cow+c);
    sort(bottle,bottle+l);
    int cowid=0;    //当前奶牛的编号
    int ans=0;
    for(int i=0; i<l; i++)
    {
        while(cowid<c && cow[cowid].first<=bottle[i].first)
        {
            pq.push(cow[cowid].second);
            cowid++;
        }
        while(!pq.empty() && bottle[i].second)
        {
            int temp=pq.top();
            pq.pop();
            if(temp>=bottle[i].first)
            {
                ans++;
                bottle[i].second--;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}


//最大流Dinic
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 5010
#define MAXE 30000005
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

    struct Cow
    {
        int minSPF,maxSPF;
        Cow(int minSPF,int maxSPF):minSPF(minSPF),maxSPF(maxSPF) {}
        Cow() {}
    } cow[MAXN/2];

    int s,t,cnt;
    int c,l;
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
    void init(int n,int m)
    {
        c = n;
        l = m;
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

    void buildGraph()
    {
        s = 0;
        t = c + l + 1;
        for(int i = 0; i<=t; i++) head[i] = -1;
        for(int i=1; i<=c; i++)
        {
            scanf("%d%d",&cow[i].minSPF,&cow[i].maxSPF);
            addEdge(l+i,t,1);
        }
        for(int i=1; i<=l; i++)
        {
            int val,num;
            scanf("%d%d",&val,&num);
            addEdge(s,i,num);
            for(int j=1; j<=c; j++)
            {
                if(cow[j].minSPF<=val && val<=cow[j].maxSPF)
                    addEdge(i,l+j,1);
            }
        }
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
