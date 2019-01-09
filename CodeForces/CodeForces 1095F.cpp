/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-02
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
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
    int u,v;
    LL w;
    Edge() {}
    Edge(int u,int v,LL w):u(u),v(v),w(w) {}
    bool operator <(const Edge &ed) const
    {
        return w < ed.w;
    }
} e[MAXN<<2];

struct Node
{
    int id;
    LL cost;
    bool operator <(const Node &nd) const
    {
        return cost < nd.cost;
    }
} nd[MAXN];

int fa[MAXN];
int n,m;

int findset(int x)
{
    if(x != fa[x])
        return fa[x] = findset(fa[x]);
    return fa[x];
}

LL kruskal()
{
    sort(e,e+n+m-1);
    int cnt = n - 1;
    LL ans = 0;
    for(int i=0; i<=n; i++)
        fa[i] = i;
    for(int i=0; i<n+m-1; i++)
    {
        int fu = findset(e[i].u);
        int fv = findset(e[i].v);
        if(fu != fv)
        {
            fa[fu] = fv;
            ans += e[i].w;
            cnt--;
            if(!cnt)
                break;
        }
    }
    return cnt ? INF : ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&nd[i].cost);
        nd[i].id=i;
    }
    sort(nd+1,nd+n+1);
    for(int i=2; i<=n; i++)
        e[i+m-2]=Edge(nd[1].id,nd[i].id,nd[1].cost+nd[i].cost);
    for(int i=0; i<m; i++)
    {
        int u,v;
        LL w;
        scanf("%d%d%I64d",&u,&v,&w);
        e[i]=Edge(u,v,w);
    }
    LL ans=kruskal();
    printf("%I64d\n",ans);
    return 0;
}
