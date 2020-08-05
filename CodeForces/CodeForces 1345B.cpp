/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-31
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

const int MAXN = 26005;

LL a[MAXN];

void init()
{
    a[1] = 2;
    for(int i = 2; a[i - 1] <= 1000000000LL; i++)
        a[i] = a[i - 1] + (i - 1) + 1LL * i * 2;
    //printf("%d\n", i);
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
        int cnt = 0, pos = 0;
        for(int i = 1; i < MAXN; i++)
        {
            if(a[i] > n)
            {
                pos = i - 1;
                break;
            }
        }
        //printf("pos: %d\n", pos);
        while(pos)
        {
            while(a[pos] <= n)
            {
                n -= a[pos];
                cnt++;
            }
            pos--;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
