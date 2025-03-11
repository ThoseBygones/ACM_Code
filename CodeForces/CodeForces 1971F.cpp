/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-06
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 枚举 + 二分
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

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL n;
        scanf("%lld", &n);
        LL ans = 0;
        for(LL x = 1; x <= n; x++) //枚举x坐标
        {
            LL cnt1 = 0, cnt2 = 0;
            LL l = 0, r = n;   //二分横坐标为x的竖轴方向上符合要求的点的数量（坐标轴上的点先不统计）
            while(l <= r)
            {
                LL mid = (l + r) >> 1;
                if(sqr(x) + sqr(mid) < sqr(n))  //x ^ 2 + y ^ 2 < r ^ 2
                {
                    cnt1 = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            l = 0, r = n;   //二分横坐标为x的竖轴方向上符合要求的点的数量（坐标轴上的点先不统计）
            while(l <= r)
            {
                LL mid = (l + r) >> 1;
                if(sqr(x) + sqr(mid) < sqr(n + 1))  //x ^ 2 + y ^ 2 < (r + 1) ^ 2
                {
                    cnt2 = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            ans += cnt2 - cnt1; //类似前缀和处理，得到符合 r ^ 2 <= x ^ 2 + y ^ 2 < (r + 1) ^ 2 的点
        }
        printf("%lld\n", 4 * ans + 4);    //4个坐标轴上的点 (r, 0), (-r, 0), (0, r), (0, -r)
    }
    return 0;
}
