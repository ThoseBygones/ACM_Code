/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-05
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
#define MAXN 205

int a[MAXN];
LL dp[MAXN][MAXN];  //dp[i][j]表示选择第i幅画后，包括第i幅画已选了j幅画

int main()
{
    int n,k,x;
    scanf("%d%d%d",&n,&k,&x);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= x; j++)
            dp[i][j] = -1;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) //枚举当前选择的画的位置
    {
        for(int j = 1; j <= min(i,x); j++)  //枚举已选了画的数量
        {
            for(int l = max(0,i-k); l < i; l++) //枚举已选的上一幅画的位置
            {
                if(~dp[l][j-1]) //前一状态可以转移
                    dp[i][j] = max(dp[i][j],dp[l][j-1]+a[i]);
            }
        }
    }
    LL ans = -1;
    /*
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= x; j++)
            printf("(%d,%d): %d\n",i,j,dp[i][j]);
    }
    */
    for(int i = n-k+1; i <= n; i++)
        ans = max(ans,dp[i][x]);
    printf("%I64d\n",ans);
    return 0;
}
