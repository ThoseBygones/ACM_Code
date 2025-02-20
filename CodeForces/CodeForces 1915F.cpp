/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-02-20
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 归并排序/树状数组+离散化求逆序对
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

PII a[MAXN], tmp[MAXN];

LL mergeSort(int l, int r)
{
    if(l >= r)
        return 0;
    int mid = (l + r) >> 1;
    int i = l, j = mid + 1, p = l;
    LL ans = mergeSort(l, mid) + mergeSort(mid + 1, r);
    while(i <= mid && j <= r)
    {
        if(a[i].second > a[j].second)
        {
            tmp[p++] = a[j++];
            ans += mid - i + 1;
        }
        else
            tmp[p++] = a[i++];
    }
    while(i <= mid)
        tmp[p++] = a[i++];
    while(j <= r)
        tmp[p++] = a[j++];
    for(int k = l; k <= r; k++)
        a[k] = tmp[k];
    return ans;
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
        {
            int x, y;
            scanf("%d%d", &x, &y);
            a[i] = MP(x, y);
        }
        sort(a + 1, a + 1 + n);
        LL ans = mergeSort(1, n);
        printf("%lld\n", ans);
    }
    return 0;
}
