/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-03-12
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
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

int dp[5][5];   //dp[i][j]表示拼成i个侧门柱和j个门梁最少需要的木条数量

int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
            dp[i][j]=INF;
    }
    dp[0][0]=0;
    for(int i=0; i<=4; i++)
    {
        for(int j=0; j<=2; j++)
        {
            for(int k=0; k<=i; k++)
            {
                if(k*a<=n)
                    dp[i][j]=min(dp[i][j],dp[max(i-k,0)][max(j-(n-k*a)/b,0)]+1);
            }
        }
    }
    printf("%d\n",dp[4][2]);
    return 0;
}
