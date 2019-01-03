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

int vis[MAXN];
int n,q;
vector<int> g[MAXN];
int order[MAXN],stamp[MAXN],childcnt[MAXN];
int dfs_clock;
int cnt;

int dfs(int u)
{
    vis[u] = 1;
    stamp[u] = ++dfs_clock;
    order[dfs_clock] = u;
    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(!vis[v])
            childcnt[u] += dfs(v) + 1;
    }
    return childcnt[u];
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=2; i<=n; i++)
    {
        int x;
        scanf("%d",&x);
        g[x].PB(i);
    }
    dfs(1);
    //for(int i=1; i<=n; i++)
    //    cout << order[i] << "-" << stamp[i] << endl;
    while(q--)
    {
        int u,x;
        scanf("%d%d",&u,&x);
        if(childcnt[u] < x - 1)
            puts("-1");
        else
            printf("%d\n",order[stamp[u]+x-1]);
    }
    return 0;
}
