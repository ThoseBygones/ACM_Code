/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-10
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 二分 + 向量叉积
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

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
#define MAXN 5005

#define Vector Point

typedef double Type;

inline int dcmp(double x)
{
    return (x > EPS) - (x < -EPS);
}

struct Point
{
    Type x, y;
    //int belong;   //属于哪一个圆
    Point(Type x = 0, Type y = 0) : x(x), y(y) {}

    Vector operator + (const Vector& rhs) const
    {
        return Vector(x + rhs.x, y + rhs.y);
    }

    Vector operator - (const Point& rhs) const
    {
        return Vector(x - rhs.x, y - rhs.y);
    }

    Vector operator * (Type p) const
    {
        return Vector(x * p, y * p);
    }

    Vector operator / (Type p) const
    {
        return Vector(x / p, y / p);
    }

    bool operator < (const Point& rhs) const
    {
        return dcmp(x - rhs.x) < 0 || (dcmp(x-rhs.x)==0 && dcmp(y-rhs.y) < 0);
    }

    /*
    bool operator < (const Point& rhs) const
    {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
    */

    bool operator == (const Point& rhs) const
    {
        return dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) == 0;
    }

    bool operator > (const Point& rhs) const
    {
        return !(*this < rhs || *this == rhs);
    }

    bool operator >= (const Point& rhs) const
    {
        return !(*this < rhs);
    }

    bool operator <= (const Point& rhs) const
    {
        return (*this < rhs || *this == rhs);
    }

    double operator * (const Vector& rhs) const //点积
    {
        return x * rhs.x + y * rhs.y;
    }
    double operator ^ (const Vector& rhs) const //叉积
    {
        return x * rhs.y - y * rhs.x;
    }

    void read()
    {
        scanf("%lf%lf",&x,&y);
    }

    void print() const
    {
        printf("(%lf, %lf)",x,y);
    }
};

//叉积
Type Cross(Vector v1,Vector v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

Type Cross(Point &p0,Point &p1,Point &p2)
{
    return Cross(p1-p0,p2-p0);
}

struct CardBoard
{
    Point a,b;
} cb[MAXN];

bool cmp(CardBoard x,CardBoard y)
{
    return x.a.x<y.a.x;
}

int cnt[MAXN];
int num[MAXN];

int main()
{
    int n,m;
    double xx1,yy1,xx2,yy2;
    while(~scanf("%d",&n),n)
    {
        memset(cnt,0,sizeof(cnt));
        memset(num,0,sizeof(num));
        scanf("%d%lf%lf%lf%lf",&m,&xx1,&yy1,&xx2,&yy2);
        for(int i=0; i<n; i++)
        {
            double u,l;
            scanf("%lf%lf",&u,&l);
            cb[i].a.x=u;
            cb[i].a.y=yy1;
            cb[i].b.x=l;
            cb[i].b.y=yy2;
        }
        cb[n].a.x=xx2;
        cb[n].a.y=yy1;
        cb[n].b.x=xx2;
        cb[n].b.y=yy2;
        sort(cb,cb+1+n,cmp);
        for(int i=0; i<m; i++)
        {
            Point p;
            p.read();
            int l=0, r=n;
            int ans;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(dcmp(Cross(p,cb[mid].a,cb[mid].b))<0)
                {
                    ans=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            cnt[ans]++;
        }
        for(int i=0; i<=n; i++)
            num[cnt[i]]++;
        puts("Box");
        for(int i=1; i<=n; i++)
        {
            if(num[i])
                printf("%d: %d\n",i,num[i]);
        }
    }
    return 0;
}
