/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-10
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

const int MAXN = 1005;

char s[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, c0, c1, h;
        scanf("%d%d%d%d", &n, &c0, &c1, &h);
        scanf("%s", s);
        int cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
                cnt0++;
            else
                cnt1++;
        }
        int sum = 0;
        if(c0 > c1 + h) //0换1
            sum = cnt0 * h + n * c1;
        else if(c1 > c0 + h)    //1换0
            sum = cnt1 * h + n * c0;
        else
            sum = cnt0 * c0 + cnt1 * c1;
        printf("%d\n", sum);
    }
    return 0;
}
