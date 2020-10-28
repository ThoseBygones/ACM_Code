/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-15
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: Prim 求最小生成树
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

const int MAXN = 105;

int g[MAXN][MAXN];
int vis[MAXN];
int dis[MAXN];
int n;

int prim()
{
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++)
        dis[i] = g[0][i];
    vis[0] = 1;
    dis[0] = 0;
    int sum = 0;
    for(int i=1; i<n; i++)
    {
        int pos = -1;
        int Min = INF;
        for(int j=0; j<n; j++)
        {
            if(!vis[j] && dis[j] < Min)
            {
                Min = dis[j];
                pos = j;
            }
        }
        //if(pos == -1) return INF;
        sum += Min;
        vis[pos] = 1;
        for(int j=0; j<n; j++)
        {
            if(!vis[j] && g[pos][j] < dis[j])
                dis[j] = g[pos][j];
        }
    }
    return sum;
}

int main()
{
    while(~scanf("%d", &n), n)
    {
        for(int i = 0; i < n * (n - 1) / 2; i++)
        {
            int u, v, w, d;
            scanf("%d%d%d%d", &u, &v, &w, &d);
            u--, v--;
            if(d)
                g[u][v] = g[v][u] = 0;
            else
                g[u][v] = g[v][u] = w;
        }
        printf("%d\n", prim());
    }
    return 0;
}
