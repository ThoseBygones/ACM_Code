/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-14
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

int a[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if(k == 0)
        {
            printf("%d\n", n);
            continue;
        }
        sort(a + 1, a + 1 + n);
        if(a[n] == n - 1)   //mex(a[]) > max(a[])
        {
            printf("%d\n", n + k);
            continue;
        }
        int mex = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] != i - 1)
            {
                mex = i - 1;
                break;
            }
        }
        int tmp = (a[n] + mex + 1) / 2;
        if(tmp == *lower_bound(a + 1, a + 1 + n, tmp))
            printf("%d\n", n);
        else
            printf("%d\n", n + 1);
    }
    return 0;
}
