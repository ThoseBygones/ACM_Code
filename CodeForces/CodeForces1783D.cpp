/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-10-16
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

const int MAXN = 300;
const int OFFSET = MAXN * MAXN;
const int MOD = 998244353;

int a[MAXN + 5];
int dp[MAXN + 5][(OFFSET << 1) + 5];    //dp[i][j]表示操作完前i个数时，元素a[i + 1] = j时的方案数

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)\
        scanf("%d", &a[i]);
    dp[1][a[2] + OFFSET] = 1;   //初始化（第1个数不会被操作）
    for(int i = 2; i < n; i++)
    {
        for(int j = -OFFSET; j <= OFFSET; j++)
        {
            if(dp[i - 1][j + OFFSET])   //前置状态存在
            {
                if(j == 0)  //当前操作的元素a[i] = 0，意味着操作后序列不变，只能从dp[i - 1][a[i] == 0]状态转移过来
                    dp[i][a[i + 1] + OFFSET] = (dp[i][a[i + 1] + OFFSET] + dp[i - 1][OFFSET]) % MOD;
                else
                {
                    dp[i][a[i + 1] + j + OFFSET] = (dp[i][a[i + 1] + j + OFFSET] + dp[i - 1][j + OFFSET]) % MOD;    //操作后元素a[i + 1] += j
                    dp[i][a[i + 1] - j + OFFSET] = (dp[i][a[i + 1] - j + OFFSET] + dp[i - 1][j + OFFSET]) % MOD;    //操作后元素a[i + 1] -= j
                }
            }
        }
    }
    int ans = 0;
    for(int j = -OFFSET; j <= OFFSET; j++)
        ans = (ans + dp[n - 1][j + OFFSET]) % MOD;
    printf("%d\n", ans);
    return 0;
}
