/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-13
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
#define MAXN 100005
#define MAXM 85

int l[MAXM], r[MAXM];
int dp[MAXN];   //dp[i]表示天线已经覆盖了1~i的区域，还要把区域i+1~m覆盖掉需要的最小花费

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        int x, s;
        scanf("%d%d", &x, &s);
        l[i] = max(x - s, 0);
        r[i] = min(x + s, m);
    }
    for(int i = m - 1; i >= 0; i--)
    {
        dp[i] = m - i;
        for(int j = 0; j < n; j++)
        {
            if(l[j] <= i + 1 && i + 1 <= r[j])  //该点被某个天线包括
                dp[i] = dp[i+1];    //不需要扩展天线的覆盖范围
            else if(i < l[j])   //如果该点与某个天线覆盖范围左边界之间还有点没被覆盖到
                dp[i] = min(dp[i], dp[min(m, r[j] + l[j] - i - 1)] + l[j] - i - 1);   //要么不扩大这个天线的覆盖范围，要么直接让天线包了这个区域
        }
    }
    /*for(int i = 0; i <= m; i++)
        printf("%d ", dp[i]);
    */
    printf("%d\n", dp[0]);
    return 0;
}
