/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-22
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm: dfs + 染色 有向图判环
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 105;
const int MAXE = 1005;

int head[MAXN];
int color[MAXN];
int cnt;

struct Edge
{
    int to, nxt;
    Edge() {}
    Edge(int to, int nxt) : to(to), nxt(nxt) {}
} e[MAXE];

inline void addEdge(int u, int v)
{
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

bool dfs(int u)
{
    color[u] = 1;
    for(int i = head[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].to;
        if(color[v] == 1)
            return true;
        if(!color[v] && dfs(v)) //下一个结点还未被处理过
            return true;
    }
    color[u] = 2;
    return false;
}

bool findLoop(int n)
{
    for(int i = 0; i < n; i++)
    {
        if(!color[i])
        {
            if(dfs(i))
                return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    cnt = 0;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    printf("%d\n", findLoop(n));
    return 0;
}
