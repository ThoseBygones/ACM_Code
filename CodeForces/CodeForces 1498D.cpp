/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-10-24
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

const int MAXN = 100000;

bool dp[205][MAXN + 5];  //dp[i][j]表示前i次操作能否凑成j
int ans[MAXN + 5];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(ans, -1, sizeof(ans));
    dp[0][0] = true;
    for(int i = 1; i <= n; i++)
    {
        int t, y;
        LL x;
        scanf("%d%lld%d", &t, &x, &y);
        for(int j = 0; j <= m; j++)
        {
            dp[i][j] |= dp[i - 1][j];   //前i-1次能达到的状态，前i次也能达到
            if(!dp[i - 1][j])
                continue;
            LL val = j;
            for(int k = 1; k <= y; k++)
            {
                if(t == 1)
                    val = val + (x + MAXN - 1) / MAXN;
                else if(t == 2)
                    val = (val * x + MAXN - 1) / MAXN;
                if(val > m || dp[i - 1][val])   //数字范围超过了m或者该状态在上一步操作已经可以达到了
                    break;
                dp[i][val] = true;
                ans[val] = i;
            }
        }
    }
    for(int i = 1; i <= m; i++)
        printf("%d%c", ans[i], (i == m ? '\n' : ' '));
    return 0;
}
