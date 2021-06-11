/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-11
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

const int MAXN = 100005;

char s[MAXN];
int a[MAXN], dp[MAXN];  //dp[i]表示以i为起点k为步长到终点的过程中需要添加几个格子

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, p, k;
        scanf("%d%d%d", &n, &p, &k);
        for(int i = 0; i < k; i++)
            dp[i] = 0;
        scanf("%s", s + 1);
        for(int i = 1; i <= n; i++)
        {
            a[i] = s[i] - '0';
            if(i >= p)
                dp[i % k] += (a[i] ^ 1);
        }
        int x, y;
        scanf("%d%d", &x, &y);
        LL ans = LINF;
        for(int i = p; i <= n; i++) //枚举起点
        {
            LL sum = 1LL * dp[i % k] * x + 1LL * (i - p) * y;
            dp[i % k] -= (a[i] ^ 1);    //下一次从(i + k)位置开始少考虑一个格子的情况
            ans = min(sum, ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
