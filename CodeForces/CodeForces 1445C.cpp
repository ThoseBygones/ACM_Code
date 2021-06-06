/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-06
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm:
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

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL p, q;
        scanf("%lld%lld", &p, &q);
        if(p % q)   //p不能整除q
            printf("%lld\n", p);
        else    //p可以整除q
        {
            LL ans = 0;
            for(int i = 1; i * i <= q; i++)
            {
                LL tmp = p;
                if(q % i)
                    continue;
                if(i != 1)  //q本身就是个质因数
                {
                    while(tmp % q == 0)
                        tmp /= i;
                    ans = max(ans, tmp);
                }
                tmp = p;
                while(tmp % q == 0)
                    tmp /= (q / i);
                ans = max(ans, tmp);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
