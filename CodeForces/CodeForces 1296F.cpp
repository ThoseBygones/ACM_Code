/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-17
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 树上dfs
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
#define MAXN 5005

struct Query
{
    int u,v,g;
    Query() {}
    Query(int u,int v,int g):u(u),v(v),g(g) {}
} q[MAXN];

vector<int> G[MAXN];
int u[MAXN],v[MAXN];
int par[MAXN];   //par[i]表示以1号结点为根的树中，结点i的父结点
int dep[MAXN];  //dep[i]表示结点i的深度
int val[MAXN];  //val[i]表示以1号结点为根的有向树（边的方向为父结点指向子结点），出点为i的边的权值

void dfs(int u,int fa)
{
    dep[u] = dep[fa] + 1;
    par[u] = fa;
    for(auto v: G[u])
    {
        if(v != fa)
            dfs(v,u);
    }
}

void modify(Query q)
{
    int x = q.u, y = q.v;
    while(x != y)   //从叶结点往上遍历至两个结点的公共祖先结点
    {
        if(dep[x] < dep[y])
            swap(x,y);
        val[x] = max(val[x],q.g);   //更新对边最小值的限制
        x = par[x];
    }
}

bool check(Query q)
{
    int Min = INF;  //该路径上边的最小值
    int x = q.u, y = q.v;
    while(x != y)   //从叶结点往上遍历至两个结点的公共祖先结点
    {
        if(dep[x] < dep[y])
            swap(x,y);
        Min = min(Min,val[x]);
        x = par[x];
    }
    if(Min != q.g)
        return false;
    return true;
}

int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].PB(v[i]);
        G[v[i]].PB(u[i]);
        val[i+1] = 1; //边的最小长度为1
    }
    dfs(1,0);
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        q[i] = Query(u,v,w);
    }
    for(int i=0; i<m; i++)
        modify(q[i]);
    for(int i=0; i<m; i++)
    {
        if(!check(q[i]))
        {
            puts("-1");
            return 0;
        }
    }
    for(int i=1; i<n; i++)
    {
        int ans = v[i];
        if(dep[u[i]] > dep[v[i]])
            ans = u[i];
        printf("%d%c",val[ans],i==n-1?'\n':' ');
    }
    return 0;
}
