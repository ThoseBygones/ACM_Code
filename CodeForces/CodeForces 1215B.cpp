/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-25
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp
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
#define MAXN 200005

LL dp[2][MAXN];    //dp[0/1][i]表示前i个数中子序列之积为负/正的数量

int main()
{
    int n;
    scanf("%d",&n);
    int cnt = 0;    //负数的数量
    for(int i=1; i<=n; i++)
    {
        int x;
        scanf("%d",&x);
        if(x > 0)
        {
            dp[0][i] = dp[0][i-1] + cnt;
            dp[1][i] = dp[1][i-1] + i - cnt;
        }
        else
        {
            dp[0][i] = dp[0][i-1] + i - cnt;
            dp[1][i] = dp[1][i-1] + cnt;
            cnt = i - cnt;
        }
    }
    printf("%lld %lld\n",dp[0][n],dp[1][n]);
    return 0;
}
