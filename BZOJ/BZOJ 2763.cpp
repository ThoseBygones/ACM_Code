/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-09-19
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: BZOJ
 *  Algorithm: 分层图最短路（SPFA）
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
#define MAXN 10005
#define MAXE 100010

typedef int Type;

class SPFA
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
    } e[MAXE];

    bool inq[MAXN][12];

    struct Node
    {
        int v,lv;
        Node() {}
        Node(int v,int lv):v(v),lv(lv) {}
    };

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

    void spfa(int s,int n,int k)
    {
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<=k; j++)
                inq[i][j] = false,d[i][j] = INF;
        }
        d[s][0] = 0;
        queue<Node> q;
        q.push(Node(s,0));
        while(!q.empty())
        {
            Node x = q.front();
            q.pop();
            inq[x.v][x.lv] = false;
            for(int i = head[x.v]; ~i; i = nxt[i])
            {
                Edge ed = e[i];
                if(d[ed.v][x.lv]>d[x.v][x.lv]+ed.cost)  //转移至本层
                {
                    d[ed.v][x.lv] = d[x.v][x.lv]+ed.cost;
                    if(!inq[ed.v][x.lv])
                    {
                        inq[ed.v][x.lv] = true;
                        q.push(Node(ed.v,x.lv));
                    }
                }
                if(x.lv+1<=k&&d[ed.v][x.lv+1]>d[x.v][x.lv])  //转移至下层
                {
                    d[ed.v][x.lv+1] = d[x.v][x.lv];
                    if(!inq[ed.v][x.lv+1])
                    {
                        inq[ed.v][x.lv+1] = true;
                        q.push(Node(ed.v,x.lv+1));
                    }
                }
            }
        }
    }

    void buildGraph(int n,int m)
    {
        for(int i=0; i<m; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            addEdge(u,v,c);
            addEdge(v,u,c);
        }
    }

    void solve(int n,int m,int k,int s,int t)
    {
        buildGraph(n,m);
        spfa(s,n,k);
        int ans=d[t][0];
        for(int i=0; i<=k; i++)
            ans=min(ans,d[t][i]);
        printf("%d\n",ans);
    }
} spfa;

int main()
{
    int n,m,k,s,t;
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&s,&t);
    spfa.init(n);
    spfa.solve(n,m,k,s,t);
    return 0;
}
