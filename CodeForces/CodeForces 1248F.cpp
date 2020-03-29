/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-28
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: Tarjan求有向图强连通分量 + 缩点 / Tarjan求解2-sat问题
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

/* 解法一：Tarjan强连通分量缩点 (545ms) */

#define MAXN 1000005
#define MAXE 1000005

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
    int outd[MAXN]; //出度

    stack <int> sta;

    int n,m;
    int cnt;
    int dfs_clock,scc_cnt;

    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
        dfs_clock = scc_cnt = 0;
        cnt = 0;
        for(int i = 0; i <= n; i++)
        {
            head[i] = -1;
            dfn[i] = 0;
            belong[i] = 0;
            outd[i] = 0;
        }
    }

    void tarjan(int u)
    {
        dfn[u] = low[u] = ++dfs_clock;
        sta.push(u);
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!dfn[v])
            {
                tarjan(v);
                low[u] = min(low[u],low[v]);
            }
            else if(!belong[v])
                low[u] = min(low[u],dfn[v]);
        }
        if(dfn[u]==low[u])
        {
            scc_cnt++;
            while(!sta.empty())
            {
                int temp = sta.top();
                belong[temp] = scc_cnt;
                sta.pop();
                if(u==temp)
                    break;
            }
        }
    }

    void get_scc()    //缩点
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = head[i]; ~j; j = e[j].next)
            {
                int v = e[j].to;
                if(belong[i] != belong[v])
                    outd[belong[i]]++;
            }
        }
    }

    void buildGraph()
    {
        for(int i = 0; i < m; i++)  //人和认识的猫连边
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
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
        if(scc_cnt == 1)    //如果只有一个强连通分量，说明不存在符合条件的选择方案
            puts("No");
        else
        {
            int pos = 1;
            for(int i = 1; i <= scc_cnt; i++)   //找到出度为0的强连通分量（缩点后的点）
            {
                if(!outd[i])
                {
                    pos = i;
                    break;
                }
            }
            vector<int> ans1, ans2;
            for(int i = 1; i <= n; i++)
            {
                if(belong[i] == pos) //将属于该出度为0的强连通分量的编号对应的人作为jury
                    ans1.PB(i);
                else    //不属于的猫作为contestant
                    ans2.PB(i);
            }
            puts("Yes");
            printf("%d %d\n", ans1.size(), ans2.size());
            for(int i = 0; i < ans1.size(); i++)
                printf("%d%c", ans1[i], (i == ans1.size() - 1 ? '\n' : ' '));
            for(int i = 0; i < ans2.size(); i++)
                printf("%d%c", ans2[i], (i == ans2.size() - 1 ? '\n' : ' '));
        }
    }
} scc;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        scc.init(n, m);
        scc.solve();
    }
    return 0;
}


/* 解法二：2-sat (545ms) */

#define MAXN 2000005
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

    stack <int> sta;

    int n,m;
    int cnt;
    int dfs_clock,scc_cnt;

    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
        dfs_clock = scc_cnt = 0;
        cnt = 0;
        for(int i = 0; i <= 2 * n; i++)
        {
            head[i] = -1;
            dfn[i] = 0;
            belong[i] = 0;
        }
        while(!sta.empty())
            sta.pop();
    }

    void tarjan(int u)
    {
        dfn[u] = low[u] = ++dfs_clock;
        sta.push(u);
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!dfn[v])
            {
                tarjan(v);
                low[u] = min(low[u],low[v]);
            }
            else if(!belong[v])
                low[u] = min(low[u],dfn[v]);
        }
        if(dfn[u]==low[u])
        {
            scc_cnt++;
            while(!sta.empty())
            {
                int temp = sta.top();
                belong[temp] = scc_cnt;
                sta.pop();
                if(u==temp)
                    break;
            }
        }
    }

    void buildGraph()
    {
        for(int i = 0; i < m; i++)  //人和认识的猫连边
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v + n);
        }
        for(int i = 1; i <= n; i++) //自家的猫和人连边
            addEdge(i + n, i);
    }

    void solve()    //求有向图的强连通分量
    {
        buildGraph();
        for(int i = 1; i<=n; i++)   //点的编号从1开始
        {
            if(!dfn[i])
                tarjan(i);
        }
        if(scc_cnt == 1)    //如果只有一个强连通分量，说明不存在符合条件的选择方案
            puts("No");
        else
        {
            vector<int> ans1, ans2;
            for(int i = 1; i <= n; i++)
            {
                if(belong[i] == 1) //将属于该出度为0的强连通分量的编号对应的人作为jury
                    ans1.PB(i);
                else    //不属于的猫作为contestant
                    ans2.PB(i);
            }
            puts("Yes");
            printf("%d %d\n", ans1.size(), ans2.size());
            for(int i = 0; i < ans1.size(); i++)
                printf("%d%c", ans1[i], (i == ans1.size() - 1 ? '\n' : ' '));
            for(int i = 0; i < ans2.size(); i++)
                printf("%d%c", ans2[i], (i == ans2.size() - 1 ? '\n' : ' '));
        }
    }
} scc;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        scc.init(n, m);
        scc.solve();
    }
    return 0;
}
