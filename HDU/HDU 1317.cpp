/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: FLoyd + SPFA
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

const int MAXN = 105;
const int MAXE = MAXN * MAXN;

typedef int Type;

class SPFA
{
public:
    int head[MAXN], nxt[MAXE], cnt;
    Type d[MAXN];
    struct Edge
    {
        int v;
        Type cost;
        Edge() {}
        Edge(int v, Type cost) : v(v), cost(cost) {}
    } e[MAXE];

    bool g[MAXN][MAXN];

    bool inq[MAXN];
    int inqcnt[MAXN];   //入队次数

    void init(int n)
    {
        cnt = 0;
        for(int i = 0; i <= n; i++)
            head[i] = -1;
        memset(g, false, sizeof(g));
    }

    inline void addEdge(int u, int v, Type cost)
    {
        e[cnt] = Edge(v, cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    void floyd(int n)
    {
        for(int k = 1; k <= n; k++)
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= n; j++)
                    g[i][j] |= (g[i][k] && g[k][j]);
            }
        }
    }

    bool spfa(int s, int n)
    {
        for(int i = 0; i <= n; i++)
        {
            inq[i] = false;
            d[i] = 0;
            inqcnt[i] = 0;
        }
        d[s] = 100;
        queue<int> q;
        q.push(s);
        inqcnt[s]++;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            inq[x] = false;
            for(int i = head[x]; ~i; i = nxt[i])
            {
                Edge ed = e[i];
                if(d[ed.v] < d[x] + ed.cost && d[x] + ed.cost > 0)
                {
                    d[ed.v] = d[x] + ed.cost;
                    if(!inq[ed.v])
                    {
                        if(++inqcnt[ed.v] >= n)    //有正环
                            return g[x][n]; //判断从该点是否能直接到达终点
                        inq[ed.v] = true;
                        q.push(ed.v);
                    }
                }
            }
        }
        return d[n] > 0;
    }

    void solve(int n)
    {
        for(int u = 1; u <= n; u++)
        {
            int en, k;
            scanf("%d%d", &en, &k);
            while(k--)
            {
                int v;
                scanf("%d", &v);
                g[u][v] = true;
                addEdge(u, v, en);
            }
        }
        floyd(n);
        if(!g[1][n])
            puts("hopeless");
        else
            puts(spfa(1, n) ? "winnable" : "hopeless");
    }
} spfa;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(n == -1)
            break;
        spfa.init(n);
        spfa.solve(n);
    }
    return 0;
}
