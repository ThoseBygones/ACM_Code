/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-06-08
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp + 前缀和
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

const int MAXN = 1000005;

char s[MAXN];
int pre[MAXN];  //前缀和，记录字符'1'的个数
int dp[MAXN];   //dp[i]表示第i位字符为'1'时，前i位字符中需要修改字符个数的最小值

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        for(int i = 1; i <= n; i++)
        {
            pre[i] = pre[i-1] + (s[i] == '1');
            dp[i] = pre[i-1] + (s[i] == '0');
        }
        for(int i = k + 1; i <= n; i++)
            dp[i] = min(dp[i], dp[i-k] + pre[i-1] - pre[i-k] + (s[i] == '0'));    //从第i-k个字符到第i-1个字符中，所有1修改为0
        int ans = INF;
        for(int i = 0; i <= n; i++)
            ans = min(ans, dp[i] + pre[n] - pre[i]);    //只处理前i个字符，后面的全部归零
        printf("%d\n", ans);
    }
    return 0;
}
