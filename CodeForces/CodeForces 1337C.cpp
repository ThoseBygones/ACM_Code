/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-28
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

vector<int> G[MAXN];
int dep[MAXN];  //结点的深度
int cnt[MAXN];  //该结点所在子树的大小（包括该结点）
int val[MAXN];  //计算当前结点设为工业结点时对特使旅行幸福度的影响

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    cnt[u] = 1;
    for(auto v: G[u])
    {
        if(v != fa)
        {
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        val[i] = dep[i] - cnt[i];
    sort(val + 1, val + 1 + n, greater<int>());
    LL ans = 0;
    for(int i = 1; i <= k; i++)
        ans += val[i];
    printf("%lld\n", ans);
    return 0;
}
