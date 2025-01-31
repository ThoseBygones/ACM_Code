/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-01-27
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

const int MAXN = 205;

int deg[MAXN], cnt[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; i++)
        {
            deg[i] = 0;
            cnt[i] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            deg[u]++, deg[v]++;
        }
        for(int i = 1; i <= n; i++)
            cnt[deg[i]]++;
        int x = 0, y = 0;
        for(int i = 2; i <= n; i++)
        {
            if(cnt[i] > 1)
                y = i;
            else if(cnt[i] == 1)
                x = i;
        }
        if(!x)
            x = y;
        printf("%d %d\n", x, y - 1);
    }
    return 0;
}
