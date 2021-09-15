/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-09-14
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 最短路Dijkstra + dp
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

template<class T> inline T sqr(T x) {return x * x;}
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

const int MAXN = 1005;
const int MAXE = 20005;

typedef int Type;

class Dijkstra
{
public:
    int head[MAXN], nxt[MAXE], cnt;
    Type dp[MAXN][105]; //dp[i][j]表示在结点i，当前邮箱油量为j时的最小花费
    struct Edge
    {
        int v;
        Type cost;
        Edge() {}
        Edge(int v, Type cost) : v(v), cost(cost) {}
    } e[MAXE];
    bool vis[MAXN][105];
    int n, m;

    struct Node
    {
        int u, cap, cost;
        Node() {}
        Node(int u, int cap, int cost) : u(u), cap(cap), cost(cost) {}
        bool operator < (const Node& nd) const
        {
            return cost > nd.cost;
        }
    };

    int price[MAXN];

    //初始化，n为点数，m为边数
    void init(int n, int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = 0;
        memset(head, -1, sizeof(head));
    }

    inline void addEdge(int u, int v, Type cost)
    {
        e[cnt] = Edge(v, cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    Type dijkstra(int s, int t, int Max)
    {
        for(int i = 0; i < n; i++)
            fill(dp[i], dp[i] + 105, INF);
        memset(vis, false, sizeof(vis));
        dp[s][0] = 0;
        priority_queue<Node> q;
        q.push(Node(s, 0, 0));
        while(!q.empty())
        {
            Node cur = q.top();
            q.pop();
            if(vis[cur.u][cur.cap])   //没有该判断会TLE
                continue;
            vis[cur.u][cur.cap] = true;
            if(cur.u == t)
                return cur.cost;
            //油还未加满，则可以考虑停留在原地加1个单位的燃油
            if(cur.cap < Max && !vis[cur.u][cur.cap + 1] && dp[cur.u][cur.cap + 1] > dp[cur.u][cur.cap] + price[cur.u])
            {
                dp[cur.u][cur.cap + 1] = dp[cur.u][cur.cap] + price[cur.u];
                q.push(Node(cur.u, cur.cap + 1, dp[cur.u][cur.cap + 1]));
            }
            //油足够往下一个地点出发，则考虑去下一个地点
            for(int i = head[cur.u]; ~i; i = nxt[i])
            {
                Edge ee = e[i];
                if(cur.cap >= ee.cost && !vis[ee.v][cur.cap - ee.cost] && dp[ee.v][cur.cap - ee.cost] > cur.cost)
                {
                    dp[ee.v][cur.cap - ee.cost] = cur.cost;
                    q.push(Node(ee.v, cur.cap - ee.cost, dp[ee.v][cur.cap - ee.cost]));
                }
            }
        }
        return -1;
    }

    void buildGraph()
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &price[i]);
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
    }

    void solve()
    {
        buildGraph();   //建图
        int q;
        scanf("%d", &q);
        while(q--)
        {
            int sum, u, v;
            scanf("%d%d%d", &sum, &u, &v);
            int ans = dijkstra(u, v, sum);
            if(~ans)
                printf("%d\n", ans);
            else
                puts("impossible");
        }
    }
} dij;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    dij.init(n, m);
    dij.solve();
    return 0;
}
