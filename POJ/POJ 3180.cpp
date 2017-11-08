#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

#define MAXN 10005
#define MAXE 2000005

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
    int ans;

    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
        dfs_clock = scc_cnt = 0;
        ans = 0;
        memset(dfn,0,sizeof(dfn));
        memset(belong,0,sizeof(belong));
    }

    void tarjan(int u)
    {
        dfn[u] = low[u] = ++dfs_clock;
        sta.push(u);
        //instack[u] = true;
        int num = 0;
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
                num++;
                belong[temp] = scc_cnt;
                sta.pop();
                if(u==temp)
                    break;
            }
            if(num>=2)  //含结点数大于2的强连通分量才算（因为一头牛自己无法跳舞）
                ans++;
        }
    }

    void buildGraph()
    {
        cnt = 0;
        memset(head,-1,sizeof(head));
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
        }
    }

    void solve()    //求有向图的强连通分量
    {
        buildGraph();
        for(int i = 0; i<n; i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        printf("%d\n",ans);
    }
} scc;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scc.init(n,m);
    scc.solve();
    return 0;
}
