/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 逆拓扑排序 + 优先队列
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

const int MAXN = 205;

vector<int> G[MAXN];
int ind[MAXN], ans[MAXN];

bool toposort(int n)
{
    priority_queue<int> pq;
    for(int i = 1; i <= n; i++)
    {
        if(!ind[i])
            pq.push(i);
    }
    int cnt = 0;
    while(!pq.empty())
    {
        int u = pq.top();
        pq.pop();
        ans[u] = n - (cnt++);
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            ind[v]--;
            if(!ind[v])
                pq.push(v);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(ind[i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            ind[i] = 0;
            G[i].clear();
        }
        bool flag = true;
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if(u != v)
            {
                G[v].PB(u);
                ind[u]++;
            }
            else
                flag = false;
        }
        if(flag)
        {
            if(toposort(n))
            {
                for(int i = 1; i <= n; i++)
                    printf("%d%c", ans[i], (i == n ? '\n' : ' '));
            }
            else
                puts("-1");
        }
        else
            puts("-1");
    }
    return 0;
}
