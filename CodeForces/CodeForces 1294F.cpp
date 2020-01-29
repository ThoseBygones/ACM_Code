/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-28
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: BFS 求 树的直径 + 三点两两之间简单路径最大并集
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
#define MAXN 200005

vector<int> G[MAXN];
bool vis[MAXN];
int dis[2][MAXN]; //d[0/1][i]记录点v/u分别到达点i的距离

int bfs(int x,int flag)
{
    int u = x;
    memset(vis,false,sizeof(vis));
    queue<int> q;
    q.push(x);
    vis[x] = true;
    dis[flag][x] = 0;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            if(!vis[v])
            {
                vis[v] = true;
                dis[flag][v] = dis[flag][u] + 1;
                q.push(v);
            }
        }
    }
    return u;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].PB(v);
        G[v].PB(u);
    }
    //求出树的直径
    int u = bfs(1,0);
    int v = bfs(u,0);
    //printf("u: %d v: %d\n",u,v);
    //求出第三个点
    bfs(v,1);
    int d = dis[0][v];  //树的直径
    int ans = 0;
    int w;  //第三个点
    for(int i=1; i<=n; i++)
    {
        if(i != u && i != v && ans < d+(dis[0][i]+dis[1][i]-d)/2)
        {
            //树的直径长度 + (树直径上的两端点到第三点的路径长度和 - 树的直径长度) / 2
            ans = d + (dis[0][i] + dis[1][i] - d) / 2;
            w = i;
        }
    }
    printf("%d\n",ans);
    printf("%d %d %d\n",u,v,w);
    return 0;
}
