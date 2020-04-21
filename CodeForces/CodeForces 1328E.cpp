/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-21
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dfs序
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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

struct Edge
{
    int v, nxt;
    Edge() {}
    Edge(int v, int nxt) : v(v), nxt(nxt) {}
} e[MAXN<<1];

int head[MAXN];
int cnt;

void addEdge(int u, int v)
{
    e[cnt].v = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

int dfs_clock;  //dfs序时间戳
int lnd[MAXN], rnd[MAXN];    //为每一个结点赋一个左值lnd和一个右值rnd，这个区间表示这个结点的管辖结点范围。
int par[MAXN];  //该结点的父结点
int dep[MAXN];  //该结点的深度
int qry[MAXN];  //记录询问的点
int n, m;

void init()
{
    memset(head, -1, sizeof(head));
    cnt = 0;
    dfs_clock = 0;
}

void dfs(int u, int fa, int d)  //dfs序
{
    dep[u] = d;
    par[u] = fa;
    lnd[u] = ++dfs_clock;   //记录dfs序下该结点被访问的起始时间戳
    for(int i = head[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].v;
        if(v != fa)
            dfs(v, u, d + 1);
    }
    rnd[u] = dfs_clock; //记录dfs序下该结点被访问的结束时间戳
}

bool check(int u, int v)
{
    if(lnd[u] <= lnd[v] && rnd[v] <= rnd[u])
        return true;
    return false;
}

bool check_all(int k, int val)
{
    for(int i = 1; i <= k; i++)
    {
        if(!check(qry[i], val) && !check(par[qry[i]], val))
            return false;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    init();
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(1, 0, 0);
    while(m--)
    {
        int k;
        scanf("%d", &k);
        int maxdep = 0;
        for(int i = 1; i <= k; i++)
        {
            scanf("%d", &qry[i]);
            if(dep[maxdep] < dep[qry[i]])
                maxdep = qry[i];
        }
        if(check_all(k, maxdep))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
