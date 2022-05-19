/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-16
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp + 图论
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

const int MAXN = 5005;

int tag[MAXN];
LL s[MAXN];
LL dp[MAXN];    //dp[i]表示最后一个问题为i时的最大贡献

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &tag[i]);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &s[i]);
        for(int j = 2; j <= n; j++) //从小到大枚举 j，j - i 差固定时，(2 ^ j - 2 ^ i) 的值越大
        {
            for(int i = j - 1; i; i--)  //从大到小枚举 i，保证 (2 ^ j - 2 ^ i) 的值
            {
                if(tag[i] != tag[j])
                {
                    LL pre_i = dp[i], pre_j = dp[j];
                    dp[i] = max(dp[i], pre_j + abs(s[i] - s[j]));
                    dp[j] = max(dp[j], pre_i + abs(s[i] - s[j]));
                }
            }
        }
        LL ans = 0;
        for(int i = 1; i <= n; i++)
            ans = max(ans, dp[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
