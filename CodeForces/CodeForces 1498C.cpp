/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-10-24
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

const int MAXN = 1005;
const int MOD = 1000000007;

int dp[MAXN][MAXN]; //dp[i][j]表示某个粒子前方还需要穿过i个平面，衰变年龄为j时，这里粒子能分裂出的粒子数量

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; i++)
            dp[i][1] = 1;
        for(int i = 1; i <= k; i++)
            dp[0][i] = 1;
        for(int j = 1; j <= k; j++)
        {
            for(int i = 1; i <= n; i++)
                dp[i][j] = (dp[i - 1][j] + dp[n - i][j - 1]) % MOD;
        }
        printf("%d\n", dp[n][k]);
    }
    return 0;
}
