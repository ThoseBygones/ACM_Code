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

int cnt;
int head[MAXN];
int vis[MAXN];
int u[MAXN],v[MAXN];
vector<int> ans;
int n;
struct Edge
{
    int to,nxt;
    Edge() {}
    Edge(int to,int nxt):to(to),nxt(nxt) {}
} e[MAXN<<1];

inline void addEdge(int u,int v)
{
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dfs(int u)
{
    vis[u]=1;
    for(int i=head[u]; ~i; i=e[i].nxt)
    {
        int v=e[i].to;
        if(!vis[v])
        {
            ans.PB(v);
            dfs(v);
        }
    }
}

int main()
{
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    cnt=0;
    for(int i=1; i<=n; i++)
        scanf("%d%d",&u[i],&v[i]);
    if(n==3)
    {
        printf("1 2 3\n");
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        if(u[u[i]]==v[i] || v[u[i]]==v[i])
            addEdge(u[i],v[i]);
        else
            addEdge(v[i],u[i]);
    }
    memset(vis,0,sizeof(vis));
    ans.PB(1);
    dfs(1);
    for(int i=0; i<ans.size(); i++)
    {
        if(i)
            printf(" %d",ans[i]);
        else
            printf("%d",ans[i]);
    }
    puts("");
    return 0;
}
