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

int a[MAXN];
vector <int> ans[MAXN];

int biSearch(int val,int sz)
{
    int l=0,r=sz;
    while(l<r)
    {
        int mid=(l+r)>>1;
        //cout << ans[mid].back() << endl;
        if(ans[mid].back()<=val)
            r=mid;
        else
            l=mid+1;
    }
    if(r==sz)
        return -1;
    return r;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        if(cnt==0)
        {
            ans[cnt++].PB(a[i]);
            continue;
        }
        int p=biSearch(a[i],cnt);
        if(p==-1)
            ans[cnt++].PB(a[i]);
        else
            ans[p].PB(a[i]);
    }
    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            if(j==0)
                printf("%d",ans[i][j]);
            else
                printf(" %d",ans[i][j]);
        }
        puts("");
    }
    return 0;
}
