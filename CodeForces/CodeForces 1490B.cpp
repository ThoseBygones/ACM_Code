/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-19
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

int c[5];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        c[0] = c[1] = c[2] = 0;
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            c[x % 3]++;
        }
        //printf("%d %d %d\n", c[0], c[1], c[2]);
        int ans = 0;
        for(int i = 0; i < 6; i++)
        {
            if(c[i % 3] > n / 3)
            {
                c[(i + 1) % 3] += (c[i % 3] - n / 3);
                ans += (c[i % 3] - n / 3);
                c[i % 3] = n / 3;
            }
            //printf("%d %d %d\n", c[0], c[1], c[2]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
