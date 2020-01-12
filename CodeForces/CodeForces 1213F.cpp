/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-01
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 有向图强联通分量Tarjan算法 + 缩点 + 拓扑排序
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
using namespace std;
template<class T> inline T sqr(T x)
{
    return x * x;
}
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 200005

class SCC
{
public:
    int head[MAXN];
    struct Edge
    {
        int to,next;
        Edge() {}
        Edge(int to,int next):to(to),next(next) {}
    } e[MAXN<<1];

    void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    int belong[MAXN];
    int dfn[MAXN];
    int low[MAXN];
    //bool instack[MAXN<<1];
    int ind[MAXN];  //入度
    int outd[MAXN]; //出度

    stack <int> sta;
    vector <int> nG[MAXN];  //缩点后得到的新图

    int n,k;
    int cnt;
    int dfs_clock,scc_cnt;

    char ans[MAXN];

    void init(int n,int k)
    {
        this -> n = n;
        this -> k = k;
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

    void get_scc()    //缩点
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
                    nG[belong[i]].push_back(belong[v]);
                }
            }
        }
    }

    void topoSort() //拓扑排序
    {
        queue <int> q;
        for(int i = 1; i<=scc_cnt; i++)
        {
            if(!ind[i])
                q.push(i);
        }
        int id = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            ans[u] = id + 'a';
            if(id < 25)
                id++;
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
        cnt = 0;
        memset(head,-1,sizeof(head));
        int u,v;
        scanf("%d",&u);
        for(int i=1; i<n; i++)
        {
            scanf("%d",&v);
            addEdge(u,v);
            u = v;
        }
        scanf("%d",&u);
        for(int i=1; i<n; i++)
        {
            scanf("%d",&v);
            addEdge(u,v);
            u = v;
        }
    }

    void solve()    //求有向图的强连通分量
    {
        buildGraph();
        for(int i = 1; i<=n; i++)   //点的编号从1开始
        {
            if(!dfn[i])
                tarjan(i);
        }
        if(scc_cnt < k)
        {
            puts("NO");
            return ;
        }
        get_scc();
        topoSort();
        puts("YES");
        for(int i=1; i<=n; i++)
            printf("%c",ans[belong[i]]);
        puts("");
    }
} scc;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scc.init(n,k);
    scc.solve();
    return 0;
}
