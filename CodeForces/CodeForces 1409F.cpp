/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-07
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

const int MAXN = 205;

char s[MAXN], t[3];
int dp[MAXN][MAXN][MAXN];   //dp[i][j][k]表示前i个字符修改了j个其中有k个字符为t[0]时t为s子串的最大数量

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s %s", s + 1, t);
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++)  //枚举字符
    {
        for(int j = 0; j <= k; j++) //枚举修改次数
        {
            for(int cnt = 0; cnt <= n; cnt++)   //枚举修改成t[0]的数量
            {
                if(~dp[i - 1][j][cnt])  //前一状态存在（合法）
                {
                    /* 第一种dp方法 */
                    //不改变字符s[i]，如果s[i] == t[1]则累加答案
                    dp[i][j][cnt + (s[i] == t[0])] = max(dp[i][j][cnt + (s[i] == t[0])], dp[i - 1][j][cnt] + (s[i] == t[1] ? cnt : 0));
                    if(j < k)   //还可以再修改字符
                    {
                        //s[i]修改为t[0]；若t[0] == t[1]则直接累加结果
                        dp[i][j + (s[i] != t[0])][cnt + 1] = max(dp[i][j + (s[i] != t[0])][cnt + 1], dp[i - 1][j][cnt] + (t[0] == t[1] ? cnt : 0));
                        //修改成t[1]；若t[0] == t[1]则直接累加
                        dp[i][j + (s[i] != t[1])][cnt + (t[0] == t[1])] = max(dp[i][j + (s[i] != t[1])][cnt + (t[0] == t[1])], dp[i - 1][j][cnt] + cnt);
                    }
                    /* 第二种dp方法 */
                    if(s[i] == t[0])    //s[i] == t[0]，要么不改，要么改为t[1]
                    {
                        if(t[0] != t[1])    //t[0] != t[1]，改动有区别
                        {
                            dp[i][j][cnt + 1] = max(dp[i][j][cnt + 1], dp[i - 1][j][cnt]);  //不改
                            dp[i][j + 1][cnt] = max(dp[i][j + 1][cnt], dp[i - 1][j][cnt] + cnt);    //改成t[1]
                        }
                        else    //t[0] == t[1]，改不改都一样
                            dp[i][j][cnt + 1] = max(dp[i][j][cnt + 1], dp[i - 1][j][cnt] + cnt);    //不改
                    }
                    else if(s[i] == t[1])   //s[i] == t[1]，要么不改，要么改为t[0]
                    {
                        if(t[0] != t[1])    //t[0] != t[1]，改动有区别
                        {
                            dp[i][j][cnt] = max(dp[i][j][cnt], dp[i - 1][j][cnt] + cnt);    //不改
                            dp[i][j + 1][cnt + 1] = max(dp[i][j + 1][cnt + 1], dp[i - 1][j][cnt]);    //改成t[0]
                        }
                        else    //t[0] == t[1]，改不改都一样
                            dp[i][j][cnt + 1] = max(dp[i][j][cnt + 1], dp[i - 1][j][cnt] + cnt);    //不改
                    }
                    else    //s[i] != t[0] && s[i] != t[1]，要么不改，要么改为t[0]，要么改为t[1]
                    {
                        dp[i][j][cnt] = max(dp[i][j][cnt], dp[i - 1][j][cnt]);  //不改
                        if(t[0] != t[1])    //t[0] ！= t[1]
                        {
                            dp[i][j + 1][cnt + 1] = max(dp[i][j + 1][cnt + 1], dp[i - 1][j][cnt]);  //改成t[0]
                            dp[i][j + 1][cnt] = max(dp[i][j + 1][cnt], dp[i - 1][j][cnt] + cnt);    //改成t[1]
                        }
                        if(t[0] == t[1])    //t[0] == t[1]
                            dp[i][j + 1][cnt + 1] = max(dp[i][j + 1][cnt + 1], dp[i - 1][j][cnt] + cnt);    //改成t[0]/t[1]
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= k; i++)
    {
        for(int j = 0; j <= n; j++)
            ans = max(ans, dp[n][i][j]);
    }
    printf("%d\n", ans);
    return 0;
}
