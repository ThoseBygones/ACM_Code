/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-07-14
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 无向图找奇环 + 染色
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
#define MAXN 200010

vector<int> G[MAXN];
bool vis[MAXN];
int col[MAXN];  //每个点的颜色
vector<int> edge;   //记录图中的边的端点u
bool flag;

void dfs(int u,int c)   //c表示颜色
{
    vis[u] = true;
    col[u] = c;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(vis[v])  //与u节点相邻的v节点已被染色
        {
            if(col[u] == col[v])    //如果两节点颜色相同
                flag = false;
        }
        else    //否则继续搜索
            dfs(v,c^1);
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge.PB(u);
        G[u].PB(v);
        G[v].PB(u);
    }
    flag = true;
    dfs(1,0);
    if(flag)
    {
        puts("YES");
        for(int i=0; i<edge.size(); i++)
            printf("%d",col[edge[i]]);
        puts("");
    }
    else
        puts("NO");
    return 0;
}
