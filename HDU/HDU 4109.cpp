//差分约束/spfa求最长路
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 1005
#define MAXE 20005
#define INF 0x3f3f3f3f

typedef int Type;

class SPFA
{
public:
    int head[MAXN],nxt[MAXE],cnt;
    Type d[MAXN];
    struct Edge
    {
        int v;
        Type cost;
        Edge() {}
        Edge(int v,Type cost):v(v),cost(cost) {}
    } e[MAXE];

    bool inq[MAXN];

    void init(int n)
    {
        cnt = 0;
        for(int i = 0; i <= n+1; i++) head[i] = -1;
    }

    inline void addEdge(int u,int v,Type cost)
    {
        e[cnt] = Edge(v,cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    Type spfa(int s,int t,int n)
    {
        for(int i = 0; i <= n+1; i++) inq[i] = false,d[i] = INF;
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            inq[x] = false;
            for(int i = head[x]; ~i; i = nxt[i])
            {
                Edge ed = e[i];
                if(d[ed.v]>d[x]+ed.cost)
                {
                    d[ed.v] = d[x]+ed.cost;
                    if(!inq[ed.v])
                    {
                        inq[ed.v] = true;
                        q.push(ed.v);
                    }
                }
            }
        }
        return d[t];
    }
} spfa;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        spfa.init(n);
        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u++;
            v++;
            spfa.addEdge(u,v,-w);
        }
        for(int i=1; i<=n; i++)
        {
            spfa.addEdge(0,i,0);
            spfa.addEdge(i,n+1,-1);
        }
        printf("%d\n",-spfa.spfa(0,n+1,n));
    }
    return 0;
}


//拓扑排序+关键路径
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 1005
#define MAXE 10005

struct Edge
{
    int from;
    int to;
    int cost;
    int next;
} e[MAXE];

int head[MAXN];
int indegree[MAXN];
int mint[MAXN];
int n,m;
int cnt;

void init()
{
    cnt = 0;
    memset(head,-1,sizeof(head));
    memset(indegree,0,sizeof(indegree));
    memset(mint,0,sizeof(mint));
}

void addEdge(int u,int v,int w)
{
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].cost = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void toposort()
{
    queue <int> q;
    for(int i=1; i<=n; i++)
    {
        if(!indegree[i])
            q.push(i);
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u]; ~i; i=e[i].next)
        {
            int v=e[i].to;
            if(!mint[v])
                mint[v]=e[i].cost+mint[u];
            else
                mint[v]=max(mint[v],e[i].cost+mint[u]);
            indegree[v]--;
            if(!indegree[v])
                q.push(v);
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u++;
            v++;
            addEdge(u,v,w);
            indegree[v]++;
        }
        toposort();
        int ans=0;
        for(int i=1; i<=n; i++)
            ans=max(ans,mint[i]);
        printf("%d\n",ans+1);   //加上最后完成最后一个项目需要花费的1ns
    }
    return 0;
}
