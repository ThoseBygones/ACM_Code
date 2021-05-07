/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-07
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp + 后缀最大值
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

const int MAXN = 200005;

int x[MAXN];
int dp[MAXN];   //dp[i]表示平台左端点坐标为x_i时，能接到的最多点的数量
int suf[MAXN];  //suf[i]表示第一个平台左端点为x_i时，第二个平台放在其右边能接到的最多点的数量

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++)
            scanf("%d", &x[i]);
        for(int i = 0; i < n; i++)
        {
            int y;
            scanf("%d", &y);
        }
        sort(x, x + n);
        dp[n] = suf[n] = 0;
        int r = 0;
        for(int l = 0; l < n; l++)
        {
            while(r < n && x[r] - x[l] <= k)
                r++;
            dp[l] = r - l;
        }
        for(int l = n; l > 0; l--)
            suf[l - 1] = max(dp[l], suf[l]);
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, dp[i] + suf[i + dp[i] - 1]);
        printf("%d\n", ans);
    }
    return 0;
}
