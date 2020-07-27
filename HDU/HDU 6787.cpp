/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: dp（滚动数组） / 预处理 + dp
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

const int MAXN = 1005;
const int MOD = 1000000007;

/* dp（滚动数组）（748ms）*/

LL dp[2][MAXN][11]; //（滚动数组）dp[i][j][k]表示当前到位置i，已经放置了j个传感器，若位置i放置传感器则到位置i已经有连续k个传感器，此时总的方案数

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int j = 0; j <= m; j++)
        {
            for(int k = 0; k <= 10; k++)
                dp[0][j][k] = dp[1][j][k] = 0;
        }
        dp[1][0][0] = 1;
        int cur = 0;
        for(int i = 2; i <= n; i++) //枚举当前到位置i（位置1不能放传感器）
        {
            for(int j = 0; j <= min(i, m); j++) //枚举已经放置的传感器数量
            {
                for(int k = 0; k <= 10; k++)    //枚举连续的传感器数量
                {
                    dp[cur][j][0] = (dp[cur][j][0] + dp[cur^1][j][k]) % MOD;  //位置i不放置传感器
                    if(k && j)  //如果当前到位置i-1已经连续的传感器数量不到10个，则位置i还能放置传感器
                        dp[cur][j][k] = (dp[cur][j][k] + dp[cur^1][j-1][k-1] * (i - 1) % MOD) % MOD;  //乘以传感器可以传送到的位置数量（位置i自己不能被传送）
                }
            }
            cur ^= 1;
            for(int j = 0; j <= m; j++) //清空接下来要更新的数组
            {
                for(int k = 0; k <= 10; k++)
                    dp[cur][j][k] = 0;
            }
        }
        //printf("cur: %d\n", cur);
        printf("%lld\n", dp[cur^1][m][0] ? dp[cur^1][m][0] : -1);
    }
    return 0;
}


/* 预处理 + dp （109ms） */

int dp[MAXN][MAXN][11]; //dp[i][j][k]表示当前到位置i，已经放置了j个传感器，若位置i放置传感器则到位置i已经有连续k个传感器，此时总的方案数

int main()
{
    int t;
    scanf("%d", &t);
    /* 预处理dp */
    dp[1][0][0] = 1;
    for(int i = 2; i <= 1000; i++) //枚举当前到位置i（位置1不能放传感器）
    {
        for(int j = 0; j <= i; j++) //枚举已经放置的传感器数量
        {
            for(int k = 0; k <= 10; k++)    //枚举连续的传感器数量
            {
                dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][k]) % MOD;  //位置i不放置传感器
                if(k && j)  //如果当前到位置i-1已经连续的传感器数量不到10个，则位置i还能放置传感器
                    dp[i][j][k] = (dp[i][j][k] + 1LL * dp[i-1][j-1][k-1] * (i - 1) % MOD) % MOD;  //乘以传感器可以传送到的位置数量（位置i自己不能被传送）
            }
        }
    }
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%d\n", dp[n][m][0] ? dp[n][m][0] : -1);
    }
    return 0;
}
