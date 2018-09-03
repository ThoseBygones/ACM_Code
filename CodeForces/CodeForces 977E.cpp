/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-09-03
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dfs求简单环
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
#define MAXE 200005

struct Edge
{
    int to,nxt;
    Edge() {}
    Edge(int to,int nxt):to(to),nxt(nxt) {}
} e[MAXE<<1];

int head[MAXN];
bool vis[MAXN];
int deg[MAXN];
bool flag;
int cnt;

inline void addEdge(int u,int v)
{
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dfs(int u)
{
    vis[u] = true;
    if(deg[u] != 2)
        flag = false;
    for(int i=head[u]; ~i; i=e[i].nxt)
    {
        int v = e[i].to;
        if(!vis[v])
            dfs(v);
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    cnt = 0;
    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
        deg[u]++;
        deg[v]++;
    }
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            flag = true;
            dfs(i);
            if(flag)
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
