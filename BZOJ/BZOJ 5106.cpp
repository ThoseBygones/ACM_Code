//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
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
#define MAXN 200005
using namespace std;

LL h[MAXN];
LL a[MAXN];
LL n,S,L;

LL biSearch(LL val)
{
    LL sum=0;
    for(int i=0; i<n; i++)
    {
        if(h[i]+a[i]*val>=L)
            sum+=h[i]+a[i]*val;
        if(sum>=S)
            return true;
    }
    return false;
}

int main()
{
    LL maxh=-1;
    scanf("%lld%lld%lld",&n,&S,&L);
    for(int i=0; i<n; i++)
        scanf("%lld",&h[i]);
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
        maxh=max(maxh,a[i]);
    }
    LL l=0LL,r=max(S,L)/maxh;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(biSearch(mid))
            r=mid-1;
        else
            l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
