/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-04-16
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

const int MAXN = 100005;

int a[MAXN], b[MAXN];
char s[MAXN], c[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s", s);
        for(int i = 1; i <= m; i++)
            scanf("%d", &a[i]);
        scanf("%s", c + 1);
        sort(a + 1, a + 1 + m);
        sort(c + 1, c + 1 + m);
        int len = unique(a + 1, a + 1 + m) - a - 1; //去重，重复修改的位置实际上应该最后改成字典序最小的数字
        for(int i = 1; i <= len; i++)
            s[a[i] - 1] = c[i];
        printf("%s\n", s);
    }
    return 0;
}
