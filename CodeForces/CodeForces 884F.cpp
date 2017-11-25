#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define MAXE 100005
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

    int head[MAXN],nxt[MAXE],a[MAXN],p[MAXN];
    bool inq[MAXN];
    CostType d[MAXN];
    int cnt,s,t;
    int node;
    int n;

    char str[105];
    int b[105];
    int num[30];

    void init(int n)
    {
        cnt = 0;
        this -> n = n;
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
        for(int i = 0; i<=node; i++)
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

    CostType maxFlow()
    //int maxFlow()
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
        s = 0;
        t = 26 + n/2 + 1;
        node = t;
        for(int i=1; i<=26; i++)
            addEdge(s,i,num[i],0);
        for(int i=1; i<=26; i++)
        {
            for(int j=1; j<=n/2; j++)
            {
                if(str[j]==(i+'a'-1)||str[n-j+1]==(i+'a'-1))
                {
                    if(str[j]==str[n-j+1])
                        addEdge(i,j+26,1,-max(b[j],b[n-j+1]));
                    else
                    {
                        if(str[j]==(i+'a'-1))
                            addEdge(i,j+26,1,-b[j]);
                        else
                            addEdge(i,j+26,1,-b[n-j+1]);
                    }
                }
                else
                    addEdge(i,j+26,1,0);
            }
        }
        for(int i=1; i<=n/2; i++)
            addEdge(i+26,t,2,0);
    }

    void solve()
    {
        scanf("%s",str+1);
        for(int i=1; i<=n; i++)
            num[str[i]-'a'+1]++;
        for(int i=1; i<=n; i++)
            scanf("%d",&b[i]);
        buildGraph();
        int ans=maxFlow();
        printf("%d\n",-ans);
    }
} mcmf;

int main()
{
    int n;
    scanf("%d",&n);
    mcmf.init(n);
    mcmf.solve();
    return 0;
}
