/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-30
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
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
#define MAXN 50005

struct Point
{
    int x, y, z, id;
    Point() {}
    Point(int x, int y, int z, int id) : x(x), y(y), z(z), id(id) {}
    bool operator <(const Point &p) const
    {
        if(x == p.x)
        {
            if(y == p.y)
                return z < p.z;
            return y < p.y;
        }
        return x < p.x;
    }
} p[MAXN];

bool vis[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        p[i] = Point(x, y, z, i);
    }
    sort(p + 1, p + 1 + n);
    //先处理在同一条直线上的相邻两点（x坐标、y坐标相同的相邻两点）
    int l = 1, r = l + 1;
    while(r <= n)
    {
        //printf("%d - %d\n",l,r);
        if(p[l].x == p[r].x && p[l].y == p[r].y)
        {
            vis[l] = true;
            vis[r] = true;
            printf("%d %d\n", p[l].id, p[r].id);
            l = r + 1;
            r = l + 1;
        }
        else
        {
            l = r;
            r = l + 1;
        }
    }
    //再处理在同一个平面yOz上的相邻两点（x坐标相同的相邻两点）
    l = 1, r = l + 1;
    while(r <= n)
    {
        if(!vis[l])
        {
            while(vis[r] && r <= n)
                r++;
            if(p[l].x == p[r].x)
            {
                vis[l] = true;
                vis[r] = true;
                printf("%d %d\n", p[l].id, p[r].id);
                l = r + 1;
                r = l + 1;
            }
            else
            {
                l++;
                r = l + 1;
            }
        }
        else
        {
            l++;
            r = l + 1;
        }
    }
    //最后处理剩下的点
    l = 1, r = l + 1;
    while(r <= n)
    {
        if(!vis[l])
        {
            while(vis[r] && r <= n)
                r++;
            vis[l] = true;
            vis[r] = true;
            printf("%d %d\n", p[l].id, p[r].id);
            l = r + 1;
            r = l + 1;
        }
        else
        {
            l++;
            r = l + 1;
        }
    }
    return 0;
}
/*
8
0 2 0
1 0 1
1 1 0
1 1 1
2 2 2
2 2 4
2 3 2
2 2 3
*/
