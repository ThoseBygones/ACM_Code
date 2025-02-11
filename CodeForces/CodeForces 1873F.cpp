/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:2025-02-09
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 滑动窗口
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

int a[MAXN], h[MAXN];

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
        for(int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        int sum = a[1], ans = 0;
        int l = 1, r = l;
        while(r <= n)
        {
            if(r != 1)
            {
                if(h[r - 1] % h[r])
                {
                    l = r;
                    sum = a[r];
                }
                else
                    sum += a[r];
            }
            while(sum > k)  //窗口大小为 1 时，也需要判断窗口内数值和是否小于 k
            {
                sum -= a[l];
                l++;
            }
            //printf("%d - %d = %d\n", l, r, sum);
            ans = max(ans, r - l + 1);
            r++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
