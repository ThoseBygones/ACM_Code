/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-02-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp
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
char s[MAXN];
int dp[MAXN][2];    //dp[i][j]表示把i点当做j类型点需要的最小花费（j取值为0和1，0/1分别表示music类型和silence类型）

void dfs(int u, int fa)
{
    if(s[u] == 'P')
    {
        dp[u][0] = 0;
        dp[u][1] = INF;
    }
    else if(s[u] == 'S')
    {
        dp[u][0] = INF;
        dp[u][1] = 0;
    }
    else if(s[u] == 'C')
        dp[u][0] = dp[u][1] = 0;
    for(auto v: G[u])
    {
        if(v != fa)
        {
            dfs(v, u);  //先搜索，回溯的时候再更新
            if(s[u] == 'P') //music点
                dp[u][0] += min(dp[v][0], dp[v][1] + 1); //子结点v如果是music点则不需要建墙，否则需要建
            else if(s[u] == 'S')    //silence点
                dp[u][1] += min(dp[v][0] + 1, dp[v][1]); //子结点v如果是music点则需要建墙，否则不需要建
            else if(s[u] == 'C')    //don't care点
            {
                dp[u][0] += min(dp[v][0], dp[v][1] + 1); //该点当做music点对待
                dp[u][1] += min(dp[v][0] + 1, dp[v][1]); //该点当做silence点对待
            }
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
        for(int u = 2; u <= n; u++)
        {
            int v;
            scanf("%d", &v);
            G[u].PB(v);
            G[v].PB(u);
        }
        scanf("%s", s + 1);
        dfs(1, 0);
        printf("%d\n", min(dp[1][0], dp[1][1]));
    }
    return 0;
}
