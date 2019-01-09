/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:2019-01-08
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 计算几何（极角排序） + 离散化 + dp
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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

struct Point
{
    int x,y,l;
    Point() {}
    Point(int x,int y,int l):x(x),y(y),l(l) {}
    void getLevel()
    {
        l = max(x,y);
    }
    void read()
    {
        scanf("%d%d",&x,&y);
        getLevel();
    }
} p[MAXN];

vector<Point> level[MAXN];
LL dp[MAXN][2]; //dp[i][0]表示到达第i层中（极角排序后的）第一个点的最短距离；dp[i][1]表示到达第i层中（极角排序后）的最后一个点的最短距离

bool cmp(Point a,Point b)
{
    if(a.l == b.l)
    {
        if(a.x == b.x)
            return a.y < b.y;
        return a.x > b.x;
    }
    return a.l < b.l;
}

LL getDis(Point a,Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main()
{
    int n;
    scanf("%d",&n);
    p[0] = Point(0,0,0);
    for(int i = 1; i <= n; i++)
        p[i].read();
    sort(p,p+n+1,cmp);
    int idx = 0;
    level[idx].PB(p[0]);
    for(int i = 1; i <= n; i++)
    {
        if(p[i].l == p[i-1].l)
            level[idx].PB(p[i]);
        else
            level[++idx].PB(p[i]);
    }
    /*
    for(int i=0; i<=idx; i++)
    {
        for(int j=0; j<level[i].size(); j++)
            printf("(%d,%d)",level[i][j].x,level[i][j].y);
        puts("");
    }
    */
    for(int i = 1; i <= idx; i++)
    {
        int sz1 = level[i-1].size();
        int sz2 = level[i].size();
        dp[i][0] = min(dp[i-1][0]+getDis(level[i-1][0],level[i][sz2-1]),dp[i-1][1]+getDis(level[i-1][sz1-1],level[i][sz2-1]));
        dp[i][0] += getDis(level[i][0],level[i][sz2-1]);
        //cout << i << ": " << dp[i][0] << " + " << getDis(level[i][0],level[i][sz2-1]) << endl;
        dp[i][1] = min(dp[i-1][0]+getDis(level[i-1][0],level[i][0]),dp[i-1][1]+getDis(level[i-1][sz1-1],level[i][0]));
        dp[i][1] += getDis(level[i][0],level[i][sz2-1]);
        //cout << i << ": " << dp[i][1] << " + " << getDis(level[i][0],level[i][sz2-1]) << endl;
    }
    printf("%I64d\n",min(dp[idx][0],dp[idx][1]));
    return 0;
}
