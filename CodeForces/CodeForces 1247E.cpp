/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-30
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp + 后缀和
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

const int MOD = 1e9 + 7;

char g[MAXN][MAXN];
int cnt[MAXN][MAXN][2]; //每行每列的石头数（后缀和）
int dp[MAXN][MAXN][2];  //dp[i][j][0/1]表示从点(i,j)处下一步向右/向下走到点(n,m)处的方案数

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%s", g[i] + 1);
    if(g[n][m] == 'R')
        puts("0");
    else if(n == 1 && m == 1)
        puts("1");
    else
    {
        for(int i = n; i; i--)
        {
            for(int j = m; j; j--)
            {
                cnt[i][j][0] = cnt[i][j+1][0] + (g[i][j] == 'R');   //计算第i行上的石头后缀和
                cnt[i][j][1] = cnt[i+1][j][1] + (g[i][j] == 'R');   //计算第j列上的石头后缀和
            }
        }
        for(int i = 1; i < n; i++)
        {
            if(!cnt[i][m][1])   //最后一列上的点(i,m)在推完石头后仍然不会被石头所占去
                dp[i][m][1] = 1;
        }
        for(int i = 1; i < m; i++)
        {
            if(!cnt[n][i][0])   //最后一行上的点(n,i)在推完石头后仍然不会被石头所占去
                dp[n][i][0] = 1;
        }
        for(int i = n - 1; i; i--)
        {
            for(int j = m - 1; j; j--)
            {
                if(g[i][j+1] == 'R')    //该点往右一格处有石头
                    dp[i][j][0] = ((dp[i][j+1][0] + dp[i][j+1][1]) % MOD - dp[i][m-cnt[i][j+1][0]+1][1] + MOD) % MOD;   //减去从点(i,j+1)往右将石头推到最右边后，向右找到的第一个有石头的点处向左倒推回来的方案数
                else
                    dp[i][j][0] = (dp[i][j+1][0] + dp[i][j+1][1]) % MOD;
                if(g[i+1][j] == 'R')    //该点往下一格处有石头
                    dp[i][j][1] = ((dp[i+1][j][0] + dp[i+1][j][1]) % MOD - dp[n-cnt[i+1][j][1]+1][j][0] + MOD) % MOD;   //减去从点(i+1,j)往下将石头推到最下边后，向下找到的第一个有石头的点处向上倒推回来的方案数
                else
                    dp[i][j][1] = (dp[i+1][j][0] + dp[i+1][j][1]) % MOD;
            }
        }
        printf("%d\n", (dp[1][1][0] + dp[1][1][1]) % MOD);
    }
    return 0;
}
