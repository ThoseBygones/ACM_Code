/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-10-05
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 树形dp
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 100005;

vector<int> G[MAXN];
LL l[MAXN], r[MAXN];
LL dp[MAXN][2];    //dp[u][0/1]表示u结点选取[l, r]区间中l/r值时，其和其子结点能获得的最大贡献总和

void dfs(int u, int fa)
{
    dp[u][0] = dp[u][1] = 0;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(v != fa)
        {
            dfs(v, u);
            dp[u][0] += max(dp[v][0] + abs(l[u] - l[v]), dp[v][1] + abs(l[u] - r[v]));
            dp[u][1] += max(dp[v][0] + abs(r[u] - l[v]), dp[v][1] + abs(r[u] - r[v]));
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            G[i].clear();
        for(int i = 1; i <= n; i++)
            scanf("%lld%lld", &l[i], &r[i]);
        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].PB(v);
            G[v].PB(u);
        }
        dfs(1, -1);
        printf("%lld\n", max(dp[1][0], dp[1][1]));
    }
    return 0;
}
