/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp（思维巧妙）
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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

const int MAXN = 3005;

int a[MAXN];
int dp[MAXN][MAXN]; //dp[i][j]表示到达点i只有一种方案（一条路径），i的上一个点为k（从k到i），从k点能到达最远位置为j（k + a[k] <= j）时的最小修改次数

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                dp[i][j] = INF;
        }
        for(int i = 2; i <= n; i++) //1号点不能被修改
        {
            int cnt = 0;    //cnt表示[j + 1, i - 1]中能到达点i的点的个数（这些点都要删除，因为如果j通过这些点再到达i也是不合法的）
            for(int j = i - 1; j; j--)
            {
                if(j + a[j] >= i)   //j + a[j] 都不能到达i的不参与计算
                    dp[i][j + a[j]] = min(dp[i][j + a[j]], dp[j][i - 1] + (cnt++)); //j之前的那个点最远只能到达i-1号点（能到达i就不合法了）
            }
            for(int j = i + 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][j - 1]); //对于最远位置不超过j∈[i+1,...,n]的情况，dp[i][j-1]也是其中一种方案，所以需要维护后缀最小值
        }
        printf("%d\n", dp[n][n]);
    }
    return 0;
}
