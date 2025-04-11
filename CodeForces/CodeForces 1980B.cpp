/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-12
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

int a[105];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int x = a[m];
        //printf("x: %d\n", x);
        sort(a + 1, a + 1 + n, greater<int>());
        if(a[k] < x)
            puts("YES");
        else if(a[k] > x)
            puts("NO");
        else
        {
            if(k != n && a[k + 1] == x)
                puts("MAYBE");
            else
                puts("YES");
        }
    }
    return 0;
}
