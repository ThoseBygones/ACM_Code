#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

#define MAXN 505
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

    int b[MAXN][MAXN];

    //使用前调用
    void init(int n)
    {
        this -> n = n;
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

    void buildGraph(int val)
    {
        memset(head,-1,sizeof(head));
        memset(mark,0,sizeof(mark));
        cnt = scc_cnt = dfs_clock = 0;
        memset(dfn,0,sizeof(dfn));
        memset(belong,0,sizeof(belong));
        while(!sta.empty())
            sta.pop();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int k=b[i][j]&(1<<val);
                int u=i<<1;
                int v=j<<1;
                if((i&1)&&(j&1))    //OR
                {
                    if(k)   //OR==1
                    {
                        addEdge(u^1,v);
                        addEdge(v^1,u);
                    }
                    else    //OR==0
                    {
                        addEdge(u,u^1);
                        addEdge(v,v^1);
                    }
                }
                else if(!(i&1)&&!(j&1))  //AND
                {
                    if(k)   //AND==1
                    {
                        addEdge(u^1,u);
                        addEdge(v^1,v);
                    }
                    else    //AND==0
                    {
                        addEdge(u,v^1);
                        addEdge(v,u^1);
                    }
                }
                else    //XOR
                {
                    if(k)   //XOR==1
                    {
                        addEdge(u,v^1);
                        addEdge(v,u^1);
                        addEdge(u^1,v);
                        addEdge(v^1,u);
                    }
                    else    //XOR==0
                    {
                        addEdge(u,v);
                        addEdge(v,u);
                        addEdge(u^1,v^1);
                        addEdge(v^1,u^1);
                    }
                }
            }
        }
    }

    bool solve()
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d",&b[i][j]);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j&&b[i][j])
                    return false;
                if(b[i][j]!=b[j][i])
                    return false;
            }
        }
        for(int k=0; k<31; k++)
        {
            buildGraph(k);
            if(!check())
                return false;
        }
        return true;
    }
} twosat;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        twosat.init(n);
        if(twosat.solve())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
