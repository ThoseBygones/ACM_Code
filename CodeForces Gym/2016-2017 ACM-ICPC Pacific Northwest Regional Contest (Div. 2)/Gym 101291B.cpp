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
#define MAXN 20
using namespace std;

set <int> s;
int b[MAXN];
int p[MAXN];
int n,m;

void dfs(int l,int r,int cnt)
{
    if(cnt==m)
    {
        if(l==r)
        {
            for(int i=0; i<n; i++)
                s.insert(b[i]+l+r);
        }
        return ;
    }
    dfs(l,r,cnt+1);
    dfs(l+p[cnt],r,cnt+1);
    dfs(l,r+p[cnt],cnt+1);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%d",&b[i]);
    for(int i=0; i<m; i++)
        scanf("%d",&p[i]);
    dfs(0,0,0);
    for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
        printf("%d\n",*it);
    return 0;
}
