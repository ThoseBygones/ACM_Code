/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-21
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 分治 + 前缀和 + 二分
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

map<LL, bool> mp;
int a[MAXN];
LL sum[MAXN];

void solve(int l, int r)
{
    if(l <= r)
    {
        int val = (a[l] + a[r]) >> 1;
        if(a[l] > val || a[r] <= val)   //val是左区间的右边界，a[r] == val时无法分割成两个区间
            return ;
        int pos = upper_bound(a + l, a + r, val) - a - 1;
        mp[sum[pos] - sum[l - 1]] = true;
        mp[sum[r] - sum[pos]] = true;
        solve(l, pos);
        solve(pos + 1, r);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        mp.clear();
        for(int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i];
        mp[sum[n]] = true;
        solve(1, n);
        while(q--)
        {
            LL x;
            scanf("%lld", &x);
            if(mp[x])
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
