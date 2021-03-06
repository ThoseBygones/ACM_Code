/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:2019-01-08
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
#define MAXN 1005

int a[MAXN];

int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int ans = 0;
    int last = 0;
    int p = 0;
    while(last < n)
    {
        p = 0;
        for(int i=n; i>max(0,last-r+1); i--)
        {
            if(a[i] && i - r <= last)
            {
                p = i;
                break;
            }
        }
        if(!p)
        {
            puts("-1");
            return 0;
        }
        ans++;
        last = p + r - 1;
    }
    printf("%d\n",ans);
    return 0;
}
