/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-21
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 数学
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 1000005;

bool vis[MAXN];

int main()
{
    LL k, l, r, t, x, y;
    scanf("%lld%lld%lld%lld%lld%lld", &k, &l, &r, &t, &x, &y);
    if(x == y)
    {
        if(k + y <= r || k - x >= l)    //补充水不超过r或喝完一天剩下不少于l，则能永远喝下去
            puts("Yes");
        else
            puts("No");
    }
    else if(x > y)  //喝掉的水比较多
    {
        LL cnt = 0;
        if(k + y <= r)  //在补充水不超过r的情况下先补充水
            k += y;
        if(k - x >= l)  //如果第一天喝完水不少于l
        {
            k -= x;
            cnt += (k - l) / (x - y) + 1;   //计算能够喝几天
        }
        if(cnt >= t)    //可以喝超过t天
            puts("Yes");
        else
            puts("No");
    }
    else    //补充的水比较多
    {
        while(true)
        {
            t -= (k - l) / x;   //先不补充水，喝到再喝要少于l为止
            k -= (k - l) / x * x;
            if(t <= 0)  //这样喝已经超过t天
            {
                puts("Yes");
                break;
            }
            if(vis[(k - l) % x])    //记录剩下 k - l 水的时候这种情况是能够可持续发展的
            {
                puts("Yes");
                break;
            }
            vis[(k - l) % x] = true;
            if(k + y <= r)  //补充水以后不会超过r
                k += y;
            else
            {
                puts("No");
                break;
            }
        }
    }
    return 0;
}
