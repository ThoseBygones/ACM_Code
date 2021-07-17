/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-12
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 树的重心 + 点分治 + 双指针
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

const int MAXN = 10005;

int head[MAXN];
struct Edge
{
    int to, cost, nxt;
    Edge() {}
    Edge(int to, int cost, int nxt) : to(to), cost(cost), nxt(nxt) {}
} e[MAXN << 1];

int sz[MAXN];  //以每个结点为根子树的结点数（包含自身）
int dp[MAXN];   //dp[i]表示沿树路径到第i个点时子树结点数的最大值（不含自身）
int dis[MAXN];  //存储各个点到重心的距离（单纯存储距离值，不对应结点）
bool vis[MAXN];
int cnt, tot;
int nodecnt;    //当前子树中所有结点数
int rt; //求得当前子树的重心
int ans;
int n, k;

void init()
{
    cnt = rt = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int w)
{
    e[cnt].to = v;
    e[cnt].cost = w;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dfs(int u, int fa)
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
    dp[u] = max(dp[u], nodecnt - sz[u]);      //树的重心的定义：以该点为根的有根树，最大子树的结点数最小
    if(dp[u] < dp[rt])
        rt = u;
}

void getDis(int u, int fa, int d)
{
    dis[++tot] = d;
    for(int i = head[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].to, w = e[i].cost;
        if(v != fa && !vis[v] && d + w <= k)
            getDis(v, u, d + w);
    }
}

int cal(int u, int d)
{
    tot = 0;
    int sum = 0;
    getDis(u, 0, d);
    //printf("tot: %d\n", tot);
    sort(dis + 1, dis + 1 + tot);
    //printf("dis: ");
    /*for(int i = 1; i <= tot; i++)
        printf("%d ", dis[i]);
    puts("");*/
    int l = 1, r = tot;
    while(l < r)
    {
        if(dis[l] + dis[r] < k)
            l++;
        else if(dis[l] + dis[r] > k)
            r--;
        else
        {
            if(dis[l] == dis[r])
            {
                sum += (r - l + 1) * (r - l) / 2;
                break;
            }
            int i = l, j = r;
            while(dis[i] == dis[l])
                i++;
            while(dis[j] == dis[r])
                j--;
            sum += (i - l) * (r - j);
            l = i, r = j;
        }
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

int main()
{
    while(~scanf("%d", &n), n)
    {
        init();
        int v, w;
        for(int u = 1; u <= n; u++)
        {
            while(~scanf("%d", &v), v)
            {
                scanf("%d", &w);
                addEdge(u, v, w);
                addEdge(v, u, w);
            }
        }
        while(~scanf("%d", &k), k)
        {
            memset(vis, false, sizeof(vis));
            dp[0] = INF;
            nodecnt = n;
            ans = rt = 0;
            dfs(1, 0);
            solve(rt);
            puts(ans ? "AYE" : "NAY");
        }
        puts(".");
    }
    return 0;
}
