/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-16
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

const int MAXN = 100000;

int fac[MAXN + 5];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL n;
        scanf("%lld", &n);
        for(int i = 1; i <= MAXN; i++)
            fac[i] = 0;
        LL val = 0, tmp = n;
        int cnt = 0;
        for(LL i = 2; i * i <= tmp; i++)
        {
            if(tmp % i == 0)
            {
                while(tmp % i == 0)
                {
                    fac[i]++;
                    tmp /= i;
                }
                if(fac[i] > cnt)
                {
                    cnt = fac[i];
                    val = i;
                }
            }
        }
        if(tmp > 1)   //自己就是质数
        {
            if(cnt == 0)
            {
                cnt = 1;
                val = tmp;
            }
        }
        printf("%d\n", cnt);
        for(int i = 1; i < cnt; i++)
        {
            printf("%lld ", val);
            n /= val;
        }
        printf("%lld\n", n);
    }
    return 0;
}
