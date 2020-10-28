/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: ZOJ
 *  Algorithm: TarjanÀ„∑®«Û∏Óµ„
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
const int MAXE = MAXN * MAXN;

class CUT
{
public:
    int head[MAXN];
    int cnt;
    struct Edge
    {
        int from,to,nxt;
        Edge() {}
        Edge(int from,int to,int nxt):from(from),to(to),nxt(nxt) {}
    } e[MAXE];

    int cut[MAXN],dfn[MAXN],low[MAXN];
    int dfs_clock;

    void init()
    {
        memset(head,-1,sizeof(head));
        memset(dfn, 0, sizeof(dfn));
        cnt = dfs_clock = 0;
        for(int i=0; i<=1000; i++)
            cut[i] = 0;
    }

    inline void addEdge(int u,int v)
    {
        e[cnt].from = u;
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
                {
                    if(~fa)
                        cut[u] = child + 1;
                    else
                        cut[u] = child;
                }

            }
            else if(dfn[v] < dfn[u] && v != fa)
                lowu = min(lowu,dfn[v]);
        }
        if(fa == -1 && child == 1)
            cut[u] = 0;
        low[u] = lowu;
        return lowu;
    }

    void buildGraph(int u)
    {
        while(u)
        {
            int v;
            scanf("%d", &v);
            addEdge(u, v);
            addEdge(v, u);
            scanf("%d", &u);
        }
    }

    void solve(int u, int kase)
    {
        buildGraph(u);
        for(int i=1; i<=1000; i++)
        {
            if(!dfn[i])
                dfs(i,-1);
        }
        if(kase != 1)
            puts("");
        printf("Network #%d\n", kase);
        bool flag = false;
        for(int i = 1; i <= 1000; i++)
        {
            if(cut[i])
            {
                flag = true;
                printf("  SPF node %d leaves %d subnets\n", i, cut[i]);
            }
        }
        if(!flag)
            puts("  No SPF nodes");
    }
} cut;

int main()
{
    int u, kase = 1;
    while(~scanf("%d", &u), u)
    {
        cut.init();
        cut.solve(u, kase++);
    }
    return 0;
}
