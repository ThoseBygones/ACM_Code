/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-05
 *  Subject: ACM-ICPC
 *  Language: C/C++
 *  OJ: CodeForces
 *  Algorithm: dp
 ********************************************************************************
 *  Algo-Description:
 *    dp[i][j]表示第i个语句缩进为j的方案数。
 *    1.如果第i-1个是'f'，则第i个肯定要比第i个多缩进一个单位，即dp[i][j]=dp[i-1][j-1]。
 *    2.如果第i-1个是's'，则第i个可以属于前面任何一个for循环，因此第i个的缩进要<=第i+1个的缩进，即dp[i+1][j]=dp[i][k]，j<=k<=n。
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
#define MAXN 5005
#define MOD 1000000007
using namespace std;

int dp[MAXN][MAXN]; //dp[i][j]表示第i个语句缩进为j的方案数
char c[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> c[i];
    dp[1][1]=1;
    for(int i=2; i<=n; i++)
    {
        int sum=0;
        for(int j=n; j>=1; j--)
        {
            if(c[i-1]=='f')
                dp[i][j]=dp[i-1][j-1];
            else
            {
                sum=(sum+dp[i-1][j])%MOD;   //后缀和，因为这个简单语句可以属于之前的任意一个循环，因此dp[i][j]=sum(dp[i-1][j...n])
                dp[i][j]=sum;
            }
        }
    }
    int ans=0;
    for(int i=0; i<=n; i++)
        ans=(ans+dp[n][i])%MOD;
    cout << ans << endl;
    return 0;
}
