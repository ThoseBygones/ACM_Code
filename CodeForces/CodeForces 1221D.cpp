/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-07
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
#define MAXN 300005

LL a[MAXN], b[MAXN];
LL dp[MAXN][3]; //dp[i][j]表示第i块板增加j长度后使前i块板都是“棒的”需要的最小花费

int main()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld%lld", &a[i], &b[i]);
        for(int i = 1; i <= n; i++)
            fill(dp[i], dp[i]+3, LINF);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < 3; j++)  //枚举第i块板增加的高度
            {
                for(int k = 0; k < 3; k++)  //枚举前一块（第i-1块）板增加的高度
                {
                    if(a[i-1] + k != a[i] + j)  //当前方案满足前i块板是“棒的”的要求
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + b[i] * j);
                }
            }
        }
        printf("%lld\n",min(dp[n][0], min(dp[n][1], dp[n][2])));
    }
    return 0;
}

/*
1
20
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
1000000000 1000000000
*/
