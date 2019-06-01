/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-05-31
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
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
#define MAXN 200005

vector<int> G[MAXN];
int deg[MAXN];  //每个点的度数
bool vis[MAXN];

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            if(!vis[v])
            {
                vis[v] = true;
                q.push(v);
                printf("%d %d\n",u,v);
            }
        }
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].PB(v);
        G[v].PB(u);
        deg[u]++, deg[v]++;
    }
    int maxdeg = 0;
    int p = 1;
    for(int i=1; i<=n; i++)
    {
        if(deg[i] > maxdeg)
        {
            maxdeg = deg[i];
            p = i;
        }
    }
    bfs(p);
    return 0;
}
