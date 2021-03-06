/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-26
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp递推
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 100005

const LL MOD = 1e9 + 7;

LL dp[MAXN];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    dp[1] = 2, dp[2] = 4;
    for(int i = 3; i <= max(n, m); i++)
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    LL ans = (dp[m] - 2 + dp[n]) % MOD;    //第一行的排列除了“黑白黑白...” 和“白黑白黑...”两种情况外，其他涂色方案均会使其他行的涂色方案固定
    printf("%lld\n", ans);
    return 0;
}
