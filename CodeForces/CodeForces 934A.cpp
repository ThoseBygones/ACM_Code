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
#define MAXN 55

LL a[MAXN],b[MAXN];

int main()
{
    LL n,m;
    scanf("%I64d%I64d",&n,&m);
    for(LL i=0; i<n; i++)
        scanf("%I64d",&a[i]);
    for(LL i=0; i<m; i++)
        scanf("%I64d",&b[i]);
    LL Max=-2e18;
    LL idx=0;
    for(LL i=0; i<n; i++)
    {
        for(LL j=0; j<m; j++)
        {
            if(Max<a[i]*b[j])
            {
                Max=a[i]*b[j];
                idx=i;
            }
        }
    }
    Max=-2e18;
    for(LL i=0; i<n; i++)
    {
        if(i==idx)
            continue;
        for(LL j=0; j<m; j++)
            Max=max(Max,a[i]*b[j]);
    }
    printf("%I64d\n",Max);
    return 0;
}
