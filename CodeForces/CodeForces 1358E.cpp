/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-31
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 前缀和 + 尺取法（滑动窗口）
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

const int MAXN = 500005;

LL a[MAXN], sum[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= (n + 1) / 2; i++)
        scanf("%lld", &a[i]);
    LL x;
    scanf("%lld", &x);
    for(int i = (n + 1) / 2 + 1; i <= n; i++)
        a[i] = x;
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    if(x > 0)   //后面 n / 2 个数都是正数
    {
        if(sum[n] > 0)    //前缀和大于0，k = n
            printf("%d\n", n);
        else    //前缀和小于等于0，肯定不存在这样的k
            puts("-1");
    }
    else    //后面 n / 2 个数是负数
    {
        int r = n;
        for(int l = n / 2; l >= 0; l--) //枚举连续区间的起点
        {
            if(sum[r] - sum[l] > 0) //窗口向左滑动
                r--;
            else    //区间右端点回复到n
                r = n;
        }
        if(r != n)
            printf("%d\n", r + 1);
        else
            puts("-1");
    }
    return 0;
}
