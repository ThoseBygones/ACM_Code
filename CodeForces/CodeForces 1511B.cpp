/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ:
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

int powD[10];

void init()
{
    powD[0] = 1;
    for(int i = 1; i < 10; i++)
        powD[i] = powD[i - 1] * 10;
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        printf("%d %d\n", powD[a - 1] + powD[c - 1], powD[b - 1]);
        //printf("gcd = %d\n", __gcd(powD[a - 1] + powD[c - 1], powD[b - 1]));
    }
    return 0;
}
