/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-29
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
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

const int MAXN = 100005;

//树形dp
vector<int> G[MAXN];
int dp[MAXN];   //dp[i]表示从结点i出发，往以i为根节点的子树遍历能到达的最远距离
int ans;

void dfs(int u, int fa)
{
    for(auto v: G[u])
    {
        if(v != fa)
        {
            dfs(v, u);
            ans = max(ans, dp[u] + dp[v] + 1);  //先用dp[u]更新ans
            dp[u] = max(dp[u], dp[v] + 1);  //再用dp[v]更新dp[u]，顺序不能改变
        }
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
            G[i].clear();
        memset(dp, 0, sizeof(dp));
        ans = 0;
        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].PB(v);
            G[v].PB(u);
        }
        dfs(1, 0);
        while(m--)
        {
            int k;
            scanf("%d", &k);
            if(ans + 1 >= k)
                printf("%d\n", k - 1);
            else
                printf("%d\n", ans + (k - ans - 1) * 2);    //直径上的点只需要走一遍，不在直径上的点需要走两遍（来回）
        }
    }
    return 0;
}


//两次dfs
vector<int> G[MAXN];
int d[MAXN];   //d[i]表示以某个结点为根，结点i的深度
int rt; //第一次dfs后找到的树的直径的一个端点

void dfs(int u, int fa)
{
    for(auto v: G[u])
    {
        if(v != fa)
        {
            d[v] = d[u] + 1;
            if(d[v] > d[rt])
                rt = v;
            dfs(v, u);
        }
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
            G[i].clear();
        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].PB(v);
            G[v].PB(u);
        }
        memset(d, 0, sizeof(d));
        dfs(1, 0);
        memset(d, 0, sizeof(d));
        dfs(rt, 0);
        //printf("--%d\n", d[rt]);
        while(m--)
        {
            int k;
            scanf("%d", &k);
            if(d[rt] + 1 >= k)
                printf("%d\n", k - 1);
            else
                printf("%d\n", d[rt] + (k - d[rt] - 1) * 2);    //直径上的点只需要走一遍，不在直径上的点需要走两遍（来回）
        }
    }
    return 0;
}
