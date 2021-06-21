/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-21
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp + 前缀和 + 后缀和
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

char s[MAXN];
int l[MAXN][MAXN], r[MAXN][MAXN];   //第i行第j列左边（右边）有多少个连续的'*'（包括自己）
int dp[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", s + 1);
            for(int j = 1; j <= m; j++)
            {
                if(s[j] == '*')
                    l[i][j] = l[i][j - 1] + 1;
                else
                    l[i][j] = 0;
            }
            for(int j = m; j; j--)
            {
                if(s[j] == '*')
                    r[i][j] = r[i][j + 1] + 1;
                else
                    r[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                dp[i][j] = min(dp[i - 1][j] + 1, min(l[i][j], r[i][j]));
                ans += dp[i][j];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
