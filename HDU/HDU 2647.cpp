/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: Õÿ∆À≈≈–Ú
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

const int MAXN = 10005;

vector<int> G[MAXN];
int ind[MAXN];  //»Î∂»

int topoSort(int n)
{
    queue<PII> q;
    for(int i = 1; i <= n; i++)
    {
        if(!ind[i])
            q.push(MP(i, 0));
    }
    int sum = 0, cnt = 0;
    while(!q.empty())
    {
        PII tmp = q.front();
        int u = tmp.first, w = tmp.second;
        q.pop();
        cnt++;
        sum += w + 888;
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(!--ind[v])
                q.push(MP(v, w + 1));
        }
    }
    return cnt == n ? sum : -1;
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i <= n; i++)
        {
            G[i].clear();
            ind[i] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            ind[u]++;
            G[v].PB(u);
        }
        int ans = topoSort(n);
        printf("%d\n", ans);
    }
    return 0;
}
