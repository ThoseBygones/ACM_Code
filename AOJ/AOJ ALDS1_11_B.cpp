/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-06-26
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: AOJ
 *  Algorithm: DFS
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
#define MAXN 105

int g[MAXN][MAXN];
bool vis[MAXN];
int d[MAXN],f[MAXN];
int cnt,n;

void dfs(int u)
{
    vis[u]=true;
    d[u]=cnt++;
    for(int v=1; v<=n; v++)
    {
        if(g[u][v] && !vis[v])
            dfs(v);
    }
    f[u]=cnt++;
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int u,num;
        scanf("%d%d",&u,&num);
        while(num--)
        {
            int v;
            scanf("%d",&v);
            g[u][v]=1;
        }
    }
    cnt=1;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    for(int i=1; i<=n; i++)
        printf("%d %d %d\n",i,d[i],f[i]);
    return 0;
}
