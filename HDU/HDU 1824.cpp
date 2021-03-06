#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

//2-SAT模板

#define MAXN 3005
#define MAXE 200005

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
    int s[MAXN<<1];
    int c,cnt,dfs_clock;
    int n,m;

    stack <int> sta;

    int dfn[MAXN<<1];
    int low[MAXN<<1];
    int belong[MAXN<<1];
    int color[MAXN<<1];
    int id[MAXN<<1];

    //使用前调用
    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = dfs_clock = 0;
        memset(dfn,0,sizeof(dfn));
        memset(belong,0,sizeof(belong));
        memset(color,0,sizeof(color));
        memset(mark,0,sizeof(mark));
        while(!sta.empty())
            sta.pop();
    }

    bool dfs(int u) //用来判断当前的强连通分量当中会不会出现矛盾
    {
        if(mark[u^1]) return false; //如果需要被选的不能被选那么矛盾
        if(mark[u]) return true;    //如果需要被选的已经被选，那么当前联通分量一定    不会出现矛盾
        mark[u] = true; //如果当前点需要被选，那么选上它，并且标记
        s[c++] = u; //当前的强连通分量加上这个点
        //找到与当前点相连点，判断他们的状态
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!dfs(v))
                return false;
        }
        return true;
    }

    inline void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    void tarjan(int u)
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
            int temp;
            do
            {
                temp = sta.top();
                belong[temp] = cnt;
                mark[temp] = 2;
                sta.pop();
            }
            while(temp!=u);
            cnt++;
        }
    }

    bool check()    //利用强连通缩点判断2-SAT问题是否有解
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
        for(int i = 0; i<2*n; i++) head[i] = -1,mark[i] = 0;
        for(int i=0; i<n; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            id[a]=i<<1;
            id[b]=id[c]=i<<1|1;
        }
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(id[u],(id[v]^1));
            addEdge(id[v],(id[u]^1));
        }
    }
} twosat;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        twosat.init(n,m);
        twosat.buildGraph();
        bool flag=twosat.check();
        puts(flag?"yes":"no");
    }
    return 0;
}
