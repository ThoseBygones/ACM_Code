/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-08-04
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
#define MAXN 10005
#define MAXE 100010


/*最小生成树kruskal算法，适合求稀疏图上的MST*/

struct Edge
{
    int u,v,w;
    Edge() {}
    Edge(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator <(const Edge &ed) const
    {
        return w < ed.w;
    }
} e[MAXE];

int fa[MAXN];
int n,m;

int findset(int x)
{
    if(x != fa[x])
        return fa[x] = findset(fa[x]);
    return fa[x];
}

int kruskal()
{
    sort(e,e+m);
    int cnt = n - 1;
    int ans = 0;
    for(int i=0; i<=n; i++)
        fa[i] = i;
    for(int i=0; i<m; i++)
    {
        int fu = findset(e[i].u);
        int fv = findset(e[i].v);
        if(fu != fv)
        {
            fa[fu] = fv;
            ans += e[i].w;
            cnt--;
            if(!cnt)
                break;
        }
    }
    return cnt ? INF : ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[i] = Edge(u,v,w);
    }
    int ans = kruskal();
    printf("%d\n",ans);
    return 0;
}
