/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-18
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

LL dp[MAXN][2]; //dp[i][0/1]表示第i个位置右侧使用低柱子/高柱子需要的最少花费
char s[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        LL a,b;
        scanf("%d%lld%lld",&n,&a,&b);
        scanf("%s",s+1);
        for(int i=0; i<=n; i++)
            dp[i][0] = dp[i][1] = LINF;
        dp[0][0] = b;
        for(int i=1; i<=n; i++)
        {
            if(s[i] == '1')   //该位置为十字路口处
                dp[i][1] = min(dp[i][1],dp[i-1][1]+a+b*2);
            else
            {
                dp[i][0] = min(dp[i][0],min(dp[i-1][0]+a+b,dp[i-1][1]+a*2+b));  //要么从高变低要么一直都是低
                dp[i][1] = min(dp[i][1],min(dp[i-1][0]+a*2+b*2,dp[i-1][1]+a+b*2));  //要么从低变高要么一直都是高
            }
        }
        printf("%lld\n",dp[n][0]);
    }
    return 0;
}
