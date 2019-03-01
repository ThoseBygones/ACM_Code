/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-30
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: BZOJ
 *  Algorithm: 区间dp + 最短路 Dijkstra
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
#define MAXN 55
#define MAXM 105
#define MAXE (MAXN*MAXN)>>1

typedef int Type;

class Dijkstra
{
public:
    int head[MAXN],nxt[MAXE],cnt;
    Type d[MAXN];
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
    bool vis[MAXN];

    int stat[MAXM]; //stat[i]表示第i天的码头可用状态（0表示可用，1表示不可用）
    int c[MAXM][MAXM];    //c[i][j]记录第i天到第j天运输的最小花费
    int dp[MAXM];   //dp[i]表示前i天需要的最小花费
    int N,M,K,E;

    void init(int N,int M,int K,int E)
    {
        this -> N = N;
        this -> M = M;
        this -> K = K;
        this -> E = E;
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

    void dijkstra(int s,int sta)
    {
        for(int i = 0; i<=M; i++)
            d[i] = INF,vis[i] = false;
        d[s] = 0;
        priority_queue<Edge> q;
        q.push(Edge(s,0));
        while(!q.empty())
        {
            Edge ed = q.top();
            q.pop();
            if(vis[ed.v])
                continue;
            vis[ed.v] = true;
            for(int i = head[ed.v]; ~i; i = nxt[i])
            {
                Edge ee = e[i];
                if(sta & (1<<(ee.v-1))) //如果当天该码头不可用
                    continue;
                if(!vis[ee.v]&&d[ee.v]>d[ed.v]+ee.cost)
                {
                    d[ee.v] = d[ed.v]+ee.cost;
                    /*
                     *  最短路树
                    	p[ee.v] = MP(u,i);
                    */
                    q.push(Edge(ee.v,d[ee.v]));
                }
            }
        }
    }

    void buildGraph()
    {
        int u,v,w;
        for(int i = 0; i<E; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
            addEdge(v,u,w);
        }
    }

    void solve()
    {
        buildGraph();
        int D;
        scanf("%d",&D);
        while(D--)
        {
            int P,a,b;
            scanf("%d%d%d",&P,&a,&b);
            for(int i = a; i<=b; i++)
                stat[i] |= (1<<(P-1));
        }
        for(int i = 1; i<=N; i++)   //枚举起点天
        {
            int tmpstat = 0;    //当前码头可用状态
            for(int j = i; j<=N; j++)   //枚举结束天
            {
                tmpstat |= stat[j]; //获得该时间区间段的码头状态
                dijkstra(1,tmpstat);
                c[i][j] = d[M]; //记录该时间段可行的最短路
            }
        }
        for(int i = 1; i<=N; i++)
        {
            dp[i] = (c[1][i]<INF) ? (c[1][i] * i) : INF;    //初始化dp数组
            for(int j = 1; j<i; j++)
            {
                if(c[j+1][i] >= INF)    //该时间段没有可行的运输路径
                    continue;
                dp[i] = min(dp[i],dp[j]+c[j+1][i]*(i-j)+K); //第j天改变计划与不改变计划两种方案的最小值
            }
        }
        printf("%d\n",dp[N]);
    }
} dij;

int main()
{
    int n,m,k,e;
    scanf("%d%d%d%d",&n,&m,&k,&e);
    dij.init(n,m,k,e);
    dij.solve();
    return 0;
}
