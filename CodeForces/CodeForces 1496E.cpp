/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-15
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 规律
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

const int MAXN = 505;

char s[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%s", s[i] + 1);
        for(int j = 1 + (m % 3 == 0); j <= m; j += 3)
        {
            for(int i = 1; i <= n; i++)
                s[i][j] = 'X';
            if(j + 2 > m)
                break;
            int r = 2;
            if(n == 1 || (s[2][j + 1] != 'X' && s[2][j + 2] != 'X'))    //第二列没有连任何一个，所以应该连第一列
                r = 1;
            s[r][j + 1] = s[r][j + 2] = 'X';
        }
        for(int i = 1; i <= n; i++)
            printf("%s\n", s[i] + 1);
    }
    return 0;
}
