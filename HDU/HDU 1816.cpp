#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

//2-SAT模板

#define MAXN (1<<10)+10
#define MAXM (1<<11)+10
#define MAXE (1<<12)+10

class TwoSat
{
public:
    int head[MAXE<<1];
    struct Edge
    {
        int to,next;
        Edge() {}
        Edge(int to,int next):to(to),next(next) {}
    } e[MAXE<<2];

    int mark[MAXE<<1];  //mark[i<<1]==1，表示点i被选择；mark[i<<1|1]==1，表示点i没有被选择
    int c,cnt,scc_cnt,dfs_clock;
    int n,m;

    stack <int> sta;

    int dfn[MAXE<<1];
    int low[MAXE<<1];
    int belong[MAXE<<1];

    int key1[MAXN];
    int key2[MAXN];
    int lock1[MAXM];
    int lock2[MAXM];

    //使用前调用
    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
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
                belong[temp] = scc_cnt;
                mark[temp] = 2;
                sta.pop();
            }
            while(temp!=u);
            scc_cnt++;
        }
    }

    bool check()    //利用强连通缩点判断2-SAT问题是否有解
    {
        for(int i = 0; i<4*n; i++)
        {
            if(!mark[i])
                tarjan(i);
        }
        for(int i = 0; i<2*n; i++)
        {
            if(belong[i<<1]==belong[i<<1|1])
                return false;
        }
        return true;
    }

    void buildGraph(int x)
    {
        cnt = scc_cnt = dfs_clock = 0;
        memset(dfn,0,sizeof(dfn));
        memset(belong,0,sizeof(belong));
        while(!sta.empty())
            sta.pop();
        for(int i = 0; i<4*n; i++) head[i] = -1,mark[i] = 0;
        for(int i=0; i<n; i++)
        {
            int u=key1[i]<<1;
            int v=key2[i]<<1;
            //用key1，key2就不能用
            addEdge(u,v^1);
            //用key2，key1就不能用
            addEdge(v,u^1);
        }
        for(int i=0; i<x; i++)
        {
            int u=lock1[i]<<1;
            int v=lock2[i]<<1;
            //不开lock1就必须开lock2
            addEdge(u^1,v);
            //不开lock2就必须开lock1
            addEdge(v^1,u);
        }
    }

    void solve()
    {
        for(int i=0; i<n; i++)
            scanf("%d%d",&key1[i],&key2[i]);
        for(int i=0; i<m; i++)
            scanf("%d%d",&lock1[i],&lock2[i]);
        int l=0,r=m;
        int ans;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            buildGraph(mid);
            if(check())
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        printf("%d\n",ans);
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
}
