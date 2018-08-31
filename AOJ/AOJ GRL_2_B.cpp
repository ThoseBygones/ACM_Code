/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-08-30
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
#define MAXN 105
#define MAXE 1005

typedef int Type;

struct Edge//边的权和顶点
{
    int u,v;
    Type w;
    Edge() {}
    Edge(int u,int v,Type w):u(u),v(v),w(w) {}
} e[MAXE];

int pre[MAXN],id[MAXN],vis[MAXN];
int n,m,pos;
Type in[MAXN];  //存最小入边权,pre[v]为该边的起点

Type DMST(int root, int n, int m)   //n为总结点数,m为总边数
{
    Type ret = 0;//存最小树形图总权值
    while(true)
    {
        //1.找每个节点的最小入边
        for(int i=0; i<n; i++)
            in[i] = INF;    //初始化为无穷大
        for(int i=0; i<m; i++)  //遍历每条边
        {
            int u = e[i].u;
            int v = e[i].v;
            if(e[i].w < in[v] && u != v)    //说明顶点v有条权值较小的入边  记录之
            {
                pre[v] = u; //节点u指向v
                in[v] = e[i].w; //最小入边
                if(u == root)   //这个点就是实际的起点
                    pos = i;
            }
        }
        for(int i=0; i<n; i++)  //判断是否存在最小树形图
        {
            if(i == root)
                continue;
            if(in[i] == INF)
                return -1;  //除了根以外有点没有入边,则根无法到达它  说明它是独立的点 一定不能构成树形图
        }
        //2.找环
        int cnt = 0;    //记录环数
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;
        for(int i=0; i<n; i++)  //标记每个环
        {
            ret += in[i];   //记录权值
            int v = i;
            while(vis[v] != i && id[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1)
            {
                for(int u = pre[v]; u != v; u = pre[u])
                    id[u] = cnt;    //标记节点u为第几个环
                id[v] = cnt++;
            }
        }
        if(cnt == 0)    //无环
            break;
        for(int i=0; i<n; i++)
            if(id[i] == -1)
                id[i] = cnt++;
        //3.建立新图：缩点，重新标记
        for(int i=0; i<m; i++)
        {
            int u = e[i].u;
            int v = e[i].v;
            e[i].u = id[u];
            e[i].v = id[v];
            if(id[u] != id[v])
                e[i].w -= in[v];
        }
        n = cnt;
        root = id[root];
    }
    return ret;
}

int main()
{
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[i] = Edge(u,v,w);
    }
    int ans = DMST(r,n,m);
    printf("%d\n",ans);
    return 0;
}
