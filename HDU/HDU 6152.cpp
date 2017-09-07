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
#define MAXN 3005

using namespace std;

bool a[MAXN][MAXN];
int n;

bool judge()
{
    if(n>=6)
        return true;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            for(int k=j+1; k<=n; k++)
            {
                int cnt=a[i][j]+a[i][k]+a[j][k];
                if(cnt==0 || cnt==3)
                    return true;
            }
        }
    }
    return false;
}

int main(void)
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        scanf("%d",&n);
        clr(a,0);
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                scanf("%d",&a[i][j]);
                a[j][i]=a[i][j];
            }
        }
        puts(judge()?"Bad Team!":"Great Team!");
    }
    return 0;
}
