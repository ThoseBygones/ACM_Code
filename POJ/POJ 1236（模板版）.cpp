#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

//有向图强连通分量Tarjan算法

#define MAXN 105
#define MAXE 20005

class SCC
{
public:
    int head[MAXN];
    struct Edge
    {
        int to,next;
        Edge() {}
        Edge(int to,int next):to(to),next(next) {}
    } e[MAXE];

    void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    int belong[MAXN];
    int dfn[MAXN];
    int low[MAXN];
    //bool instack[MAXN];
    int ind[MAXN];  //入度
    int outd[MAXN]; //出度

    stack <int> sta;

    int n,m;
    int cnt;
    int dfs_clock,scc_cnt;

    void init(int n)
    {
        this -> n = n;
        dfs_clock = scc_cnt = 0;
        memset(dfn,0,sizeof(dfn));
        memset(belong,0,sizeof(belong));
    }

    void tarjan(int u)
    {
        dfn[u] = low[u] = ++dfs_clock;
        sta.push(u);
        //instack[u] = true;
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!dfn[v])
            {
                tarjan(v);
                low[u] = min(low[u],low[v]);
            }
            //else if(instack[v])
            else if(!belong[v])
                low[u] = min(low[u],dfn[v]);
        }
        if(dfn[u]==low[u])
        {
            scc_cnt++;
            while(!sta.empty())
            {
                int temp = sta.top();
                //instack[v] = false;
                belong[temp] = scc_cnt;
                sta.pop();
                if(u==temp)
                    break;
            }
        }
    }

    void find_scc()    //缩点
    {
        memset(ind,0,sizeof(ind));
        memset(outd,0,sizeof(outd));
        for(int i = 1; i<=n; i++)
        {
            for(int j = head[i]; ~j; j = e[j].next)
            {
                int v = e[j].to;
                if(belong[i]!=belong[v])
                {
                    ind[belong[v]]++;
                    outd[belong[i]]++;
                }
            }
        }
    }

    void buildGraph()
    {
        cnt = 0;
        memset(head,-1,sizeof(head));
        for(int u=1; u<=n; u++)
        {
            int v;
            while(~scanf("%d",&v),v)
                addEdge(u,v);
        }
    }

    void solve()    //求有向图的强连通分量
    {
        buildGraph();
        for(int i = 1; i<=n; i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        find_scc();
        int inzero=0,outzero=0;
        for(int i=1; i<=scc_cnt; i++)
        {
            if(!ind[i])
                inzero++;
            if(!outd[i])
                outzero++;
        }
        if(scc_cnt==1)
            printf("1\n0\n");
        else
            printf("%d\n%d\n",inzero,max(inzero,outzero));
    }
} scc;

int main()
{
    int n;
    scanf("%d",&n);
    scc.init(n);
    scc.solve();
}
