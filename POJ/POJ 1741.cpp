/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-07
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 树形dp求树的重心 + 点分治
 ********************************************************************************
 *  Algo-Description:
 * > 点分治：对点进行分治，一般用于路经统计问题。
 *   > 对每个点而言，一条路径要么经过该点，要么不经过该点，即分成路径经过该点和不经过该点。
 *   > 基本思想：当经过某点的路径可以比较方便快速统计的情况下，通过对点进行分治，把树的规模不断变小。
 * > 树的重心：
 *   > 一棵无根树，把某个点去掉之后，原树会分裂成几棵规模较小的树，每棵树有若干个节点。
 *   > 树的重心即将该点删除之后，得到的最大的子树的规模最小。
 *   > 显然，点分治中，对树的重心进行分治是最好的。树的规模能够稳定的变小。
 * > 点分治解题套路：
 *   > 对整个树，求出一个重心，对重心进行点分治，先统计出经过这个点的路径。
 *   > 将这个重心点删掉，把整个树分解成若干个子树。
 *   > 对每个子树继续求重心，并进行分治。
 * > 本题题解：对于某个点 u ，经过该点且长度小于等于 k 的路径个数可以很方便求出：
 *   > 把树变成以 u 为根的树，对每个点 v 求出 u 到它的距离，看其中有多少对距离 d(u, v) <= k 。
 *   > 采用的方法就是把所有的距离存在一个数组里进行排序，然后双指针的方法计算符合要求的点对组合数量。
 *   > 存在的问题是：
 *     > 某个经过点 u 的路径可以分成两段，这两段路径必须分布在不同两个子树上。
 *     > 如果在一个子树上，两段路径在子树中对应的结点的 LCA（最近公共祖先）不等于 u ；
 *     > 即合并后的这条路径实际上不会经过点 u （LCA(v1, v2) -> u -> LCA(v1, v2) 这一段实际上重复走了）。
 *   > 因此，在上述统计完成后，还要对每个子树进行路径遍历去重。
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

const int MAXN = 10005;

int head[MAXN];
struct Edge
{
    int to, cost, nxt;
    Edge() {}
    Edge(int to, int cost, int nxt) : to(to), cost(cost), nxt(nxt) {}
} e[MAXN << 1];

int sz[MAXN];   //以每个结点为根子树的结点数（包含自身）
int dp[MAXN];   //dp[i]表示沿树路径到第i个点时子树结点数的最大值（不含自身）
bool vis[MAXN];
int dis[MAXN];  //存储各个点到重心的距离（单纯存储距离值，不对应结点）
int cnt, tot;
int sum;    //当前子树的结点数量
int rt; //当前子树的重心
int ans;
int n, k;

void init()
{
    cnt = rt = 0;
    ans = 0;
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

void dfs(int u, int fa) //求树的重心
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
    dp[u] = max(dp[u], sum - sz[u]);
    if(dp[u] < dp[rt])  //树的重心的定义：以该点为根的有根树，最大子树的结点数最小
        rt = u;
}

int getDis(int u, int fa, int d)    //计算点到重心的距离
{
    dis[++tot] = d;
    for(int i = head[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].to;
        if(v != fa && !vis[v])
            getDis(v, u, d + e[i].cost);
    }
}

int cal(int u, int d)   //计算满足条件（长度小于k）的路径数
{
    tot = 0;
    int sum = 0;
    getDis(u, 0, d);
    sort(dis + 1, dis + 1 + tot);
    int l = 1, r = tot;
    while(l < r)    //双指针计算所有路径数（可能会重复计算）
    {
        if(dis[l] + dis[r] <= k)
        {
            sum += r - l;
            l++;
        }
        else
            r--;
    }
    return sum;
}

void solve(int u)   //递归（分治）解决
{
    vis[u] = true;
    ans += cal(u, 0);
    for(int i = head[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].to;
        if(!vis[v])
        {
            ans -= cal(v, e[i].cost);  //容斥原理，删除重复计算的路径
            sum = sz[v];
            rt = 0;
            dfs(v, 0);  //找到结点u以结点v为根的子树的重心
            solve(rt);
        }
    }
}

int main()
{
    while(~scanf("%d%d", &n, &k))
    {
        if(!n && !k)
            break;
        init();
        for(int i = 1; i < n; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        dp[0] = INF;    //根结点无穷大
        sum = n;
        dfs(1, 0);
        solve(rt);
        printf("%d\n", ans);
    }
    return 0;
}
