/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-31
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 前缀和 + 尺取法
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

LL a[MAXN << 1], pre[MAXN << 1], sum[MAXN << 1];

int main()
{
    int n;
    LL x;
    scanf("%d%lld", &n, &x);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
        sum[i + n] = sum[i] = (1 + a[i]) * a[i] / 2;
    }
    for(int i = 1; i <= 2 * n; i++)
        pre[i] = pre[i - 1] + a[i];
    LL ans = 0, tmp = 0;
    for(int i = 2 * n, j = i; i > n; i--)  //枚举终点
    {
        while(j > 0 && pre[i] - pre[j] < x)
            tmp += sum[j--];
        ans = max(ans, tmp - (1 + pre[i] - pre[j] - x) * (pre[i] - pre[j] - x) / 2);
        tmp -= sum[i];
    }
    printf("%lld\n", ans);
    return 0;
}
