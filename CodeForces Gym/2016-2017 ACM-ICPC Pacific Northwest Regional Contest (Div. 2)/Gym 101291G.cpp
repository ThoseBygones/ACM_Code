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
#define MAXN 55
using namespace std;

struct Apple
{
    int x,y;
} a[MAXN*MAXN];

char mp[MAXN][MAXN];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        scanf("%s",mp[i]);
        for(int j=0; j<m; j++)
        {
            if(mp[i][j]=='o')
            {
                cnt++;
                a[cnt].x=i;
                a[cnt].y=j;
            }
        }
    }
    for(int i=cnt; i; i--)
    {
        while(a[i].x+1<n && mp[a[i].x+1][a[i].y]=='.')
        {
            int nx=a[i].x+1;
            int ny=a[i].y;
            swap(mp[a[i].x][a[i].y],mp[nx][ny]);
            a[i].x=nx;
            a[i].y=ny;
        }
    }
    for(int i=0; i<n; i++)
        printf("%s\n",mp[i]);
    return 0;
}
