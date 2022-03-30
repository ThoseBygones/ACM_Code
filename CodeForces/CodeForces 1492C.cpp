/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-03-28
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

const int MAXN = 200005;

char s[MAXN], t[MAXN];
int l[MAXN], r[MAXN];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s%s", s, t);
    for(int i = 0, j = 0; i < n && j < m; i++)
    {
        if(s[i] == t[j])
            l[j++] = i;
    }
    for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--)
    {
        if(s[i] == t[j])
            r[j--] = i;
    }
    int ans = 0;
    for(int i = 1; i < m; i++)
        ans = max(ans, r[i] - l[i - 1]);
    printf("%d\n", ans);
    return 0;
}
