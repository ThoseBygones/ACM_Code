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
#define MAXN 100005
using namespace std;

LL a[MAXN];
LL b[MAXN];
LL dp1[MAXN];  //dp1[i]表示到第i个数保持不下降总的需要的修改的量
LL dp2[MAXN];  //dp1[i]表示到第i个数保持不上升总的需要的修改的量

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
        b[i]=a[i];
    }
    for(int i=2; i<=n; i++)
    {
        if(a[i-1]>=a[i])
        {
            dp1[i]=dp1[i-1]+(a[i-1]-a[i]+1);
            a[i]=a[i-1]+1;
        }
        else
            dp1[i]=dp1[i-1];
    }
    for(int i=n-1; i>=1; i--)
    {
        if(b[i+1]>=b[i])
        {
            dp2[i]=dp2[i+1]+(b[i+1]-b[i]+1);
            b[i]=b[i+1]+1;
        }
        else
            dp2[i]=dp2[i+1];
    }
    LL ans=LINF;
    for(int i=0; i<=n; i++) //可以单调增或者单调减
    {
        LL sum=dp1[i]+dp2[i+1];
        if(a[i]==b[i+1])  //两数均为峰值
            sum++;
        ans=min(ans,sum);
    }
    printf("%I64d\n",ans);
    return 0;
}
