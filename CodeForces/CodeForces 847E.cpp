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

char s[MAXN];
vector <int> a,p;

int getDis(int l,int r,int val) //先去两者较近再去两者较远的总距离
{
    int x=val-l;
    int y=r-val;
    return 2*min(x,y)+max(x,y);
}

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0; i<n; i++)
    {
        if(s[i]=='*')
            a.PB(i);
        if(s[i]=='P')
            p.PB(i);
    }
    int l=0,r=2*n;  //二分时间（不超过2*n）
    int ans;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        int i,j;
        for(i=0,j=0; i<p.size(); i++)
        {
            int ll=p[i],rr=p[i];    //初始化星号的左右边界
            for(; j<a.size(); j++)
            {
                if(getDis(min(ll,a[j]),max(rr,a[j]),p[i])>mid)  //超过限定时间，换一个Packman来吃
                    break;
                else
                {
                    ll=min(ll,a[j]);
                    rr=max(rr,a[j]);
                }
            }
        }
        if(j<a.size())
            l=mid+1;
        else
        {
            ans=mid;
            r=mid-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
