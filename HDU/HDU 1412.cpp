/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-05
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: STL Set
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

set<int> s;

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        s.clear();
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            s.insert(x);
        }
        for(int i = 0; i < m; i++)
        {
            int x;
            scanf("%d", &x);
            s.insert(x);
        }
        bool flag = true;
        for(auto &x: s)
        {
            if(flag)
            {
                flag = false;
                printf("%d", x);
            }
            else
                printf(" %d", x);
        }
        puts("");
    }
    return 0;
}
