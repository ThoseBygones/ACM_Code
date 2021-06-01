/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-01
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

const int MAXN = 205;

char g[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%s", g[i] + 1);
        int s1 = g[1][2] - '0', s2 = g[2][1] - '0';
        int f1 = g[n - 1][n] - '0', f2 = g[n][n - 1] - '0';
        if(s1 == s2 && f1 == f2)
        {
            if(s1 != f1)
                puts("0");
            else
            {
                puts("2");
                puts("1 2");
                puts("2 1");
            }
        }
        else
        {
            if(s1 != s2 && f1 != f2)
            {
                puts("2");
                if(s1 != f1)
                    printf("2 1\n%d %d\n", n, n - 1);
                else
                    printf("2 1\n%d %d\n", n - 1, n);
            }
            else
            {
                puts("1");
                if(s1 != s2)
                {
                    if(s1 != f1)
                        puts("2 1");
                    else
                        puts("1 2");
                }
                else if(f1 != f2)
                {
                    if(s1 != f1)
                        printf("%d %d\n", n, n - 1);
                    else
                        printf("%d %d\n", n - 1, n);
                }
            }
        }
    }
    return 0;
}
