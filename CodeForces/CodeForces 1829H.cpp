/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-01-31
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

const int MAXN  = 200005;
const int MOD = 1000000007;

int dp[MAXN][65];   //dp[i][j]为前i个数构成与和为j的方案数
int a[MAXN];

bool isK(int x, int k)
{
    int cnt = 0;
    for(int i = 0; i < 6; i++)
    {
        if((x >> i) & 1)
            cnt++;
    }
    return cnt == k ? true : false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < 64; j++)
                dp[i][j] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            dp[i][a[i]] = 1;
            for(int j = 0; j < 64; j++)
            {
                dp[i][j & a[i]] = (dp[i][j & a[i]] + dp[i - 1][j]) % MOD; //序列中保留第i个数
                dp[i][j] = (dp[i][j] +  dp[i - 1][j]) % MOD;    //序列中不保留第i个数
            }
        }
        int ans = 0;
        for(int i = 0; i < 64; i++)
        {
            if(isK(i, k))   //判断数位和是否为k
                ans = (ans + dp[n][i]) % MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}
