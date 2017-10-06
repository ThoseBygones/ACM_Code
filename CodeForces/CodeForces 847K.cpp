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
#define MAXN 610
using namespace std;

map <string,int> mp;
map <PII,int> t;
vector <int> rec;
int n,a,b,k,f;

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> a >> b >> k >> f;
    int id=0;
    int pre=-1;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        string st,ed;
        cin >> st >> ed;
        if(!mp[st])
            mp[st]=++id;
        if(!mp[ed])
            mp[ed]=++id;
        int cost=(mp[st]==pre?b:a);
        ans+=cost;
        pre=mp[ed];
        t[MP(min(mp[st],mp[ed]),max(mp[st],mp[ed]))]+=cost;  //固定起点和终点，如果需要返程则价格双倍（后面在考虑替换成通票）
    }
    for(map<PII,int>::iterator it=t.begin(); it!=t.end(); it++)
        rec.PB(it->second);
    sort(rec.begin(),rec.end(),cmp);
    for(int i=0; i<k; i++) //最多买k张通票
    {
        //cout << rec[i] << endl;
        if(rec[i]<=f)
            break;
        else
            ans-=(rec[i]-f);    //如果买通票更划算则把最贵的几张单程票换成通票
    }
    cout << ans << endl;
	return 0;
}
