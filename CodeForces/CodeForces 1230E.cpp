/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-08
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 树上dfs + 数论（GCD）
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
#define MOD 1000000007
#define MAXN 100005

vector<int> G[MAXN];
map<LL, int> mp[MAXN];  //用vector记录会MLE
LL x[MAXN];
LL ans;

void dfs(int u, int fa) //自上往下更新，状态递增（若自下往上更新，底层的信息多，回溯时需要网上带的信息太多）
{
    for(auto it: mp[fa])    //加上从根到父结点路径上的所有贡献
    {
        LL res = __gcd(it.first, x[u]);
        mp[u][res] += it.second;
        ans = (ans + res * it.second % MOD) % MOD;
    }
    //加上自己的贡献
    mp[u][x[u]]++;
    ans = (ans + x[u]) % MOD;
    for(auto v: G[u])
    {
        if(v != fa)
            dfs(v, u);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}
