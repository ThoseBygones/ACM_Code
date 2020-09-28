/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm: LCA在线倍增
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
#define MAXN 100005
#define MAXE 200005

class LCA_Online_Multiplication
{
public:


    int head[MAXN],nxt[MAXE],e[MAXE];
    int cnt;

    void init(int n)
    {
        this -> n = n;
        cnt = 0;
        memset(head,-1,sizeof(head));
    }

    inline void addEdge(int u,int v)
    {
        e[cnt] = v;
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    int dep[MAXN];
    int p[MAXN][20];
    int n;

    void dfs(int u,int fa,int d)
    {
        dep[u] = d;
        p[u][0] = fa;
        for(int i = 1; (1<<i)<=n; i++)
        {
            if(~p[u][i-1]) p[u][i] = p[p[u][i-1]][i-1];
            else p[u][i] = -1;
        }
        for(int i = head[u]; ~i; i = nxt[i])
        {
            int v = e[i];
            if(v==fa) continue;
            dfs(v,u,d+1);
        }
    }

    int LCA(int u,int v)
    {
        if(dep[u]>dep[v]) swap(u,v);
        if(dep[u]<dep[v])
        {
            int offset = dep[v] - dep[u];
            for(int i = 0; (1<<i)<=n; i++) if(offset&(1<<i)) v = p[v][i];
        }
        if(u!=v)
        {
            for(int i = log2(n); i>=0; i--)
            {
                if(p[u][i]!=p[v][i])
                    u = p[u][i],v = p[v][i];
            }
            u = p[u][0],v = p[v][0];
        }
        return u;
    }

    //求树上两点距离
    int treeDis(int u,int v)
    {
        return dep[u] + dep[v] - 2 * dep[LCA(u,v)];
    }

    void buildGraph()
    {
        for(int u = 0; u < n; u++)
        {
            int num;
            scanf("%d", &num);
            while(num--)
            {
                int v;
                scanf("%d", &v);
                addEdge(u,v);
                addEdge(v,u);
            }
        }
    }

    void solve()
    {
        buildGraph();
        dfs(0, -1, 0);
        int q;
        scanf("%d", &q);
        while(q--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", LCA(u, v));
        }
    }
} lca_multi;

int main()
{
    int n;
    scanf("%d", &n);
    lca_multi.init(n);
    lca_multi.solve();
    return 0;
}
