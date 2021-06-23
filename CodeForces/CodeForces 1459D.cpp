/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp（二维费用背包问题）
 ********************************************************************************
 *  Algo-Description:
 * > 二维费用背包内层两重循环均变为倒序的理由：
 *   > 因为 dp[i][j][k] 是由 dp[i - 1][j - 1][k - a[i]] 推导出来的，而不是 dp[i][j - 1][k - a[i]]
 *   > 所以 dp[i][j - 1][k - a[i]] 必须后于 dp[i][j][k] 求值才能保证 dp[i][j][k] 是由 dp[i - 1][j - 1][k - a[i]] 推导而来
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

int a[MAXN], b[MAXN];
int dp[MAXN][MAXN * MAXN];  //dp[i][j]表示n个瓶子中选择i个，所有瓶子总容积为j时所有这些杯子内已有水的容积的最大值

int main()
{
    int n;
    scanf("%d", &n);
    int suma = 0, sumb = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        suma += a[i];
        sumb += b[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) //枚举前i个瓶子
    {
        for(int j = i; j; j--)  //倒序遍历选择的瓶子
        {
            for(int k = suma; k >= a[i]; k--)
            {
                if(~dp[j - 1][k - a[i]])
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - a[i]] + b[i]);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        double ans = 0.0;
        for(int j = 0; j <= suma; j++)
        {
            if(~dp[i][j])
                ans = max(ans, min(1.0 * j, 1.0 * dp[i][j] + 1.0 * (sumb - dp[i][j]) / 2.0));
        }
        printf("%.10f%c", ans, (i == n ? '\n' : ' '));
    }
    return 0;
}
