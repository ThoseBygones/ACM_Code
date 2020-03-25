/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-23
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 枚举 / 扩展欧几里得
 ********************************************************************************
 *  Algo-Description:
 * > 解出方程组：1. x + y + z = n, 2. x * w + y * d = p 的解。
 * > x + y + z = n 可转化为 x + y <= n；
 * > x * w + y * d = p,
 * > => y * d = p - x * w,
 * > => (y - k * w) * d = p - x * w - k * w, 其中 y - k * w < w，即 y - k * w = y % w;
 * > => y - k * w = (p - (x + k) * w) / d,
 * > 由于 w, d <= 1e5，故此时 y - k * w <= 1e5（由于 y - k * w = y % w）
 * > 故枚举 y - k * w 的值，根据 y = (p - (y - k * w) * d) / w，求出y，即可求出一组解(x, y, z)。
 * > 特别地，由于 w > d，且 d 可能等于为 1，为避免求解时出现 % 1 的情况，故不枚举 x - k * w。
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

int main()
{
    LL n, p, w, d;
    scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
    for(LL i = 0; i < w; i++)  //枚举 y - k * w（即 y % w）的值
    {
        if(p >= i * d && (p - i * d) % w == 0)    //判断y是不是整数
        {
            LL x = (p - i * d) / w;
            LL y = i;
            LL z = n - x - y;
            if(x + y <= n)
            {
                printf("%lld %lld %lld\n", x, y, z);
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}
