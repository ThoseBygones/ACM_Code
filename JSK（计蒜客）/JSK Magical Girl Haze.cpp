/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-09-18
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: JSK（计蒜客）
 *  Algorithm: 分层图最短路dij
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

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
#define MAXN 100005
#define MAXE 200010

typedef int Type;

class Dijkstra
{
public:
    int head[MAXN],nxt[MAXE],cnt;
    Type d[MAXN][12];
    struct Edge
    {
        int v;
        Type cost;
        Edge() {}
        Edge(int v,Type cost):v(v),cost(cost) {}
        bool operator<(const Edge& ed) const
        {
            return cost>ed.cost;
        }
    } e[MAXE];
    bool vis[MAXN][12];

    struct Node
    {
        int v,lv,cost;
        Node() {}
        Node(int v,int lv,int cost):v(v),lv(lv),cost(cost) {}
        bool operator<(const Node& nd) const
        {
            return cost>nd.cost;
        }
    };

    //初始化，n为点数
    void init(int n)
    {
        cnt = 0;
        memset(head,-1,sizeof(head));
    }

    inline void addEdge(int u,int v,Type cost)
    {
        e[cnt] = Edge(v,cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    void dijkstra(int s,int n,int k)
    {
        for(int i = 0; i<=n; i++)
        {
            for(int j=0; j<=k; j++)
                d[i][j] = INF,vis[i][j] = false;
        }
        d[s][0] = 0;
        priority_queue<Node> q;
        q.push(Node(s,0,0));
        while(!q.empty())
        {
            Node nd = q.top();
            q.pop();
            vis[nd.v][nd.lv] = true;
            for(int i = head[nd.v]; ~i; i = nxt[i])
            {
                Edge ee = e[i];
                if(!vis[ee.v][nd.lv]&&d[ee.v][nd.lv]>d[nd.v][nd.lv]+ee.cost) //转移到本层
                {
                    d[ee.v][nd.lv] = d[nd.v][nd.lv]+ee.cost;
                    q.push(Node(ee.v,nd.lv,d[ee.v][nd.lv]));
                }
                if(nd.lv+1<=k&&!vis[ee.v][nd.lv]&&d[ee.v][nd.lv+1]>d[nd.v][nd.lv]) //转移到下层
                {
                    d[ee.v][nd.lv+1] = d[nd.v][nd.lv];
                    q.push(Node(ee.v,nd.lv+1,d[ee.v][nd.lv+1]));
                }
            }
        }
    }

    void buildGraph(int n,int m,int k)
    {
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
        }
    }

    void solve(int n,int m,int k)
    {
        init(n);
        buildGraph(n,m,k);
        dijkstra(1,n,k);
        int ans=d[n][0];
        for(int i=1; i<=k; i++)
            ans=min(ans,d[n][i]);
        printf("%d\n",ans);
    }
} dij;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        dij.solve(n,m,k);
    }
    return 0;
}
