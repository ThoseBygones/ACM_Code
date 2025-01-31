/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-01-23
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

vector<int> a, b, c;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        a.clear();
        b.clear();
        c.clear();
        for(int i = 0; i < n; i++)
        {
            int x;
            char s[3];
            scanf("%d%s", &x, s);
            if(strcmp(s, "11") == 0)
                a.PB(x);
            else if(strcmp(s, "10") == 0)
                b.PB(x);
            else if(strcmp(s, "01") == 0)
                c.PB(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int ans = INF;
        if(a.size())
        {
            ans = min(ans, a[0]);
            if(b.size() && c.size())
                ans = min(ans, b[0] + c[0]);
        }
        else if(b.size() && c.size())
            ans = b[0] + c[0];
        else
            ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
