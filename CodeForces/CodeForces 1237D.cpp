/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-30
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: STL Multiset / 单调队列
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
#define MAXN 100005

int a[MAXN*3], ans[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    int Max = 0, Min = INF;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i+2*n] = a[i+n] = a[i];
        Max = max(Max, a[i]);
        Min = min(Min, a[i]);
    }
    if(Max <= Min * 2)
    {
        for(int i = 1; i <= n; i++)
            ans[i] = -1;
    }
    else
    {
        multiset<int> ms;
        int pos = 0;
        for(int i = 1; i <= n; i++)
        {
            while(pos <= 3 * n)
            {
                if(ms.empty() || *ms.rbegin() <= a[pos] * 2)
                    ms.insert(a[pos++]);
                else
                    break;
            }
            ans[i] = pos - i;
            ms.erase(ms.lower_bound(a[i]));
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d%c", ans[i], (i == n ? '\n' : ' '));
    return 0;
}
