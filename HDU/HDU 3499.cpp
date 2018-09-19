/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-09-19
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 分层图最短路（dijkstra）+ STL Map
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
#define MAXE 500010

typedef LL Type;

class Dijkstra
{
public:
    int head[MAXN],nxt[MAXE],cnt;
    Type d[MAXN][2];
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
    bool vis[MAXN][2];

    struct Node
    {
        int v,lv;
        Type cost;
        Node() {}
        Node(int v,int lv,Type cost):v(v),lv(lv),cost(cost) {}
        bool operator<(const Node& nd) const
        {
            return cost>nd.cost;
        }
    };

    map<string,int> mp;

    //初始化，n为点数
    void init(int n)
    {
        cnt = 0;
        for(int i = 0; i<n; i++)
            head[i] = -1;
    }

    inline void addEdge(int u,int v,Type cost)
    {
        e[cnt] = Edge(v,cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    void dijkstra(int s,int n)
    {
        for(int i = 0; i<=n; i++)
        {
            for(int j=0; j<=1; j++)
                d[i][j] = LINF,vis[i][j] = false;
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
                if(nd.lv+1<=1&&!vis[ee.v][nd.lv]&&d[ee.v][nd.lv+1]>d[nd.v][nd.lv]+ee.cost/2) //转移到本层
                {
                    d[ee.v][nd.lv+1] = d[nd.v][nd.lv]+ee.cost/2;
                    q.push(Node(ee.v,nd.lv+1,d[ee.v][nd.lv+1]));
                }
            }
        }
    }

    void buildGraph(int m)
    {
        mp.clear();
        int tot=0;
        for(int i=0; i<m; i++)
        {
            string u,v;
            LL c;
            cin >> u >> v >> c;
            if(!mp[u])
                mp[u]=++tot;
            if(!mp[v])
                mp[v]=++tot;
            addEdge(mp[u],mp[v],c);
        }
    }

    void solve(int n,int m)
    {
        buildGraph(m);
        string s,t;
        cin >> s >> t;
        if(!mp[s] || !mp[t])
            cout << "-1" << endl;
        else
        {
            dijkstra(mp[s],n);
            LL ans=min(d[mp[t]][0],d[mp[t]][1]);
            if(ans==LINF)
                cout << "-1" << endl;
            else
                cout << ans << endl;
        }
    }
} dij;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin >> n >> m)
    {
        dij.init(n);
        dij.solve(n,m);
    }
    return 0;
}
