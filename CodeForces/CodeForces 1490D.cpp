/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 分治
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

const int MAXN = 105;

int a[MAXN], d[MAXN];

void build(int l, int r, int dep)
{
    if(l > r)
        return ;
    int mid = -1, Max = *max_element(a + l, a + r + 1);
    for(int i = l; i <= r; i++)
    {
        if(a[i] == Max)
        {
            mid = i;
            break;
        }
    }
    d[mid] = dep;
    build(l, mid - 1, dep + 1);
    build(mid + 1, r, dep + 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        build(1, n, 0);
        for(int i = 1; i <= n; i++)
            printf("%d%c", d[i], (i == n ? '\n' : ' '));
    }
    return 0;
}
