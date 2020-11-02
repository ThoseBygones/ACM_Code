/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-01
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 最小生成树变形
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

const int MAXN = 2005;
const int MAXE = 15005;

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
int n, m;
int ans;

int findset(int x)
{
    if(x != fa[x])
        return fa[x] = findset(fa[x]);
    return fa[x];
}

void kruskal(int k)
{
    int cnt = n - 1;
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    for(int i = k; i < m; i++)
    {
        int fu = findset(e[i].u);
        int fv = findset(e[i].v);
        if(fu != fv)
        {
            fa[fu] = fv;
            cnt--;
            if(!cnt)
            {
                ans = min(ans, e[i].w - e[k].w);
                break;
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            e[i] = Edge(u, v, w);
        }
        sort(e, e + m);
        ans = INF;
        for(int i = 0; i < m; i++)
            kruskal(i);
        printf("%d\n", ans == INF ? -1 : ans);
    }
    return 0;
}
