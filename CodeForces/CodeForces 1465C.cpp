/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 并查集 / dfs 找环
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

const int MAXN = 100005;

int fa[MAXN];

int findSet(int x)
{
    if(x != fa[x])
        return fa[x] = findSet(fa[x]);
    return fa[x];
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            fa[i] = i;
        int ans = 0;
        while(m--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if(x == y)
                continue;
            int fx = findSet(x);
            int fy = findSet(y);
            if(fx != fy)
            {
                fa[fx] = fy;
                ans++;
            }
            else
                ans += 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
