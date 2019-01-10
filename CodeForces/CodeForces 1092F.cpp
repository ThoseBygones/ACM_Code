/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-10
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 树形dp
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

vector<int> g[MAXN];
int a[MAXN];
LL tmp[MAXN];  //tmp[i]表示i结点及其子树中所有结点的权值和
LL dp[MAXN];   //dp[i]表示以i结点为根能获得的最大权值和
LL sum;
LL ans;

//自底向上
void dfs1(int u,int fa)
{
    tmp[u] = a[u];
    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(v != fa)
        {
            dfs1(v,u);
            dp[u] += dp[v] + tmp[v];    //自底向上更新dp[u]
            tmp[u] += tmp[v];
        }
    }
}

//自顶向下
void dfs2(int u,int fa)
{
    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(v != fa)
        {
            dp[v] = dp[u] - tmp[v] + sum - tmp[v]; //自顶向下修正dp[v]
            dfs2(v,u);
        }
    }
    ans = max(ans,dp[u]);
}

int main()
{
    int n;
    scanf("%d",&n);
    sum = 0;
    ans = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    for(int i = 1; i < n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    printf("%I64d\n",ans);
    return 0;
}
