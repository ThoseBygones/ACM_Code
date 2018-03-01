/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-28
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 *  > f(x) == q(x) * (x + k) + p 联立（合并同类项）得：
 *  > a[i] = { k * b[0] + p, i == 0;
 *           { b[i-1] + k * b[i], 0 < i < d;
 *           { b[d-1], i == d.
 *  > 得到：
 *  > b[i] = { (a[0] - p) / k, i == 0;
 *           { (a[i] - b[i-1]) / k, 0 < i < d.
 *  > 由于 0 <= a[i] < k，因此：
 *  > b[i] = { ceil(- p / k), i == 0;
 *           { ceil(- b[i-1] / k), 0 < i < d.
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 70

LL a[MAXN],b[MAXN];

LL ceilDiv(LL x,LL y)
{
    if(x % y && x > 0)
        return x / y + 1;
    return x / y;
}

int main()
{
    LL p,k;
    scanf("%I64d%I64d",&p,&k);
    b[0] = (ceilDiv(-p,k));
    a[0] = (k * b[0] + p);
    int d = 1;
    for(int i=1; i<MAXN; i++)
    {
        b[i] = ceilDiv(-b[i-1],k);
        a[i] = b[i-1] + k * b[i];
        if(a[i])
            d = i + 1;
    }
    printf("%d\n",d);
    for(int i=0; i<d; i++)
    {
        if(i)
            printf(" %d",a[i]);
        else
            printf("%d",a[i]);
    }
    puts("");
    return 0;
}
