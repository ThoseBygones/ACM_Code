/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-06-27
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: AOJ
 *  Algorithm: MST Prim
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
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(~tmp)
                g[i][j]=tmp;
            else
                g[i][j]=INF;
        }
    }
    int ans=prim();
    printf("%d\n",ans);
    return 0;
}
