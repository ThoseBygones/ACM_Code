/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-03-18
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 贪心 / 二分图最大匹配（最小路径覆盖）
 ********************************************************************************
 *  Algo-Description:
 *  > 贪心算法：按照x排序，x相等则按照y排序。若 a.x <= b.x 且 a.y <= b.y 则可以从 a 点到达 b 点
 *  > 二分图匹配算法：最小路径覆盖数 = n - 最大匹配数
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
#define MAXN 705


/*贪心算法*/

struct Garbage
{
    int x,y;
    bool flag;
} ga[MAXN];

bool cmp(Garbage a,Garbage b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    int cnt = 0;
    int x,y;
    while(~scanf("%d%d",&x,&y))
    {
        if(x == -1 && y == -1)
            break;
        if(x && y)
        {
            ga[cnt].x = x, ga[cnt].y = y, ga[cnt++].flag = false;
            continue;
        }
        sort(ga,ga+cnt,cmp);
        int ans = 0;
        for(int i=0; i<cnt; i++)
        {
            if(!ga[i].flag)
            {
                ans++;
                ga[i].flag = true;
                int tmp = ga[i].y;
                for(int j=i+1; j<cnt; j++)
                {
                    if(!ga[j].flag && ga[j].y >= tmp)
                    {
                        ga[j].flag = true;
                        tmp = ga[j].y;
                    }
                }
            }
        }
        printf("%d\n",ans);
        cnt = 0;
    }
    return 0;
}


/*二分图最大匹配*/

class Hungary_DFS
{
private:
    struct Node
    {
        int x,y;
    } nd[MAXN];
    vector <int> G[MAXN];
    int vis[MAXN];
    int mx[MAXN],my[MAXN];
    int n;
    int nx,ny;

    bool dfs(int u)
    {
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(!vis[v])
            {
                vis[v] = true;
                if(my[v] == -1 || dfs(my[v]))
                {
                    my[v] = u;
                    mx[u] = v;
                    return true;
                }
            }
        }
        return false;
    }

public:
    void init()
    {
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
    }

    int hungary()
    {
        int res = 0;
        for(int i = 0; i < nx; i++)
        {
            if(mx[i] == -1)
            {
                memset(vis, 0, sizeof(vis));
                if(dfs(i))
                    res++;
            }
        }
        return res;
    }

    bool check(Node a,Node b)   //判断两点之间是否可连边
    {
        if(a.x <= b.x && a.y <= b.y)
            return true;
        return false;
    }

    void buildGraph()   //建图
    {
        for(int i=0; i<n; i++)
        {
            G[i].clear();
            for(int j=i+1; j<n; j++)
            {
                if(check(nd[i],nd[j]))
                    G[i].PB(j);
                if(check(nd[j],nd[i]))
                    G[j].PB(i);
            }
        }
    }

    void solve()
    {
        int cnt = 0;
        int x,y;
        while(~scanf("%d%d",&x,&y))
        {
            if(x == -1 && y == -1)
                break;
            if(x && y)
            {
                nd[cnt].x = x, nd[cnt++].y = y;
                continue;
            }
            nx = ny = n = cnt;
            init();
            buildGraph();
            printf("%d\n",n-hungary());
            cnt = 0;
        }
    }
} hungaryDFS;

int main()
{
    hungaryDFS.solve();
    return 0;
}
