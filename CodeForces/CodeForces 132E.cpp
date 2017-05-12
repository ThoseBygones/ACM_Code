#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 510    //250*2
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
    int elem[MAXN];
    int nextelem[MAXN]; //记录元素的下一个值
    int presame[MAXN];  //记录上一个相同变量表示的元素
    char var[MAXN]; //记录变量的值
    int n,m;

    void init(int a,int b)
    {
        cnt = 0;
        n = a;
        m = b;
        memset(head,-1,sizeof(head));
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

    int maxFlow()
    {
        int flow = 0;
        CostType cost = 0;
        while(spfa(flow,cost));
        return cost;
    }

    int getValue(int x)
    {
        int sum=0;
        while(x)
        {
            sum+=x&1;
            x>>=1;
        }
        return sum;
    }

    void buildGraph()
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&elem[i]);
        node = 2 * n + 2;   //拆点：对每个元素的操作拆成两个点（入点、出点）
        s = 0;  //源点
        t = 2 * n + 1;  //汇点
        //addEdge(s,1,m,0);   //源点到第一个元素的入点连边
        //addEdge(2*n,t,m,0); //最后一个元素的出点到
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(elem[i]!=elem[j])
                    addEdge(i,n+j,1,getValue(elem[j])); //元素不同，则需要赋值各额外变量，连容量为1的边
                else
                    addEdge(i,n+j,1,0); //元素相同，不需要赋值给额外变量
            }
        }
        addEdge(s,2*n+2,m,0);   //另设一个点控制变量数不超过m个
        for(int i=1; i<=n; i++)
        {
            addEdge(s,i,1,0);
            addEdge(n+i,t,1,0);
            addEdge(2*n+2,n+i,1,getValue(elem[i]));    //已赋值变量改变值也需要额外花费
        }
    }

    void solve()
    {
        int ans=maxFlow();
        memset(nextelem,-1,sizeof(nextelem));
        memset(presame,-1,sizeof(presame));
        for(int i=1; i<=n; i++)
        {
            for(int j=head[i]; ~j; j=nxt[j])
            {
                if(e[j].to>n && e[j].flow)  //有流量（指示了元素处理路径）
                {
                    nextelem[i]=e[j].to-n;  //记录要处理的下一个元素
                    presame[e[j].to-n]=i;   //记录前驱

                }
            }
        }
        char tempvar='a';   //字母变量初始化为a
        for(int i=1; i<=n; i++)
        {
            if(presame[i]==-1)
                var[i]=tempvar++;
        }
        int opcnt=0;    //操作次数计数
        for(int i=1; i<=n; i++)
        {
            if(presame[i]==-1 || elem[presame[i]]!=elem[i])
                opcnt++;
            opcnt++;    //打印一次，计数+1
            if(nextelem[i]!=-1)
                var[nextelem[i]]=var[i];
        }
        printf("%d %d\n",opcnt,ans);
        for(int i=1; i<=n; i++)
        {
            if(presame[i]==-1 || elem[presame[i]]!=elem[i])
                printf("%c=%d\n",var[i],elem[i]);
            printf("print(%c)\n",var[i]);
            if(nextelem[i]!=-1)
                var[nextelem[i]]=var[i];
        }
    }
} mcmf;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    mcmf.init(n,m);
    mcmf.buildGraph();
    mcmf.solve();
    return 0;
}
