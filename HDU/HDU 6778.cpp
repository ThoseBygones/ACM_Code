/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm:
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

int cnt[10];
int dp[6][1<<10];   //dp[i][S]表示前i天车牌限号状态为S（某一位为1表示该位对应的尾号被限制，0表示未被限制）时每一天不被限号的车的总数

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        char s[6];
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++)
        {
            scanf("%s", s);
            cnt[s[4]-'0']++;
        }
        memset(dp, -1, sizeof(dp));
        fill(dp[0], dp[0] + (1 << 10), INF);
        for(int i = 1; i <= 5; i++) //枚举天数
        {
            for(int S = 0; S < (1 << 10); S++)  //枚举第i天之前车牌位的状态（被限号与否）
            {
                if(dp[i - 1][S] == -1)  //如果不存在前i-1天合法的限号状态
                    continue;
                for(int j = 0; j < (1 << 10); j++) //枚举下一天被限号的车牌位构成的状态
                {
                    if(!(S & j))   //前几天被限号的车牌不能再被限号
                    {
                        int tmp = 0;
                        for(int k = 0; k < 10; k++)
                        {
                            if(j & (1 << k))    //计算被限号的车牌对应的车的数量
                                tmp += cnt[k];
                        }
                        dp[i][S | j] = max(dp[i][S | j], min(dp[i - 1][S], tmp)); //（最大化最小值）计算前i-1天限号状态为S第i天限号状态为j时的最大方案
                    }
                }
            }
        }
        printf("%d\n", n - dp[5][(1 << 10) - 1]);
    }
    return 0;
}
