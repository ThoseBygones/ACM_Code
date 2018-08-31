/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-08-05
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: AOJ
 *  Algorithm:
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
#define MAXE 400005

class CUT
{
public:
    int head[MAXN];
    int cnt;
    struct Edge
    {
        int to,nxt;
        Edge() {}
        Edge(int to,int nxt):to(to),nxt(nxt) {}
    } e[MAXE];

    int cut[MAXN],dfn[MAXN],low[MAXN],bridge[MAXN<<1];
    int dfs_clock;

    void init(int n,int m)
    {
        memset(head,-1,sizeof(head));
        cnt = dfs_clock = 0;
        for(int i=0; i<n; i++)
            cut[i] = false;
        for(int i=0; i<m; i++)
            bridge[i] = false;
    }

    inline void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].nxt = head[u];
        head[u] = cnt++;
    }

    int dfs(int u,int fa)
    {
        int lowu = dfn[u] = ++dfs_clock;
        int child = 0;
        for(int i=head[u]; ~i; i=e[i].nxt)
        {
            int v = e[i].to;
            if(!dfn[v])
            {
                child++;
                int lowv = dfs(v,u);
                lowu = min(lowu,lowv);
                if(lowv >= dfn[u])
                    cut[u] = true;
                if(lowv > dfn[u])
                    bridge[i] = true;
            }
            else if(dfn[v] < dfn[u] && v != fa)
                lowu = min(lowu,dfn[v]);
        }
        if(fa == -1 && child == 1)
            cut[u] = 0;
        low[u] = lowu;
        return lowu;
    }

    void buildGraph(int m)
    {
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
    }

    void solve(int n,int m)
    {
        buildGraph(m);
        for(int i=0; i<n; i++)
        {
            if(!dfn[i])
                dfs(i,-1);
        }
        for(int i=0; i<n; i++)
        {
            if(cut[i])
                printf("%d\n",i);
        }
    }
} cut;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    cut.init(n,m);
    cut.solve(n,m);
    return 0;
}
