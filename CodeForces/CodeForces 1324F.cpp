/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-15
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 树形dp + DFS
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

vector<int> G[MAXN];
int a[MAXN];
int val[MAXN];  //val[i]表示以i为根的子图（i以及i的子树）构成的最大白黑结点数差
int dp[MAXN];   //dp[i]表示除去i以及i的子树后构成的最大白黑结点数差
int ans[MAXN];  //ans[i]表示包含i结点的子图构成的最大白黑结点数差

//第一次dfs，从下往上更新val数组
void dfs1(int u,int fa)
{
    val[u] = a[u];
    for(auto v: G[u])
    {
        if(v != fa)
        {
            dfs1(v,u);
            val[u] += max(0,val[v]);    //值为负的子树不取
        }
    }
}

//第二次dfs，自顶向下dp并更新ans数组
void dfs2(int u,int fa)
{
    ans[u] = dp[u] + val[u];
    for(auto v: G[u])
    {
        if(v != fa)
        {
            dp[v] = max(0,ans[u]-max(0,val[v]));   //若v以及v的子树值为负则最优解中不需要去除
            dfs2(v,u);
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if(!a[i])
            a[i] = -1;
    }

    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    for(int i=1; i<=n; i++)
        printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}
