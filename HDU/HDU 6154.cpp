//计算几何乱搞+找规律
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
template<class T> inline T sqr(T x) { return x * x; }
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
#define MAXN 90000
using namespace std;

double a[MAXN];

int main(void){
#ifndef ONLINE_JUDGE
	//freopen("/Users/mac/Desktop/data.in","r",stdin);
#endif
    for(int i=0; i<4; i++)
        a[i]=0.0;
    a[4]=2.0;
    a[5]=2.5;
    a[6]=4.0;
    a[7]=5.5;
    for(int i=8; i<MAXN; i+=4)
    {
        a[i]=(double)i*(double)i/8.0;
        a[i+1]=a[i]+(double)(i-2)/4.0;
        a[i+2]=a[i+1]+(double)(i-2)/4.0+1.0;
        a[i+3]=a[i+2]+(double)(i-2)/4.0+1.0;
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",lower_bound(a,a+MAXN,n)-a);
    }
	return 0;
}
