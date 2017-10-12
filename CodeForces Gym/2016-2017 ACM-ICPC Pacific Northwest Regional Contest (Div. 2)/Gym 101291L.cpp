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

struct Pane
{
    int x,y;
} p[3];

vector <Pane> v1,v2;

bool check()
{
    for(int i=0; i<3; i++)
    {
        for(int j=i+1; j<3; j++)
        {
            Pane t;
            if(p[i].x==p[j].x)
            {
                t.x=p[i].y+p[j].y;
                t.y=p[i].x;
                v1.PB(t);
                v2.PB(p[3-i-j]);
            }
            if(p[i].x==p[j].y)
            {
                t.x=p[i].y+p[j].x;
                t.y=p[i].x;
                v1.PB(t);
                v2.PB(p[3-i-j]);
            }
            if(p[i].y==p[j].x)
            {
                t.x=p[i].x+p[j].y;
                t.y=p[i].y;
                v1.PB(t);
                v2.PB(p[3-i-j]);
            }
            if(p[i].y==p[j].y)
            {
                t.x=p[i].x+p[j].x;
                t.y=p[i].y;
                v1.PB(t);
                v2.PB(p[3-i-j]);
            }
        }
    }
}

int main()
{
    for(int i=0; i<3; i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    check();
    if(!v1.size())
    {
        puts("NO");
        return 0;
    }
    for(int i=0; i<v1.size(); i++)
    {
        if(v1[i].x==v2[i].x && v1[i].x==v1[i].y+v2[i].y)
        {
            puts("YES");
            return 0;
        }
        if(v1[i].x==v2[i].y && v1[i].x==v1[i].y+v2[i].x)
        {
            puts("YES");
            return 0;
        }
        if(v1[i].y==v2[i].x && v1[i].y==v1[i].x+v2[i].y)
        {
            puts("YES");
            return 0;
        }
        if(v1[i].y==v2[i].y && v1[i].y==v1[i].x+v2[i].x)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
