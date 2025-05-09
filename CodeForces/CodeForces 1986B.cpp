/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-04-16
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

template<class T> inline T sqr(T x)
{
    return x * x;
}
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
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                int val = 0;
                bool flag = true;
                if(i > 1)
                {
                    if(a[i][j] <= a[i - 1][j])
                        flag = false;
                    else
                        val = max(val, a[i - 1][j]);
                }
                if(i < n)
                {
                    if(a[i][j] <= a[i + 1][j])
                        flag = false;
                    else
                        val = max(val, a[i + 1][j]);
                }
                if(j > 1)
                {
                    if(a[i][j] <= a[i][j - 1])
                        flag = false;
                    else
                        val = max(val, a[i][j - 1]);
                }
                if(j < m)
                {
                    if(a[i][j] <= a[i][j + 1])
                        flag = false;
                    else
                        val = max(val, a[i][j + 1]);
                }
                if(flag)
                    a[i][j] = val;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                printf("%d%c", a[i][j], j == m ? '\n' : ' ');
        }
    }
    return 0;
}
