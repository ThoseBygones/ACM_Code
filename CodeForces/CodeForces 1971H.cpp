/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 2-sat
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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

const int MAXN = 505;
const int MAXE = (MAXN << 1) * 6;

class TwoSat
{
public:
    int head[MAXN << 1];
    struct Edge
    {
        int to, next;
        Edge() {}
        Edge(int to, int next) : to(to), next(next) {}
    } e[MAXE];

    int mark[MAXN << 1];  //mark[i] == 1，表示点 i 取值为 1；mark[i + n] == 1，表示点 i 取值为 -1
    int cnt, scc_cnt, dfs_clock;
    int n, m;
    int top;

    stack <int> sta;

    int dfn[MAXN << 1];
    int low[MAXN << 1];
    int belong[MAXN << 1];

    int a[MAXN][3];

    //使用前调用
    void init(int n)
    {
        this -> n = n;
        cnt = scc_cnt = dfs_clock = 0;
        top = 0;
        for(int i = 0; i <= 2 * n; i++)
            dfn[i] = belong[i] = 0;
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
                low[u] = min(low[u], low[v]);
            }
            if(mark[v] == 1)
                low[u] = min(low[u], dfn[v]);
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
        for(int i = 1; i <= 2 * n; i++)
        {
            if(!mark[i])
                tarjan(i);
        }
        for(int i = 1; i <= n; i++)
        {
            if(belong[i] == belong[i + n])  //判断 x = 1 和 x = -1 两个点是否在一个连通分量内，是则存在冲突
                return false;
        }
        return true;
    }

    int cNode(int x)
    {
        if(x < 0)
            x = -x + n;
        return x;
    }

    void buildGraph()
    {
        /* 两个点至少有一个取值为 1：-x -> y, -y -> x （点 -x 到点 y 连边;点 -y 到点 x 连边）*/
        for(int i = 1; i <= n; i++) //枚举每一列
        {
            //a[i][0] 和 a[i][1] 两个点至少有一个为 1
            addEdge(cNode(-a[i][0]), cNode(a[i][1]));   //建边 -x -> y
            addEdge(cNode(-a[i][1]), cNode(a[i][0]));   //建边 -y -> x
            //a[i][0] 和 a[i][2] 两个点至少有一个为 1
            addEdge(cNode(-a[i][0]), cNode(a[i][2]));   //建边 -x -> z
            addEdge(cNode(-a[i][2]), cNode(a[i][0]));   //建边 -z -> x
            //a[i][1] 和 a[i][2] 两个点至少有一个为 1
            addEdge(cNode(-a[i][1]), cNode(a[i][2]));   //建边 -y -> z
            addEdge(cNode(-a[i][2]), cNode(a[i][1]));   //建边 -z -> y
        }
    }

    void solve()
    {
        memset(head, -1, sizeof(head));
        memset(mark, 0, sizeof(mark));
        for(int j = 0; j < 3; j++)
        {
            for(int i = 1; i <= n; i++)
                scanf("%d", &a[i][j]);
        }
        buildGraph();
        puts(check() ? "YES" : "NO");
    }
} twosat;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        twosat.init(n);
        twosat.solve();
    }
    return 0;
}
