/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-01-27
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

const int MAXN = 1000000;

int a[MAXN + 5];    //属于第几层

void init()
{
    a[1] = 1;
    int k = 1, len = 2;
    while(k <= MAXN)
    {
        for(int i = k + 1; i <= k + len && i <= MAXN; i++)
            a[i] = len;
        k += len;
        len++;
    }
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL n;
        scanf("%lld", &n);
        LL sum = 0;
        LL x = n, len = 1;
        sum += sqr(x);
        while(x > 0)
        {
            LL l = x - a[x], r = x - a[x] + len;
            bool flag = false;
            LL u = l, v = r;
            for(LL i = l; i <= r; i++)
            {
                if(i > 0 && a[x] - a[i] == 1)
                {
                    sum += sqr(i);
                    if(!flag)
                    {
                        u = i;
                        flag = true;
                    }
                    v = i;
                }
            }
            if(!flag)
                break;
            x = u, len = v - u + 1;
            //printf("%lld - %lld\n", u, v);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
