/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-20
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 规律 + 数学
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

struct Node
{
    int r, c, d;
    Node() {}
    Node(int r, int c, int d) : r(r), c(c), d(d) {}
    bool operator < (const Node &nd) const
    {
        return r < nd.r;
    }
} a[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i].r);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i].c);
            a[i].d = a[i].r - a[i].c;
        }
        sort(a + 1, a + 1 + n);
        a[0] = Node(1, 1, 0);
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i].r == 1 && a[i].c == 1)
                continue;
            if(a[i].d == a[i - 1].d)
            {
                if(a[i].d % 2 == 0)
                    ans += a[i].r - a[i - 1].r;
            }
            else
            {
                if(a[i].d & 1)
                    ans += (a[i].d - a[i - 1].d) / 2;
                else
                    ans += (a[i].d - a[i - 1].d + 1) / 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
