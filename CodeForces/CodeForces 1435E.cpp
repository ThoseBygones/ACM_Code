/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-04
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
        LL a, b, c, d;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        if(a > b * c)   //迟早能杀死
            puts("-1");
        else
        {
            if(c <= d)
                printf("%lld\n", a);
            else
            {
                LL t = a / (b * d);    //伤害能抵消几个技能冷却回合的回复
                LL ans = a * (t + 1) -  t * (t + 1) / 2 * b * d;    //刚好能够抵消的这几个回合内伤害总量 - 回复总量
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
