/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-21
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

int a[MAXN];
int tmp[MAXN];  //tmp[i]表示前i个数当前的递增数
int dp[MAXN];   //dp[i]表示前i个数跳过第i-1个数后当前的递增数

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    tmp[1] = dp[1] = 1;
    for(int i=2; i<=n; i++)
    {
        if(a[i-1] < a[i])
        {
            tmp[i] = tmp[i-1] + 1;
            dp[i] = dp[i-1] + 1;
        }
        else
        {
            tmp[i] = 1;
            dp[i] = 1;
        }
        if(a[i-2] < a[i])
            dp[i] = max(dp[i],tmp[i-2]+1);
    }
    int ans = dp[1];
    for(int i=2; i<=n; i++)
        ans = max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}
