/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-29
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 树的直径
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

const int MAXN = 10005;

//树形dp
int head[MAXN];
struct Edge
{
    int v, w, nxt;
    Edge() {}
    Edge(int v, int w, int nxt) : v(v), w(w), nxt(nxt) {}
} e[MAXN<<1];

int dp[MAXN];   //dp[i]表示从结点i出发，往以i为根节点的子树遍历能到达的最远距离
int cnt;
int ans;

void addEdge(int u, int v, int w)
{
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dfs(int u, int fa)
{
    for(int i = head[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].v;
        int w = e[i].w;
        if(v != fa)
        {
            dfs(v, u);
            ans = max(ans, dp[u] + dp[v] + w);
            dp[u] = max(dp[u], dp[v] + w);
        }
    }
}

int main()
{
    int u, v, w;
    memset(head, -1, sizeof(head));
    while(~scanf("%d%d%d", &u, &v, &w))
    {
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}


//两次dfs
int head[MAXN];
struct Edge
{
    int v, w, nxt;
    Edge() {}
    Edge(int v, int w, int nxt) : v(v), w(w), nxt(nxt) {}
} e[MAXN<<1];

int d[MAXN];   //d[i]表示以某个结点为根，结点i的深度
int cnt;
int rt; //第一次dfs后找到的树的直径的一个端点

void addEdge(int u, int v, int w)
{
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dfs(int u, int fa)
{
    for(int i = head[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].v;
        int w = e[i].w;
        if(v != fa)
        {
            d[v] = d[u] + w;
            if(d[v] > d[rt])
                rt = v;
            dfs(v, u);
        }
    }
}

int main()
{
    int u, v, w;
    memset(head, -1, sizeof(head));
    while(~scanf("%d%d%d", &u, &v, &w))
    {
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    memset(d, 0, sizeof(d));
    dfs(1, 0);  //从临时根节点开始遍历找到最远端的结点即为树的直径的一个端点
    memset(d, 0, sizeof(d));
    dfs(rt, 0); //从该端点开始遍历找到树的直径的另一个端点
    printf("%d\n", d[rt]);
    return 0;
}
