#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 2005
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

    struct Ceremony
    {
        int s,t;
        Ceremony() {}
        Ceremony(int s,int t):s(s),t(t) {}
    } p[MAXN<<1];

    int mark[MAXN<<1];  //mark[i<<1]==1，表示点i被选择；mark[i<<1|1]==1，表示点i没有被选择
    int cnt,scc_cnt,dfs_clock;
    int n,m;
    int top;

    stack <int> sta;
    vector <int> nG[MAXN];    //缩点后建立的新图

    int dfn[MAXN<<1];
    int low[MAXN<<1];
    int belong[MAXN<<1];
    int color[MAXN<<1]; //求解任意一组可行解时记录点的颜色
    int conf[MAXN<<1];  //记录新图中的冲突点
    int ind[MAXN<<1];  //入度

    //使用前调用
    void init(int n)
    {
        this -> n = n;
        cnt = scc_cnt = dfs_clock = 0;
        top = 0;
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

    bool conflict(int x,int y)
    {
        if(p[x].t<=p[y].s || p[y].t<=p[x].s)
            return false;
        return true;
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        memset(mark,0,sizeof(mark));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                int u=i<<1;
                int v=j<<1;
                if(conflict(u,v))
                    addEdge(u,v^1);
                if(conflict(u,v^1))
                    addEdge(u,v);
                if(conflict(u^1,v))
                    addEdge(u^1,v^1);
                if(conflict(u^1,v^1))
                    addEdge(u^1,v);
            }
        }
    }

    void solve()
    {
        int hh1,mm1,hh2,mm2,d;
        for(int i=0; i<n; i++)
        {
            scanf("%d:%d %d:%d %d",&hh1,&mm1,&hh2,&mm2,&d);
            p[i<<1].s=hh1*60+mm1;
            p[i<<1].t=hh1*60+mm1+d;
            p[i<<1|1].s=hh2*60+mm2-d;
            p[i<<1|1].t=hh2*60+mm2;
        }
        buildGraph();
        if(!check())
        {
            puts("NO");
            return ;
        }
        cal();
        topoSort();
        puts("YES");
        for(int i=0; i<n; i++)
        {
            if(color[belong[i<<1]]==1)
                printf("%02d:%02d %02d:%02d\n",p[i<<1].s/60,p[i<<1].s%60,p[i<<1].t/60,p[i<<1].t%60);
            else
                printf("%02d:%02d %02d:%02d\n",p[i<<1|1].s/60,p[i<<1|1].s%60,p[i<<1|1].t/60,p[i<<1|1].t%60);
        }
    }
} twosat;

int main()
{
    int n;
    scanf("%d",&n);
    twosat.init(n);
    twosat.solve();
    return 0;
}
