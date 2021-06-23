/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-22
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

const int MAXN = 55;

int a[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        LL sum1 = 0, sum2 = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if(i & 1)
            {
                sum1 += a[i];
                sum2 += 1;
            }
            else
            {
                sum1 += 1;
                sum2 += a[i];
            }
        }
        if(sum1 > sum2)
        {
            for(int i = 1; i <= n; i++)
            {
                if(i & 1)
                    printf("%d%c", a[i], (i == n ? '\n' : ' '));
                else
                    printf("1%c", (i == n ? '\n' : ' '));
            }
        }
        else
        {
            for(int i = 1; i <= n; i++)
            {
                if(i & 1)
                    printf("1%c", (i == n ? '\n' : ' '));
                else
                    printf("%d%c", a[i], (i == n ? '\n' : ' '));
            }
        }
    }
    return 0;
}
