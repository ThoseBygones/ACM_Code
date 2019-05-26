/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-05-26
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 树形dp
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
#define MAXN 300005

vector<int> G[MAXN];
int col[MAXN];
int dp[MAXN][2];    //dp[i][0/1]表示以i为根结点，子树中结点为蓝色/红色的数量
int ans;

void dfs(int u,int fa)
{
    if(col[u] == 1)
        dp[u][1]++;
    if(col[u] == 2)
        dp[u][0]++;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(v != fa)
        {
            dfs(v,u);
            //从下往上更新蓝色/红色结点数量
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][1];
        }
    }
}

void dfs2(int u,int fa)
{
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(v != fa)
        {
            //以i为结点的子树蓝色结点数量 = 整棵树的蓝色结点数量，且以i为结点的子树红色结点数量 = 0
            //或：以i为结点的子树红色结点数量 = 整棵树的红色结点数量，且以i为结点的子树蓝色结点数量 = 0
            if((dp[v][0] == dp[1][0] && dp[v][1] == 0) || (dp[v][1] == dp[1][1] && dp[v][0] == 0))
                ans++;
            dfs2(v,u);
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&col[i]);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1,-1);
    ans = 0;
    dfs2(1,-1);
    printf("%d\n",ans);
    return 0;
}
