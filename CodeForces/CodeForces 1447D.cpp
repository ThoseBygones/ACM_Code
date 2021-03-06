/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-09
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

const int MAXN = 5005;

char a[MAXN], b[MAXN];
int dp[MAXN][MAXN]; //dp[i][j]表示的最大S(a[1..i], b[1...j])值

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 4 - 2;
            else    //遇到不相等的，如果包括这一个字符后贡献为负，不如重新开始
                dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]) - 1, 0);
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
