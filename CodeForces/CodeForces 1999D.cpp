/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-24
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

const int MAXN = 200005;

char s1[MAXN], s2[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s1);
        scanf("%s", s2);
        int p = 0, q = 0;
        int lens = strlen(s1), lent = strlen(s2);
        while(p < lens)
        {
            //printf("%d vs. %d\n", p, q);
            if(s1[p] == s2[q])
                p++, q++;
            else if(s1[p] == '?')
                s1[p++] = s2[q++];
            else
                p++;
            if(q >= lent)
                break;
        }
        while(p < lens)
        {
            if(s1[p] == '?')
                s1[p] = 'a';
            p++;
        }
        if(q >= lent)
        {
            puts("YES");
            printf("%s\n", s1);
        }
        else
            puts("NO");
    }
    return 0;
}
