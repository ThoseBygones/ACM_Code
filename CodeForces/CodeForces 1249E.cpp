/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-15
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

int a[MAXN],b[MAXN];
int dp[MAXN][2];    //dp[i][0/1]表示走楼梯/坐电梯从第i层到第i+1层所需要的最小时间（0表示走楼梯，1表示坐电梯）

int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=1; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<n; i++)
        scanf("%d",&b[i]);
    dp[1][0] = 0;
    dp[1][1] = c;
    for(int i=1; i<n; i++)
    {
        dp[i+1][0] = min(dp[i][0],dp[i][1]) + a[i]; //走楼梯
        dp[i+1][1] = min(dp[i][0]+c,dp[i][1]) + b[i];   //坐电梯
    }
    for(int i=1; i<=n; i++)
    {
        if(i != n)
            printf("%d ",min(dp[i][0],dp[i][1]));
        else
            printf("%d\n",min(dp[i][0],dp[i][1]));
    }
    return 0;
}
