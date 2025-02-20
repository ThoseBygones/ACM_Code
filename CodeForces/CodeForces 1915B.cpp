/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-02-13
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

char s[5][5];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int cnta = 0, cntb = 0, cntc = 0;
        for(int i = 0; i < 3; i++)
        {
            scanf("%s", s[i]);
            for(int j = 0; j < 3; j++)
            {
                if(s[i][j] == 'A')
                    cnta++;
                else if(s[i][j] == 'B')
                    cntb++;
                else if(s[i][j] == 'C')
                    cntc++;
            }
        }
        if(cnta != 3)
            puts("A");
        else if(cntb != 3)
            puts("B");
        else if(cntc != 3)
            puts("C");
    }
    return 0;
}
