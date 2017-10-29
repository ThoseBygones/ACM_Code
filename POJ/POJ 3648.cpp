#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 10005
#define MAXE 2000005

class TwoSat
{
public:
    int head[MAXN<<1];
    struct Edge
    {
        int to,next;
        Edge() {}
        Edge(int to,int next):to(to),next(next) {}
    } e[MAXE],g[MAXE];

    int mark[MAXN<<1];  //mark[i<<1]==1，表示点i被选择；mark[i<<1|1]==1，表示点i没有被选择
    int cnt,scc_cnt,dfs_clock;
    int n,m;

    stack <int> sta;
    vector <int> nG[MAXN];    //缩点后建立的新图

    int dfn[MAXN<<1];
    int low[MAXN<<1];
    int belong[MAXN<<1];
    int color[MAXN<<1]; //求解任意一组可行解时记录点的颜色
    int conf[MAXN<<1];  //记录新图中的冲突点
    int ind[MAXN<<1];  //入度

    //使用前调用
    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = scc_cnt = dfs_clock = 0;
        memset(dfn,0,sizeof(dfn));
        memset(belong,0,sizeof(belong));
        memset(color,0,sizeof(color));
        memset(conf,0,sizeof(conf));
        memset(ind,0,sizeof(ind));
        for(int i=0; i<MAXN; i++)
            nG[i].clear();
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

    /*求2-SAT问题的任意一组可行解*/
    void cal()  //建立缩点后的新图并为之后的拓扑排序染色做准备
    {
        for(int i = 0; i<n; i++)
        {
            if(!conf[belong[i<<1]])
            {
                conf[belong[i<<1]] = belong[i<<1|1];
                conf[belong[i<<1|1]] = belong[i<<1];
            }
        }
        for(int i = 0; i<2*n; i++)
        {
            for(int j = head[i]; ~j; j = e[j].next)
            {
                int v = e[j].to;
                if(belong[i]!=belong[v])
                {
                    ind[belong[i]]++;
                    nG[belong[v]].push_back(belong[i]);
                }
            }
        }
    }

    void topoSort() //拓扑排序
    {
        queue<int> q;
        for(int i = 1; i<=scc_cnt; i++)
        {
            if(!ind[i])
                q.push(i);
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(!color[u])
            {
                color[u] = 1;
                color[conf[u]] = 2; //conf数组记录的是与当前点冲突的点
            }
            for(int i = 0; i<nG[u].size(); i++)
            {
                int v = nG[u][i];
                ind[v]--;
                if(!ind[v])
                    q.push(v);
            }
        }
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        memset(mark,0,sizeof(mark));
        for(int i=0; i<m; i++)
        {
            int a,b;
            char c1,c2;
            scanf("%d%c%d%c",&a,&c1,&b,&c2);
            int u,v;
            u = c1=='w'?a<<1:a<<1|1;
            v = c2=='w'?b<<1:b<<1|1;
            if(u==0 || v==0)    //if bride conducts adulterous relationships with sb, he/she can be on both side (bride won't see who's at her side)
                continue;
            addEdge(u,v^1);
            addEdge(v,u^1);
        }
        addEdge(0,1);
    }

    void solve()
    {
        buildGraph();
        if(!check())
        {
            puts("bad luck");
            return ;
        }
        cal();
        topoSort();
        for(int i=1; i<n; i++)
        {
            if(color[belong[i<<1]]==color[belong[0]])
                printf("%dw",i);
            else
                printf("%dh",i);
            if(i==n-1)
                puts("");
            else
                printf(" ");
        }
    }
} twosat;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        twosat.init(n,m);
        twosat.solve();
    }
    return 0;
}
