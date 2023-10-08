/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-09-23
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

const int MAXN = 105;

int a[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        if(n == 2)
        {
            puts("-1");
            continue;
        }
        int cnt = 1;
        for(int i = 0; i <= 2 * (n - 1); i += 2)
        {
            int x = 1 + i, y = 1;
            while(x >= 1)
            {
                if(x <= n && y <= n)
                    a[x][y] = cnt++;
                x -= 1, y += 1;
            }
        }
        for(int i = 1; i < 2 * (n - 1); i += 2)
        {
            int x = 1 + i, y = 1;
            while(x >= 1)
            {
                if(x <= n && y <= n)
                    a[x][y] = cnt++;
                x -= 1, y += 1;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                printf("%d%c", a[i][j], j == n ? '\n' : ' ');
        }
    }
    return 0;
}