/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-12
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

multiset<int> ms;
int a[MAXN], b[MAXN], d[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ms.clear();
        int n, m;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
            if(a[i] != b[i])
                ms.insert(b[i]);
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d", &d[i]);
            auto it = ms.find(d[i]);
            if(it != ms.end())
                ms.erase(it);
        }
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            if(b[i] == d[m])
            {
                flag = true;
                break;
            }
        }
        if(flag && ms.empty())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
