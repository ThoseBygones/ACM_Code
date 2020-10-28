/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-15
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm:
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

const int MAXN = 505;
const int MAXE = 100010;

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

int findset(int x)
{
    if(x != fa[x])
        return fa[x] = findset(fa[x]);
    return fa[x];
}

int kruskal()
{
    sort(e, e + m);
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
    return cnt ? -1 : ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int k;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            e[i] = Edge(u, v, w);
        }
        while(k--)
        {
            int t, tmp[105];
            scanf("%d", &t);
            for(int i = 0; i < t; i++)
                scanf("%d", &tmp[i]);
            for(int i = 0; i < t; i++)
            {
                for(int j = i + 1; j < t; j++)
                    e[m++] = Edge(tmp[i], tmp[j], 0);
            }
        }
        printf("%d\n", kruskal());
    }
    return 0;
}
