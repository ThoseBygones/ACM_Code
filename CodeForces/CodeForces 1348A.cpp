/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-25
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

LL p2[35];

void init()
{
    p2[0] = 1;
    for(int i = 1; i <= 30; i++)
        p2[i] = p2[i - 1] * 2;
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        //LL a = p2[n] * 2 - p2[1], b = p2[n - 1] * 2 - p2[n - n / 2];
        //printf("%lld %lld\n", a, b);
        LL sum = p2[n] * 2 - p2[1] - 2 * (p2[n - 1] * 2 - p2[n - n / 2]);
        printf("%lld\n", sum);
    }
    return 0;
}
