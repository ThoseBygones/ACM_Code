/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-21
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

const int MAXN = 200010;

LL b[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n + 2; i++)
            scanf("%lld", &b[i]);
        sort(b, b + 2 + n);
        LL sum = 0;
        for(int i = 0; i <= n; i++)
            sum += b[i];
        int ans = -1;
        for(int i = 0; i <= n; i++)
        {
            if(sum - b[i] == b[i] || sum - b[i] == b[n + 1])
            {
                ans = i;
                break;
            }
        }
        if(~ans)
        {
            vector<LL> a;
            for(int i = 0; i <= n; i++)
            {
                if(i != ans)
                    a.PB(b[i]);
            }
            for(int i = 0; i < a.size(); i++)
                printf("%lld%c", a[i], (i == a.size() - 1 ? '\n' : ' '));
        }
        else
            puts("-1");
    }
    return 0;
}
