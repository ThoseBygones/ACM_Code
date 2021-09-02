/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: 洛谷
 *  Algorithm: dfs + 反向建边 / Tarjan + 缩点 + 拓扑排序/dfs + dp
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 100005;


/* 解法一：反向图 dfs */

/*vector<int> G[MAXN];
int ans[MAXN];

void dfs(int u, int id)
{
    if(ans[u])  //该点能够到达的编号最大的值已知
        return ;
    ans[u] = id;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        dfs(v, id);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    while(m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[v].PB(u);
    }
    for(int i = n; i; i--)
        dfs(i, i);
    for(int i = 1; i <= n; i++)
        printf("%d%c", ans[i], (i == n ? '\n' : ' '));
    return 0;
}
*/


/* 解法二：tarjan + 缩点 + 拓扑排序 + dp */

/*const int MAXE = 100005;

class SCC
{
public:
    int head[MAXN];
    struct Edge
    {
        int to,next;
        Edge() {}
        Edge(int to, int next) : to(to), next(next) {}
    } e[MAXE];

    void addEdge(int u, int v)
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
    //int outd[MAXN]; //出度

    stack <int> sta;
    vector <int> nG[MAXN];  //缩点后得到的新图

    int n, m;
    int cnt;
    int dfs_clock, scc_cnt;

    int maxid[MAXN];
    int dp[MAXN];

    void init(int n, int m)
    {
        this -> n = n;
        this -> m = m;
        dfs_clock = scc_cnt = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(belong, 0, sizeof(belong));
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
                low[u] = min(low[u], low[v]);
            }
            //else if(instack[v])
            else if(!belong[v])
                low[u] = min(low[u], dfn[v]);
        }
        if(dfn[u] == low[u])
        {
            scc_cnt++;
            while(!sta.empty())
            {
                int temp = sta.top();
                //instack[v] = false;
                belong[temp] = scc_cnt;
                maxid[scc_cnt] = max(maxid[scc_cnt], temp);
                sta.pop();
                if(u == temp)
                    break;
            }
        }
    }

    void get_scc()    //缩点
    {
        memset(ind, 0, sizeof(ind));
        //memset(outd, 0, sizeof(outd));
        for(int i = 1; i <= n; i++)
        {
            for(int j = head[i]; ~j; j = e[j].next)
            {
                int v = e[j].to;
                if(belong[i] != belong[v])
                {
                    ind[belong[v]]++;
                    //outd[belong[i]]++;
                    nG[belong[i]].push_back(belong[v]);
                }
            }
        }
    }

    void topoSort() //拓扑排序
    {
        queue <int> q;
        for(int i = 1; i <= scc_cnt; i++)
        {
            if(!ind[i])
                q.push(i);
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            dp[u] = max(dp[u], maxid[u]);
            for(int i = 0; i < nG[u].size(); i++)
            {
                int v = nG[u][i];
                dp[v] = max(dp[u], dp[v]);
                if(!--ind[v])
                    q.push(v);
            }
        }
    }

    void buildGraph()
    {
        cnt = 0;
        memset(head, -1, sizeof(head));
        while(m--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(v, u);
        }
    }

    void solve()    //求有向图的强连通分量
    {
        buildGraph();
        for(int i = 1; i <= n; i++)   //点的编号从1开始
        {
            if(!dfn[i])
                tarjan(i);
        }
        get_scc();
        topoSort();
        for(int i = 1; i <= n; i++)
            printf("%d%c", dp[belong[i]], (i == n ? '\n' : ' '));
    }
} scc;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scc.init(n, m);
    scc.solve();
    return 0;
}
*/

/* 解法三：tarjan + 缩点 + dfs + dp */

const int MAXE = 100005;

class SCC
{
public:
    int head[MAXN];
    struct Edge
    {
        int to,next;
        Edge() {}
        Edge(int to, int next) : to(to), next(next) {}
    } e[MAXE];

    void addEdge(int u, int v)
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
    //int outd[MAXN]; //出度

    stack <int> sta;
    vector <int> nG[MAXN];  //缩点后得到的新图

    int n, m;
    int cnt;
    int dfs_clock, scc_cnt;

    int maxid[MAXN];
    bool vis[MAXN];
    int dp[MAXN];

    void init(int n, int m)
    {
        this -> n = n;
        this -> m = m;
        dfs_clock = scc_cnt = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(belong, 0, sizeof(belong));
        memset(vis, false, sizeof(vis));
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
                low[u] = min(low[u], low[v]);
            }
            //else if(instack[v])
            else if(!belong[v])
                low[u] = min(low[u], dfn[v]);
        }
        if(dfn[u] == low[u])
        {
            scc_cnt++;
            while(!sta.empty())
            {
                int temp = sta.top();
                //instack[v] = false;
                belong[temp] = scc_cnt;
                maxid[scc_cnt] = max(maxid[scc_cnt], temp);
                sta.pop();
                if(u == temp)
                    break;
            }
        }
    }

    void get_scc()    //缩点
    {
        //memset(ind, 0, sizeof(ind));
        //memset(outd, 0, sizeof(outd));
        for(int i = 1; i <= n; i++)
        {
            for(int j = head[i]; ~j; j = e[j].next)
            {
                int v = e[j].to;
                if(belong[i] != belong[v])
                {
                    //ind[belong[v]]++;
                    //outd[belong[i]]++;
                    nG[belong[i]].push_back(belong[v]);
                }
            }
        }
    }

    void dfs(int u)
    {
        dp[u] = maxid[u];
        vis[u] = true;
        for(int i = 0; i < nG[u].size(); i++)
        {
            int v = nG[u][i];
            if(!vis[v])
                dfs(v);
            dp[u] = max(dp[u], dp[v]);
        }
    }

    void buildGraph()
    {
        cnt = 0;
        memset(head, -1, sizeof(head));
        while(m--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
    }

    void solve()    //求有向图的强连通分量
    {
        buildGraph();
        for(int i = 1; i <= n; i++)   //点的编号从1开始
        {
            if(!dfn[i])
                tarjan(i);
        }
        get_scc();
        for(int i = 1; i <= scc_cnt; i++)
        {
            if(!vis[i])
                dfs(i);
        }
        for(int i = 1; i <= n; i++)
            printf("%d%c", dp[belong[i]], (i == n ? '\n' : ' '));
    }
} scc;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scc.init(n, m);
    scc.solve();
    return 0;
}
