/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-08-08
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: AOJ
 *  Algorithm:
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
#define MAXN 100010

struct Edge
{
    int to,cost,nxt;
    Edge() {}
    Edge(int to,int cost,int nxt):to(to),cost(cost),nxt(nxt) {}
} e[MAXN<<1];

int head[MAXN];
int cnt;
int ans;

inline void addEdge(int u,int v,int w)
{
    e[cnt].to = v;
    e[cnt].cost = w;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

int dp[MAXN][2];    //dp[i][0/1]表示以i点为树根（从i点出发）能到最远儿子的距离和到次远儿子的距离

//树的直径（树上最长路）
void dfs(int u, int fa)
{
    dp[u][0] = dp[u][1] = 0;
    for(int i=head[u]; ~i; i=e[i].nxt)
    {
        int v = e[i].to;
        int w = e[i].cost;
        if(v != fa)
        {
            dfs(v, u);
            if(dp[u][0] < dp[v][0] + w) //更新到最远儿子的距离
            {
                dp[u][1] = dp[u][0];    //到最远儿子的距离更新为到次远儿子的距离
                dp[u][0] = dp[v][0] + w;
            }
            else if(dp[u][1] < dp[v][0] + w)    //到最远儿子的距离不需要更新，只需要更新到次远儿子的距离
                dp[u][1] = dp[v][0] + w;
        }
    }
    //到最远儿子的距离 + 到次远儿子的距离 = 树的直径
    ans = max(ans, dp[u][0] + dp[u][1]);    //更新最大值
}


int main()
{
    int n;
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    cnt = 0;
    for(int i=1; i<n; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    ans = 0;
    dfs(0,-1);
    printf("%d\n",ans);
    return 0;
}
