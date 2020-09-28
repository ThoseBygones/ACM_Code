/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm:
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

const int MAXN = 10005;

int head[MAXN];
int cnt;

struct Edge
{
    int to, nxt;
    int cost;
    Edge() {}
    Edge(int to, int nxt, int cost) : to(to), nxt(nxt), cost(cost) {}
} e[MAXN << 1];

inline void addEdge(int u, int v, int w)
{
    e[cnt].to = v;
    e[cnt].cost = w;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

int d[MAXN];    //d[i]表示以某个结点为根，结点i的深度
int p[2]; //树的直径的两个端点
int ans[MAXN];

void dfs(int u, int fa, int id)
{
    for(int i = head[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].to;
        int w = e[i].cost;
        if(v != fa)
        {
            d[v] = d[u] + w;
            if(d[v] > d[p[id]])    //更新距离临时根结点（1号结点）最远的结点编号
                p[id] = v;
            dfs(v, u, id);
        }
    }
}

void solve(int n)    //dfs求树的直径
{
    memset(d, 0, sizeof(d));
    dfs(0, -1, 0);  //从临时根节点开始遍历找到最远端的结点即为树的直径的一个端点
    memset(d, 0, sizeof(d));
    dfs(p[0], -1, 1); //从该端点开始遍历找到树的直径的另一个端点
    for(int i = 0; i < n; i++)
        ans[i] = max(ans[i], d[i]);
    memset(d, 0, sizeof(d));
    dfs(p[1], -1, 0);
    for(int i = 0; i < n; i++)
    {
        ans[i] = max(ans[i], d[i]);
        printf("%d\n", ans[i]);
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    cnt = 0;
    for(int i = 1; i < n; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    solve(n);
    return 0;
}
