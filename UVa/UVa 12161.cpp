/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-13
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: 树形dp求树的重心 + 点分治 + 二分
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

class NodeDiv
{
public:
#define MAXN 30005

    int head[MAXN];
    struct Edge
    {
        int to, damage, length, nxt;
        Edge() {}
        Edge(int to, int damage, int length, int nxt) : to(to), damage(damage), length(length), nxt(nxt) {}
    } e[MAXN << 1];

    int sz[MAXN];   //以每个结点为根子树的结点数（包含自身）
    int dp[MAXN];   //dp[i]表示沿树路径到第i个点时子树结点数的最大值（不含自身）
    int path[MAXN];  //存储各个点到重心的距离（单纯存储距离值，不对应结点）
    bool vis[MAXN];
    int cnt, tot;
    int nodecnt;    //当前子树中所有结点数
    int rt; //求得当前子树的重心
    int ans;
    int n, m;

    void init(int n, int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = rt = 0;
        memset(head, -1, sizeof(head));
        memset(vis, false, sizeof(vis));
    }

    inline void addEdge(int u, int v, int w)
    {
        e[cnt].to = v;
        e[cnt].cost = w;
        e[cnt].nxt = head[u];
        head[u] = cnt++;
    }

    void dfs(int u, int fa) //树形dp求树的重心
    {
        dp[u] = 0, sz[u] = 1;
        for(int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].to;
            if(v != fa && !vis[v])
            {
                dfs(v, u);
                sz[u] += sz[v];
                dp[u] = max(dp[u], sz[v]);
            }
        }
        dp[u] = max(dp[u], nodecnt - sz[u]);    //树的重心的定义：以该点为根的有根树，最大子树的结点数最小
        if(dp[u] < dp[rt])
            rt = u;
    }

    void getPath(int u, int fa, int d)
    {
        path[++tot] = d;
        for(int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].to, w = e[i].cost;
            if(v != fa && !vis[v] && d + w <= k)
                getPath(v, u, d + w);
        }
    }

    int cal(int u, int d)
    {
        tot = 0;
        int sum = 0;
        getPath(u, 0, d);
        sort(path + 1, path + 1 + tot);
        int l = 1, r = tot;
        while(l < r)
        {
            /* 计算符合条件的路径数 */
        }
        return sum;
    }

    void solve(int u)
    {
        vis[u] = true;
        ans += cal(u, 0);
        for(int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].to;
            if(!vis[v])
            {
                ans -= cal(v, e[i].cost);
                rt = 0;
                nodecnt = sz[v];
                dfs(v, 0);  //dfs(v, u) 也可
                solve(rt);
            }
        }
    }

    void buildGraph()
    {
        for(int i = 1; i < n; i++)
        {
            int u, v, d, c;
            addEdge(u, v, d, c);
            addEdge(v, u, d, c);
        }
    }

    void main() //调用方法
    {
        memset(vis, false, sizeof(vis));
        dp[0] = INF;
        nodecnt = n;
        ans = rt = 0;
        dfs(1, 0);
        solve(rt);
    }
} nodediv;

int main()
{
    int T;
    while(T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        nodediv.init(n, m);
        nodediv.buildGraph();

    }
    return 0;
}
