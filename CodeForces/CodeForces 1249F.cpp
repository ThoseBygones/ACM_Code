/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-11
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 树形dp
 ********************************************************************************
 *  Algo-Description:
 * > 算法1：
 *    > 将所有结点按照距离根结点（随便指定）深度从大到小排序；
 *    > 如果当前结点点权 a[i] 大于 0，则将到该结点距离小于等于 k 的所有结点点权减 a[i]；
 *    > 即取了当前点，为答案贡献a[i]；
 *    > 如果之后又找到点权大于 0 的结点，说明选取新的结点更优。
 * > 算法2：
 *    > dp[u][dp]表示在u结点为根的子树中选出的结点深度不小于dep并且满足任意两个结点之间距离大于k的最大点权和
 *    > 在某棵子树上选的结点深度为dep，另外一棵子树上选的结点深度应大于k-dep
 *    > dp[u][k] = max(dp[u][i]+dp[v][max(k-i,i-1)],dp[v][i-1]+dp[u][max(k+1-i,i)]);
 *    > max(k-i,i-1)是因为dp的定义使得u子结点v的子树中选的点的深度必须大于等于i-1；同理max(k+1-i,i)
 *    > 然后求后缀最大值，因为深度更深结点的最优值可以被深度较浅的采用。
 *    > 由于两种转移会使得状态乱序，用tmp数组来维护当前子树带来的更新，最后再把更新维护到dp数组
 ********************************************************************************
 */

/* 算法1 */
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
#define MAXN 205

struct Node
{
    int id,dep;
    bool operator <(const Node &nd) const
    {
        return dep > nd.dep;    //按照距离根的深度大小排序
    }
} nd[MAXN];

int a[MAXN];  //每个点的点权

vector<int> G[MAXN];
bool vis[MAXN];
int n,k;

void dfs(int u,int fa,int d)
{
    nd[u].dep = d;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(v != fa)
            dfs(v,u,d+1);
    }
}

int bfs(int x)
{
    queue<PII> q;
    memset(vis,false,sizeof(vis));
    int val = a[x];
    q.push(MP(x,0));
    vis[x] = true;
    while(!q.empty())
    {
        PII tmp = q.front();
        q.pop();
        int u = tmp.first, dep = tmp.second;
        a[u] -= val;
        if(dep+1 <= k)
        {
            for(int i=0; i<G[u].size(); i++)
            {
                int v = G[u][i];
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(MP(v,dep+1));
                }
            }
        }
    }
    return val;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        nd[i].id = i;
    }
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1,-1,0);
    sort(nd+1,nd+1+n);
    int ans = 0;
    for(int i=1; i<=n; i++) //离根最远的点（最远的叶子节点）先遍历，无后效性
    {
        if(a[nd[i].id] > 0)
            ans += bfs(nd[i].id);
    }
    printf("%d\n",ans);
    return 0;
}

/* 算法2 */
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
#define MAXN 205

vector<int> G[MAXN];
int a[MAXN];
int dp[MAXN][MAXN]; //dp[u][dp]表示在u结点为根的子树中选出的结点深度不小于dep并且满足任意两个结点之间距离大于k的最大点权和
int tmp[MAXN];
int n,k;
int ans;

void dfs(int u,int fa)
{
    dp[u][0] = a[u];
    for(auto v: G[u])
    {
        if(v != fa)
        {
            dfs(v,u);
            dp[u][0] += dp[v][k];   //加上到u结点的子结点v距离不小于k的结点（即加上到u结点距离大于k的结点）
            memset(tmp,0,sizeof(tmp));
            tmp[0] = dp[u][0];
            for(int i=1; i<=n; i++) //枚举深度
                tmp[i] = max(dp[u][i]+dp[v][max(k-i,i-1)],dp[v][i-1]+dp[u][max(k+1-i,i)]);  //深度不小于i且满足两点之间距离大于k
            for(int i=n-1; i>=0; i--)   //求后缀最大值（因为深度更深结点的最优值可以被深度较浅的采用）
                tmp[i] = max(tmp[i],tmp[i+1]);
            for(int i=0; i<=n; i++)
                dp[u][i] = tmp[i];
        }
    }
    ans = max(ans,dp[u][0]);
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1,-1);
    printf("%d\n",ans);
    return 0;
}
