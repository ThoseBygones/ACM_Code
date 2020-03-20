/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-18
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 树形dp + 树的直径
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
#define MAXN 300005

vector<int> G[MAXN];
int dp[MAXN];   //dp[i]表示以i为根结点的子树（包括自己）有一条边连接一个度大于1的点时能构成“好树”的最大结点数（相当于一条毛毛虫）
int ans;

void dfs(int u,int fa)
{
    dp[u] = (int)G[u].size();
    for(auto v: G[u])
    {
        if(v != fa)
        {
            dfs(v, u);
            ans = max(ans, dp[u] + dp[v]);
            dp[u] = max(dp[u], dp[v] + (int)G[u].size() - 1);    //v结点被重复计算，因此减去1
        }
    }
}

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            G[i].clear();
        dp[0] = 0;
        ans = 0;
        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].PB(v);
            G[v].PB(u);
        }
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
