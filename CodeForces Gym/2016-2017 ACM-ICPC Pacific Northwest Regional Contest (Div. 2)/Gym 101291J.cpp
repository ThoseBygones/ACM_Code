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

using namespace std;

vector <PLL> a,b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    LL k;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        LL x,m;
        cin >> x >> m;
        if(x>0)
            a.PB(MP(x,m));
        else
            b.PB(MP(-x,m));
    }
    sort(a.begin(),a.end(),greater<PII>());
    sort(b.begin(),b.end(),greater<PII>());
    //for(int i=0; i<a.size(); i++)
    //    printf("%d ",a[i].first);
    LL sum=0;
    int cnt=0;
    while(cnt<a.size())
    {
        if(a[cnt].second>k)
        {
            sum+=(a[cnt].second/k)*a[cnt].first;
            a[cnt].second%=k;
            if(a[cnt].second==0)
                cnt++;
        }
        else
        {
            LL temp=k;
            sum+=a[cnt].first;
            while(temp-a[cnt].second>0 && cnt<a.size())
            {
                temp-=a[cnt].second;
                cnt++;
            }
            if(cnt<a.size())
                a[cnt].second-=temp;
        }
    }
    cnt=0;
    while(cnt<b.size())
    {
        if(b[cnt].second>k)
        {
            sum+=(b[cnt].second/k)*b[cnt].first;
            b[cnt].second%=k;
            if(b[cnt].second==0)
                cnt++;
        }
        else
        {
            LL temp=k;
            sum+=b[cnt].first;
            while(temp-b[cnt].second>0 && cnt<b.size())
            {
                temp-=b[cnt].second;
                cnt++;
            }
            if(cnt<b.size())
                b[cnt].second-=temp;
        }
    }
    cout << sum*2 << endl;
    return 0;
}
