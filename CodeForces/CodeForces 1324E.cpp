/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-12
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
#define MAXN 2005

int a[MAXN];
int dp[MAXN][MAXN]; //dp[i][j]表示第i次睡眠在一天中的第j个小时开始时总的“好睡眠”的最大数量

int main()
{
    int n,h,l,r;
    scanf("%d%d%d%d",&n,&h,&l,&r);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=n; i; i--)
    {
        for(int j=0; j<h; j++)
        {
            int k1 = (j - a[i] + h) % h;
            int k2 = (j - (a[i] - 1) + h) % h;
            dp[i-1][k1] = max(dp[i-1][k1], dp[i][j] + (l <= j && j <= r));
            dp[i-1][k2] = max(dp[i-1][k2], dp[i][j] + (l <= j && j <= r));
        }
    }
    /*for(int i=0; i<=n; i++)
    {
        for(int j=0; j<24; j++)
            printf("%d ",dp[i][j]);
        puts("");
    }
    */
    printf("%d\n",dp[0][0]);
    return 0;
}
