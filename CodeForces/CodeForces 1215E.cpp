/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-25
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 状态压缩dp
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

int pre[25];    //pre[i]表示当前颜色之前颜色i的数量
LL cnt[25][25];    //cnt[i][j]表示将所有颜色i移动到所有颜色j之前需要交换的次数
LL dp[1<<20];   //dp[S]中S的每一位表示一种颜色的就位情况（0表示未就位，1表示已就位），dp[S]表示达到状态S需要交换的最小次数

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        int col;
        scanf("%d",&col);
        col--;
        for(int j=0; j<20; j++)
            cnt[col][j] += pre[j];
        pre[col]++;
    }
    fill(dp,dp+(1<<20),LINF);
    dp[0] = 0;
    for(int S=0; S<(1<<20); S++)    //枚举状态S（当前各颜色就位情况）
    {
        for(int i=0; i<20; i++) //枚举需要调整（未就位）的颜色
        {
            if(!(S & (1 << i)))  //如果该颜色还未就位
            {
                LL sum = 0;
                for(int j=0; j<20; j++) //枚举颜色i需要移动到其之前的颜色
                {
                    if((S & (1 << j)))  //如果该颜色已就位（这样能保证之后不会再被移动，避免重复计算）
                        sum += cnt[i][j];
                }
                dp[S|(1<<i)] = min(dp[S|(1<<i)],dp[S]+sum);
            }
        }
    }
    printf("%lld\n",dp[(1<<20)-1]);
    return 0;
}
