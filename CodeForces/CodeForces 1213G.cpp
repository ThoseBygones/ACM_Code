/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-01
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 并查集 + 离线查询
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

struct Query
{
    int id,val;
    LL ans;
} q[MAXN];

struct Edge
{
    int u,v,w;
    Edge() {}
    Edge(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator <(const Edge &ed) const
    {
        return w < ed.w;
    }
} e[MAXN];

int fa[MAXN],cnt[MAXN]; //每个集合中点的数量

bool cmp1(Query a,Query b)
{
    return a.val < b.val;
}

bool cmp2(Query a,Query b)
{
    return a.id < b.id;
}

int findset(int x)
{
    if(x != fa[x])
        return fa[x] = findset(fa[x]);
    return fa[x];
}

void unionset(int x,int y)
{
    int fx = findset(x);
    int fy = findset(y);
    fa[fx] = fy;
    cnt[fx] += cnt[fy];
    cnt[fy] = cnt[fx];
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<n; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[i] = Edge(u,v,w);
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d",&q[i].val);
        q[i].id = i;
        q[i].ans = 0;
    }
    for(int i=1; i<=n; i++)
    {
        fa[i] = i;
        cnt[i] = 1;
    }
    sort(e+1,e+n);
    sort(q,q+m,cmp1);
    for(int i=0, j=1; i<m; i++)
    {
        q[i].ans = q[i-1].ans;
        while(j < n && e[j].w <= q[i].val)
        {
            int u = e[j].u;
            int v = e[j].v;
            q[i].ans += 1LL * cnt[findset(u)] * cnt[findset(v)];
            unionset(u,v);
            j++;
        }
    }
    sort(q,q+m,cmp2);
    for(int i=0; i<m; i++)
    {
        if(i == 0)
            printf("%I64d",q[i].ans);
        else
            printf(" %I64d",q[i].ans);
    }
    puts("");
    return 0;
}
