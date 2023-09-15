/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:2023-09-06
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 505;
const int MAXK = 22;

int x[MAXN][MAXN], y[MAXN][MAXN];   //x方向上行动、y方向上行动
int dp[MAXK][MAXN][MAXN];   //dp[k][i][j]表示从(i, j)出发走k步的最小无聊值

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < m; j++)
            scanf("%d", &y[i][j]);
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= m; j++)
            scanf("%d", &x[i][j]);
    }
    if(k & 1)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                printf("-1%c", j == m ? '\n' : ' ');
        }
        return 0;
    }
    for(int s = 1; s <= k / 2; s++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                dp[s][i][j] = INF;
        }
    }
    for(int s = 1; s <= k / 2; s++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(i > 1)
                    dp[s][i - 1][j] = min(dp[s][i - 1][j], dp[s - 1][i][j] + x[i - 1][j]);
                if(i < n)
                    dp[s][i + 1][j] = min(dp[s][i + 1][j], dp[s - 1][i][j] + x[i][j]);
                if(j > 1)
                    dp[s][i][j - 1] = min(dp[s][i][j - 1], dp[s - 1][i][j] + y[i][j - 1]);
                if(j < m)
                    dp[s][i][j + 1] = min(dp[s][i][j + 1], dp[s - 1][i][j] + y[i][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            printf("%d%c", dp[k / 2][i][j] * 2, j == m ? '\n' : ' ');
    }
    return 0;
}
