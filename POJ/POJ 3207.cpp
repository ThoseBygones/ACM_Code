#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

#define MAXN 1005
#define MAXE 1000005

class TwoSat
{
public:
    int head[MAXN<<1];
    struct Edge
    {
        int to,next;
        Edge() {}
        Edge(int to,int next):to(to),next(next) {}
    } e[MAXE];

    int mark[MAXN<<1];  //mark[i<<1]==1，表示点i被选择；mark[i<<1|1]==1，表示点i没有被选择
    int cnt,scc_cnt,dfs_clock;
    int n,m;

    stack <int> sta;

    int dfn[MAXN<<1];
    int low[MAXN<<1];
    int belong[MAXN<<1];

    int p1[MAXN],p2[MAXN];

    //使用前调用
    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = scc_cnt = dfs_clock = 0;
        memset(dfn,0,sizeof(dfn));
        memset(belong,0,sizeof(belong));
        while(!sta.empty())
            sta.pop();
    }

    inline void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }


    /*判断2-SAT问题是否有解*/
    void tarjan(int u)  //Tarjan算法求解强连通分量并缩点
    {
        dfn[u] = low[u] = ++dfs_clock;
        mark[u] = 1;
        sta.push(u);
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!mark[v])
            {
                tarjan(v);
                low[u] = min(low[u],low[v]);
            }
            if(mark[v]==1)
                low[u] = min(low[u],dfn[v]);
        }
        if(dfn[u]==low[u])
        {
            scc_cnt++;
            int temp;
            do
            {
                temp = sta.top();
                belong[temp] = scc_cnt;
                mark[temp] = 2;
                sta.pop();
            }
            while(temp!=u);
        }
    }

    bool check()    //判断缩点后有没有冲突
    {
        for(int i = 0; i<2*n; i++)
        {
            if(!mark[i])
                tarjan(i);
        }
        for(int i = 0; i<n; i++)
        {
            if(belong[i<<1]==belong[i<<1|1])
                return false;
        }
        return true;
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        memset(mark,0,sizeof(mark));
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&p1[i],&p2[i]);
            if(p1[i]>p2[i])
                swap(p1[i],p2[i]);
        }
        for(int i=0; i<m; i++)
        {
            for(int j=i+1; j<m; j++)
            {
                int u=i<<1;
                int v=j<<1;
                if((p1[i]<p1[j]&&p2[i]<p2[j]&&p1[j]<p2[i])||(p1[j]<p1[i]&&p2[j]<p2[i]&&p1[i]<p2[j]))
                {
                    addEdge(u,v^1);
                    addEdge(v,u^1);
                    addEdge(u^1,v);
                    addEdge(v^1,u);
                }
            }
        }
    }

    void solve()
    {
        buildGraph();
        if(check())
            puts("panda is telling the truth...");
        else
            puts("the evil panda is lying again");
    }
} twosat;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    twosat.init(n,m);
    twosat.solve();
    return 0;
}
