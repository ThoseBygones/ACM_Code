/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-09-03
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: 洛谷
 *  Algorithm: dfs
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

const int MAXN = 105;

bool g[MAXN][MAXN];
int col[MAXN];
int n, k, m, ans;

bool check(int x)
{
    for(int i = 1; i < x; i++)
    {
        if(g[x][i] && col[x] == col[i])
            return false;
    }
    return true;
}

void dfs(int x)
{
    if(x > n)
    {
        ans++;
        return ;
    }
    for(int i = 1; i <= m; i++)
    {
        col[x] = i;
        if(check(x))
            dfs(x + 1);
        else
            col[x] = 0;
    }
}

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    for(int i = 1; i <= k; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = true;
    }
    memset(col, 0, sizeof(col));
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
