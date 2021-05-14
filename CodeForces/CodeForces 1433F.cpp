/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-12
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 72;

int a[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN >> 1][MAXN];    //dp[i][j][cnt][rem]表示到第i行第j列且第i行已经取了cnt个数此时和对k取模余rem时和的最大值

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    }
    memset(dp, -1, sizeof(dp));
    dp[1][1][0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int cnt = 0; cnt <= m / 2; cnt++)   //枚举已经取了的个数
            {
                for(int rem = 0; rem < k; rem++)    //枚举余数
                {
                    if(~dp[i][j][cnt][rem]) //当前状态存在
                    {
                        //不取数的情况
                        if(j < m)   //该行还未到头
                            dp[i][j + 1][cnt][rem] = max(dp[i][j + 1][cnt][rem], dp[i][j][cnt][rem]);   //不取a[i][j]
                        else    //该行已经到头，切换到下一行
                            dp[i + 1][1][0][rem] = max(dp[i + 1][1][0][rem], dp[i][j][cnt][rem]);   //不取a[i][j]
                        if(cnt + 1 <= m / 2)    //还能再取数
                        {
                            if(j < m)   //该行还未到头
                                dp[i][j + 1][cnt + 1][(rem + a[i][j]) % k] = max(dp[i][j + 1][cnt + 1][(rem + a[i][j]) % k], dp[i][j][cnt][rem] + a[i][j]); //取a[i][j]
                            else    //该行已经到头
                                dp[i + 1][1][0][(rem + a[i][j]) % k] = max(dp[i + 1][1][0][(rem + a[i][j]) % k], dp[i][j][cnt][rem] + a[i][j]); //取a[i][j]
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", dp[n + 1][1][0][0]);
    return 0;
}
