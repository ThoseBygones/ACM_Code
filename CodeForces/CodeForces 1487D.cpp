/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-03-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 数学规律
 ********************************************************************************
 *  Algo-Description:
 * > a ^ 2 + b ^ 2 = c ^ 2, c = a ^ 2 - b => b + c + b ^ 2 = c ^ 2
 *   => b * (b + 1) = c * (c - 1)
 * > 由于 b <= c, 所以 c = b + 1
 *   => b = (a ^ 2 - 1) / 2, c = (a ^ 2 + 1) / 2
 * > 所以，a ^ 2 + ((a ^ 2 - 1) / 2) ^ 2 = ((a ^ 2 + 1) / 2) ^ 2
 *   => (a ^ 2 + 1) / 2 <= n => 1 < a <= sqrt(2 * n - 1)
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
        int n;
        scanf("%d", &n);
        int ub = int(sqrt(2 * n - 1));
        if(ub & 1)  //upperbound is odd
            printf("%d\n", ub >> 1);
        else    //upperbound is even
            printf("%d\n", (ub >> 1) - 1);
    }
    return 0;
}

/*
n = 5, a <= 3, cnt = 1
n = 7, a <= sqrt(13), cnt = 1
n = 9, a <= sqrt(17), cnt = 2
n = 11, a <= sqrt(21), cnt = 2
n = 13, a <= 5, cnt = 3

n = 6, a <= sqrt(11), cnt = 1
n = 8, a <= sqrt(15), cnt = 1
n = 10, a <= sqrt(19), cnt = 2
*/
