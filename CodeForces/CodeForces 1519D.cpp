/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-09-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 枚举
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

LL a[MAXN], b[MAXN];
LL d[MAXN][MAXN];   //d[l][r]表示对区间[l,r]中的元素进行翻转后乘积和的差值

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    LL sum = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &b[i]);
        sum += a[i] * b[i];
    }
    LL ans = 0;
    for(int l = n; l; l--)  //枚举翻转区间的左端点
    {
        for(int r = l + 1; r <= n; r++) //枚举翻转区间的右端点
        {
            d[l][r] = d[l + 1][r - 1] - a[l] * b[l] - a[r] * b[r] + a[l] * b[r] + a[r] * b[l];
            ans = max(ans, d[l][r]);
        }
    }
    printf("%lld\n", sum + ans);
    return 0;
}
