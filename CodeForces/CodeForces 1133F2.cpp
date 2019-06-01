/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-05-31
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 连通分量 + 并查集 / Tarjan + BFS / 并查集
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
#define MAXN 200005

vector<int> G[MAXN];
vector<int> rec;    //记录与1号节点相邻的节点编号
int fa[MAXN];
int vis[MAXN];

int findset(int x)
{
    if(x != fa[x])
        return fa[x] = findset(fa[x]);
    return fa[x];
}

void unionset(int x,int y)
{
    int xx = findset(x);
    int yy = findset(y);
    if(xx != yy)
        fa[xx] = yy;
}

void bfs(int x)
{
    queue<int> q;
    memset(vis,0,sizeof(vis));
    vis[x] = 1;
    q.push(x);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                q.push(v);
                printf("%d %d\n",u,v);
            }
        }
    }
}

int main()
{
    int n,m,d;
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1; i<=n; i++)
        fa[i] = i;
    int deg1 = 0;   //1号节点的度数
    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u != 1 && v != 1)
        {
            G[u].PB(v);
            G[v].PB(u);
            unionset(u,v);
        }
        else
        {
            rec.PB(max(u,v));
            deg1++;
        }
    }
    int cc_cnt = 0;
    for(int i=2; i<=n; i++)
    {
        if(fa[i] == i)
            cc_cnt++;
    }
    //cout << cc_cnt << endl;
    if(cc_cnt > d || deg1 < d)  //连通分量数量大于1号节点的度数或1号结点度数为0，则不能构造出生成树
        puts("NO");
    else
    {
        for(int i=0; i<deg1; i++)
        {
            int x = findset(rec[i]);
            if(!vis[x])   //该节点所在的连通分量没有被连入
            {
                vis[x] = 1;
                G[1].PB(rec[i]);
                G[rec[i]].PB(1);
                rec[i] = 0; //将已经连入的节点去掉
                d--;
            }
        }
        if(d)
        {
            for(int i=0; i<deg1 && d; i++)
            {
                if(rec[i])
                {
                    G[1].PB(rec[i]);
                    G[rec[i]].PB(1);
                    rec[i] = 0; //将已经连入的节点去掉
                    d--;
                }
            }
        }
        puts("YES");
        bfs(1);
    }
    return 0;
}
