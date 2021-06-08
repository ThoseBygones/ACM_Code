/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-05
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

const int MAXN = 205;

int a[MAXN];
int dp[MAXN << 1][MAXN];    //dp[i][j]表示i分钟拿出第j道菜时总的最小不高兴值

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        for(int i = 0; i <= 2 * n; i++)
            fill(dp[i], dp[i] + 1 + n, INF);
        //dp[0][0] = 0;
        for(int i = 0; i <= 2 * n; i++)
            dp[i][0] = 0;
        for(int i = 1; i <= 2 * n; i++) //枚举时间
        {
            for(int j = 1; j <= n; j++) //枚举每道菜
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(a[j] - i));
        }
        printf("%d\n", dp[2 * n][n]);
    }
    return 0;
}
