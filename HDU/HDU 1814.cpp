#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
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
    } e[MAXE];

    int mark[MAXN<<1];  //mark[i<<1]==1，表示点i被选择；mark[i<<1|1]==1，表示点i没有被选择
    int cnt,scc_cnt,dfs_clock;
    int n,m;
    int top;

    //stack <int> sta;
    //vector <int> nG[MAXN];    //缩点后建立的新图

    int dfn[MAXN<<1];
    int low[MAXN<<1];
    //int belong[MAXN<<1];
    //int color[MAXN<<1]; //求解任意一组可行解时记录点的颜色
    int sta[MAXN<<1];   //数组模拟栈
    //int conflict[MAXN<<1];  //记录新图中的冲突点
    //int indegree[MAXN<<1];  //入度

    //使用前调用
    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = scc_cnt = dfs_clock = 0;
        memset(dfn,0,sizeof(dfn));
        //memset(belong,0,sizeof(belong));
        //memset(color,0,sizeof(color));
        //memset(conflict,0,sizeof(conflict));
        //memset(indegree,0,sizeof(indegree));
        //for(int i=0; i<MAXN; i++)
        //    nG[i].clear();
        //while(!sta.empty())
        //    sta.pop();
    }

    inline void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    /*暴力求2-SAT问题的字典序最小解（复杂度O(n*m)）*/
    bool dfs(int u) //判断当前的强连通分量当中有没有出现矛盾
    {
        if(mark[u^1]) return false; //如果需要被选的不能被选那么矛盾
        if(mark[u]) return true;    //如果需要被选的已经被选，那么当前联通分量一定不会出现矛盾
        mark[u] = true; //如果当前点需要被选，那么选上它，并且标记
        sta[top++] = u; //当前的强连通分量加上这个点
        //找到与当前点相连点，判断他们的状态
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!dfs(v))
                return false;
        }
        return true;
    }

    bool solve()
    {
        for(int i = 0; i<n*2; i+=2)
        {
            if(!mark[i]&&!mark[i^1])
            {
                top = 0;
                if(!dfs(i)) //如果矛盾，那么这个强连通分量里的点都不能选取
                {
                    while(top>0)
                        mark[sta[--top]] = false;
                    if(!dfs(i^1))
                        return false;
                }
            }
        }
        return true;
    }

    void buildGraph()
    {
        for(int i = 0; i<2*n; i++) head[i] = -1,mark[i] = 0;
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--;
            b--;
            addEdge(a,b^1);
            addEdge(b,a^1);
        }
        if(!solve())
            puts("NIE");
        else
        {
            for(int i=0; i<2*n; i++)
            {
                if(mark[i])
                    printf("%d\n",i+1);
            }
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
    }
    return 0;
}
