/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-25
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

const int MAXN = 505;

int a[MAXN], b[MAXN];
LL dp[MAXN][MAXN]; //dp[i][j]表示采摘了前i棵树以后，当前篮子里有j个红果子时最多能装满的篮子数量

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &a[i], &b[i]);
    LL sum = 0; //所有果子的数量
    LL ans = 0;
    memset(dp, -1, sizeof(dp));
    dp[1][0] = 0;
    for(int i = 1; i <= n; i++) //枚举采摘的树
    {
        for(int j = 0; j < k; j++)  //枚举篮子中剩余的红果子数量
        {
            if(~dp[i][j])   //前一状态存在
            {
                LL bcnt = sum - dp[i][j] * k - j;
                for(int r = 0; r <= a[i] && r < k; r++) //枚举与同一棵树中蓝果子合并放置的红果子数量
                {
                    dp[i + 1][(j + a[i]) % k] = max(dp[i + 1][(j + a[i]) % k], dp[i][j] + (j + a[i]) / k + (bcnt + b[i]) / k);  //不把本棵树的红蓝果实合并放置的情况
                    ans = max(ans, dp[i + 1][(j + a[i]) % k]);
                    if(r + b[i] >= k)   //如果合并放置能放满甚至放超过
                    {
                        //优先合并放置
                        LL bleft = bcnt + (b[i] - (k - r)); //剩余的蓝果子
                        int aleft = j + a[i] - r;    //剩余的红果子
                        dp[i + 1][aleft % k] = max(dp[i + 1][aleft % k], dp[i][j] + bleft / k + aleft / k + 1); //合并的一篮子，剩下的分类分篮子放置
                        ans = max(ans, dp[i + 1][aleft % k]);
                    }
                }
            }
        }
        sum += a[i] + b[i];
    }
    printf("%lld\n", ans);
    return 0;
}
