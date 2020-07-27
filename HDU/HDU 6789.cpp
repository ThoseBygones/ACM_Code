/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 暴力枚举
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

int count_round(int hp, int x)  //计算给定血量hp和攻击力x最多能进行多少轮
{
    if(hp % x)
        return hp / x + 1;
    else
        return hp / x;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int ans = INF;
        for(int i = 0; i <= count_round(1000, max(x, y)); i++)  //枚举left和mid对打的次数
        {
            //left和mid对打i轮后大家剩余的血量
            int hpl1 = 1000 - i * y;
            int hpm1 = 1000 - i * x;
            int hpr1 = 1000;
            for(int j = 0; j <= count_round(1000, max(x, z)); j++)  //枚举left和right对打的次数
            {
                //left和right对打j轮后大家剩余的血量
                int hpl = hpl1 - j * z;
                int hpm = hpm1;
                int hpr = hpr1 - j * x;
                if(hpl > 0 && hpm > 0 && hpr > 0) //如果都还有血量
                {
                    if(count_round(hpm, z) == count_round(hpr, y))  //如果mid和right能够同时对打到结束
                        ans = min(ans, i + j + count_round(hpm, z));
                    else
                        continue;
                }
                else if(hpl <= 0 && hpm > 0 && hpr > 0)  //如果left没有血量
                    ans = min(ans, i + j + min(count_round(hpm, z), count_round(hpr, y)));
                else if(hpm <= 0 && hpl > 0 && hpr > 0) //如果mid没有血量
                    ans = min(ans, i + j + min(count_round(hpl, z), count_round(hpr, x)));
                else if(hpr <= 0 && hpl > 0 && hpm > 0) //如果right没有血量
                    ans = min(ans, i + j + min(count_round(hpl, y), count_round(hpm, x)));
                else
                    ans = min(ans, i + j);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
