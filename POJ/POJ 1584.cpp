/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-28
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 判断多边形凹凸性 + 线段相交
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
#define Vector Point

typedef double Type;

inline int dcmp(double x)
{
    return (x > EPS) - (x < -EPS);
}

//点的定义
struct Point
{
    Type x, y;
    //int belong;   //属于哪一个圆
    Point(Type x=0,Type y=0):x(x),y(y) {}

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

//距离
Type Length(Point p1,Point p2)
{
    Type x = p1.x - p2.x, y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}

Type Length(Vector v)
{
    return sqrt(v * v);
}

struct Line
{
    Point a,b;  //直线（线段）的两个端点（线段的时候可把a当作起点）
    Vector v;   //方向向量，v = b - a
    //double ang;//极角
    Line() {}
    Line(Point a,Point b):a(a),b(b)
    {
        v = b - a; /*ang = atan2(v.y, v.x);*/
    }
};

typedef Line Segment;

Type DistanceToLine(Point p,Line L)
{
    Vector v1 = L.b - L.a, v2 = p - L.a;
    return fabs(v1 ^ v2) / Length(v1);
}

bool OnSegment(Point &p,Segment& S)
{
    //小于0不包含端点，小于等于包含端点
    return dcmp((S.a-p)^(S.b-p)) == 0 && dcmp((S.a-p)*(S.b-p)) <= 0;
}

typedef vector<Point> Polygon;  //组成该平面的逆时针点集

int isPointInPolygon(Point p,Polygon &poly)
{
    int wn = 0;
    int n = poly.size();
    for(int i = 0; i < n; i++)
    {
        Segment seg(poly[i],poly[(i+1)%n]);
        if(OnSegment(p,seg))
            return -1;  //在多边形边界上
        int k = dcmp((poly[(i+1)%n] - poly[i]) ^ (p - poly[i]));
        int d1 = dcmp(poly[i].y - p.y);
        int d2 = dcmp(poly[(i+1)%n].y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0)
            wn++;
        if(k < 0 && d2 <= 0 && d1 > 0)
            wn--;
    }
    if(wn)
        return 1;   //在多边形内部
    return 0;   //在多边形外部
}

typedef Line Segment;

struct Circle
{
    Point c;
    double r;
    Circle(Point c,double r):c(c),r(r) {}
    Circle() {}
    Point polarCoordinates(double a)    //求圆边界上某个点相对于圆心的极角坐标
    {
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
    void read()
    {
        scanf("%lf%lf%lf",&r,&c.x,&c.y);    //题目要求先输入半径！！！
    }
};

bool isConvexHull(Point *p,int n)
{
    int flag = 0;   //记录顺时针还是逆时针
    for(int i=0; i<n; i++)
    {
        int temp = dcmp((p[(i+1)%n] - p[i%n]) ^ (p[(i+2)%n] - p[(i+1)%n]));
        if(!flag)
            flag = temp;
        if(flag * temp < 0)
            return false;
    }
    return true;
}

bool isCircleInPolygon(Circle C,int n,Polygon &poly)
{
    for(int i=0; i<n; i++)
    {
        if(dcmp(DistanceToLine(C.c,Line(poly[i%n],poly[(i+1)%n]))-C.r)<0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n<3)
            break;
        Circle C;
        C.read();
        Point p[1005];
        for(int i=0; i<n; i++)
            p[i].read();
        if(!isConvexHull(p,n))
            puts("HOLE IS ILL-FORMED");
        else
        {
            Polygon poly;
            for(int i=0; i<n; i++)
                poly.PB(p[i]);
            if(isPointInPolygon(C.c,poly) && isCircleInPolygon(C,n,poly))
                puts("PEG WILL FIT");
            else
                puts("PEG WILL NOT FIT");
        }
    }
    return 0;
}
