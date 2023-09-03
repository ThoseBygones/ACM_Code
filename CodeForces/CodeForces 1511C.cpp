/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ:
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

const int MAXN = 3000005;

int a[55];
int ans[MAXN];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if(!a[x])
            a[x] = i;
    }
    for(int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        ans[i] = a[x];
        for(int j = 1; j <= 50; j++)
        {
            if(j != x && a[j] && a[j] < a[x])
                a[j]++;
        }
        a[x] = 1;
    }
    for(int i = 0; i < q; i++)
        printf("%d%c", ans[i], (i == q - 1 ? '\n' : ' '));
    return 0;
}
