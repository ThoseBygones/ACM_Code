/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp + 因子线性筛法
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

const int MAXN = 200000;

int cnt[MAXN + 5];
int dp[MAXN + 5];   //dp[i]表示以i为最大的数，能构成的符合要求的集合的最大大小

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i <= MAXN; i++)
        {
            cnt[i] = 0;
            dp[i] = 0;
        }
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            cnt[x]++;
        }
        for(int i = 1; i <= MAXN; i++)
        {
            dp[i] += cnt[i];
            for(int j = i * 2; j <= MAXN; j += i)
                dp[j] = max(dp[i], dp[j]);
        }
        int ans = 0;
        for(int i = 1; i <= MAXN; i++)
            ans = max(ans, dp[i]);
        printf("%d\n", n - ans);
    }
    return 0;
}
