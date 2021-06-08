/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-08
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

const int MAXN = 100005;

int a[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum ^= a[i];
    }
    if(sum && n % 2 == 0)
        puts("NO");
    else
    {
        puts("YES");
        if(n & 1)
            printf("%d\n", n - 2);  //n - 1
        else
            printf("%d\n", n - 3);  //n - 2
        for(int i = 1; i + 2 <= n; i += 2)
            printf("%d %d %d\n", i, i + 1, i + 2);
        for(int i = 1; i + 1 <= n - 3; i += 2)  //n - 1
            printf("%d %d %d\n", i, i + 1, n);
    }
    return 0;
}
