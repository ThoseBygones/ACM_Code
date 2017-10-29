#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

//2-SAT模板

#define MAXN 405
#define MAXM 10005
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
    int s[MAXN<<1];
    int cnt,scc_cnt,dfs_clock;
    int n,m;

    stack <int> sta;

    int dfn[MAXN<<1];
    int low[MAXN<<1];
    int belong[MAXN<<1];
    int a[MAXM];
    int b[MAXM];
    int c[MAXM];

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

    void buildGraph(int x)
    {
        cnt = dfs_clock = 0;
        memset(dfn,0,sizeof(dfn));
        memset(belong,0,sizeof(belong));
        while(!sta.empty())
            sta.pop();
        for(int i = 0; i<2*n; i++) head[i] = -1,mark[i] = 0;
        for(int i=0; i<x; i++)
        {
            int u=a[i]<<1;
            int v=b[i]<<1;
            if(c[i]==0)
            {
                //a==0, b==1
                addEdge(u,v^1);
                addEdge(v,u^1);
                //a==1, b==0/1
            }
            else if(c[i]==1)
            {
                //a==0, b==0
                addEdge(u,v);
                addEdge(v,u);
                //a==1, b==1
                addEdge(u^1,v^1);
                addEdge(v^1,u^1);
            }
            else
            {
                //a==0, b==0/1
                //a==1, b==0
                addEdge(u^1,v);
                addEdge(v^1,u);
            }
        }
    }

    void solve()
    {
        for(int i=0; i<m; i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        int l=0,r=m;
        int ans=0;
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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        twosat.init(n,m);
        twosat.solve();
    }
    return 0;
}
