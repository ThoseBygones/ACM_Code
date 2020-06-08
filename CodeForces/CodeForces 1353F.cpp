/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-06-08
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 暴力枚举 + dp
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

const int MAXN = 105;

LL a[MAXN][MAXN];
LL dp[MAXN][MAXN];  //dp[i][j]表示从点(1,1)走到点(i,j)需要改变方格高度的最小次数

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                scanf("%lld", &a[i][j]);
        }
        LL ans = LINF;
        //枚举整个移动路径中高度不变的点
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                for(int i = 1; i <= n; i++)
                    fill(dp[i] + 1, dp[i] + 1 + m, LINF);
                dp[1][1] = 0;
                LL base = a[i][j] - (i - 1) - (j - 1);  //计算出点(i,j)为基准点下点(1,1)的标准高度
                //开始寻路
                for(int x = 1; x <= n; x++)
                {
                    for(int y = 1; y <= m; y++)
                    {
                        LL dis = base + (x - 1) + (y - 1);  //点(x,y)与点(1,1)的曼哈顿距离
                        if(dis > a[x][y])   //该点不可能通过降高度到达
                            dp[x][y] = LINF;
                        else
                        {
                            dp[x][y] += a[x][y] - dis;
                            if(x < n)
                                dp[x+1][y] = min(dp[x+1][y], dp[x][y]);
                            if(y < m)
                                dp[x][y+1] = min(dp[x][y+1], dp[x][y]);
                        }
                    }
                }
                ans = min(ans, dp[n][m]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
