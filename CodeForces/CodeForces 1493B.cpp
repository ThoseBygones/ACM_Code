/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-10
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

char s[10];
int h, m;

int reflect(int x)
{
    if(x == 0 || x == 1 || x == 8)
        return x;
    else if(x == 2)
        return 5;
    else if(x == 5)
        return 2;
    else
        return -1;
}

bool check(int hh, int mm)
{
    int h0 = reflect(mm % 10);
    int h1 = reflect(mm / 10);
    int m0 = reflect(hh % 10);
    int m1 = reflect(hh / 10);
    if(h0 == -1 || h1 == -1 || m0 == -1 || m1 == -1)
        return false;
    int newh = h0 * 10 + h1, newm = m0 * 10 + m1;
    return newh < h && newm < m;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%s", &h, &m, s);
        int hh = (s[0] - '0') * 10 + s[1] - '0';
        int mm = (s[3] - '0') * 10 + s[4] - '0';
        while(true)
        {
            if(check(hh, mm))
                break;
            mm++;
            if(mm == m)
            {
                hh = (hh + 1) % h;
                mm = 0;
            }
        }
        printf("%d%d:%d%d\n", hh / 10, hh % 10, mm / 10, mm % 10);
    }
    return 0;
}
