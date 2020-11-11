/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 拓扑排序 + 优先队列
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

const int MAXN = 100005;

vector<int> G[MAXN];
vector<int> ans;
int ind[MAXN];  //入度

void topoSort(int n)
{
    priority_queue<int> pq;
    for(int i = 1; i <= n; i++)
    {
        if(!ind[i])
            pq.push(i);
    }
    while(!pq.empty())
    {
        int u = pq.top();
        pq.pop();
        ans.PB(u);
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(!--ind[v])
                pq.push(v);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; i++)
        {
            G[i].clear();
            ind[i] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            ind[v]++;
            G[u].PB(v);
        }
        ans.clear();
        topoSort(n);
        int Min = n;
        LL sum = 0;
        for(int i = 0; i < n; i++)
        {
            Min = min(Min, ans[i]);
            sum += Min;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
