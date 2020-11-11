/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 拓扑排序 + 并查集 / dfs / bfs 求连通块大小
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

vector<int> G[MAXN];
int ind[MAXN];  //入度
int val[MAXN];  //点权值
int u[MAXN], v[MAXN];
bool vis[MAXN];  //该点是否被访问过
int fa[MAXN];
int cnt[MAXN];  //集合计数
LL sum[MAXN];  //集合中点的权值和

void topoSort(int n)
{
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(ind[i] <= 1)
            q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(!vis[v]) //该点还未入队过
            {
                --ind[v];
                if(ind[v] <= 1)
                    q.push(v);
            }
        }
    }
}

int findSet(int x)
{
    if(x != fa[x])
        return fa[x] = findSet(fa[x]);
    return fa[x];
}

void unionSet(int x, int y)
{
    int fx = findSet(x);
    int fy = findSet(y);
    if(fx != fy)
    {
        fa[fx] = fy;
        cnt[fy] += cnt[fx];
        sum[fy] += sum[fx];
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &val[i]);
            G[i].clear();
            vis[i] = false;
            ind[i] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u[i], &v[i]);
            G[u[i]].PB(v[i]);
            G[v[i]].PB(u[i]);
            ind[u[i]]++, ind[v[i]]++;
        }
        topoSort(n);
        for(int i = 1; i <= n; i++)
        {
            fa[i] = i;
            cnt[i] = 1;
            sum[i] = val[i];
        }
        for(int i = 0; i < m; i++)
        {
            if(!vis[u[i]] && !vis[v[i]])    //两个相连的池塘未被移除
                unionSet(u[i], v[i]);
        }
        LL ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(fa[i] == i && !vis[i] && (cnt[i] & 1))
                ans += sum[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
