/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm: 多边形与圆的面积交
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

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
//#include <bits/stdc++.h>
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
        printf("(%f, %f)",x,y);
    }
};

//向量的模
Type Length(Vector v)
{
    return sqrt(v * v);
}

//向量的夹角 a*b=|a||b|cosα
Type Angle(Vector v1,Vector v2)
{
    return acos(v1 * v2 / Length(v1) / Length(v2));
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

struct Circle
{
    Point p;
    Type r;
    Circle(Point p,Type r):p(p),r(r) {}
    Circle() {}
    Point polarCoordinates(double a)    //求圆边界上某个点相对于圆心的极角坐标
    {
        return Point(p.x + cos(a) * r, p.y + sin(a) * r);
    }
    void read()
    {
        p.read();
        scanf("%lf", &r);
    }
};

typedef vector<Point> Polygon;  //组成该平面的逆时针点集

int getLineCircleIntersection(Line L, Circle C, vector<Point>& ret)
{
    Vector v = L.b - L.a;
    Type a = v.x, b = L.a.x - C.p.x, c = v.y, d = L.a.y - C.p.y;
    Type e = a * a + c * c, f = 2 * (a * b + c * d), g = b * b + d * d - C.r * C.r;
    Type delta = f * f - 4 * e * g;
    Type t1, t2;
    if(dcmp(delta) < 0) //相离
        return 0;
    if(dcmp(delta) == 0)    //相切
    {
        t1 = t2 = -f / (2 * e);
        ret.PB(L.a + v * t1);
        return 1;
    }
    else
    {
        t1 = (-f - sqrt(delta)) / (2 * e);
        ret.PB(L.a + v * t1);
        t2 = (-f + sqrt(delta)) / (2 * e);
        ret.PB(L.a + v * t2);
        return 2;
    }
}


double CircleTriangleIntersectionArea(Circle c, Point a, Point b) 	//a,b与圆心c所围成的三角形与圆围成的面积
{
    double r = c.r;
    if(dcmp((c.p - a) ^ (c.p - b)) == 0)
        return 0.0;
    vector<Point> p, tmp;
    p.PB(a);
    Line l(a, b);
    if(getLineCircleIntersection(l, c, tmp) == 2)   //直线和圆的位置关系  0:相离   1:相切   2:相交
    {
        if(dcmp((a - tmp[0]) * (b - tmp[0])) < 0)
            p.PB(tmp[0]);
        if(dcmp((a - tmp[1]) * (b - tmp[1])) < 0)
            p.PB(tmp[1]);
    }
    p.PB(b);
    if(sz(p) == 4 && dcmp((p[0] - p[1]) * (p[2] - p[1])) > 0)
        swap(p[1], p[2]);
    double res = 0.0;
    for(int i = 0; i < sz(p) - 1; i++)
    {
        Vector v1 = p[i] - c.p, v2 = p[i + 1] - c.p;
        if(dcmp(Length(v1) - c.r) > 0 || dcmp(Length(v2) - c.r) > 0)
        {
            double arg = Angle(v1, v2);
            res += c.r * c.r * arg / 2.0;
        }
        else
            res += fabs((v1 ^ v2) / 2.0);
    }
    return res;
}

//圆与多边形交（利用三角剖分）
double CirclePolygonIntersectionArea(Circle c, Polygon &poly)
{
    double ret = 0;
    for(int i = 0; i < sz(poly); i++)
    {
        Vector v1 = poly[i] - c.p, v2 = poly[(i + 1) % sz(poly)] - c.p;
        ret += 1.0 * dcmp(v1 ^ v2) * CircleTriangleIntersectionArea(c, poly[i], poly[(i + 1) % sz(poly)]);
    }
    return fabs(ret);
}


int main()
{
    int n;
    double r;
    scanf("%d%lf", &n, &r);
    Circle c = Circle(Point(0.0, 0.0), r);
    Polygon poly;
    for(int i = 0; i < n; i++)
    {
        Point p;
        p.read();
        poly.PB(p);
    }
    double ans = CirclePolygonIntersectionArea(c, poly);
    printf("%.12f\n", ans);
    return 0;
}
