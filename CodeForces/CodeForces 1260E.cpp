/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-11
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 位运算 + STL Multiset
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
#define MAXN 300005

multiset<int> s;
int a[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    LL ans = 0;
    for(int i = n; ~a[i]; i--)
    {
        s.insert(a[i]);
        if(!(i & (i - 1)))  //此时对手太多，根据淘汰赛规则已贿赂的对手无法解决所有未贿赂的对手
        {
            ans += *s.begin();
            s.erase(s.begin());
        }
    }
    printf("%lld\n", ans);
    return 0;
}
