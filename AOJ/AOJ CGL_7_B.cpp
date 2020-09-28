/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm: 三角形内切圆
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

template<class T> inline T sqr(T x) {return x * x;}
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

struct Circle
{
    Point p;
    Type r;
    Circle(Point p,Type r):p(p),r(r) {}
    Circle() {}
    void read()
    {
        p.read();
        scanf("%lf",&r);
    }
    void print()
    {
        printf("%.20f %.20f %.20f\n", p.x, p.y, r);
    }
};

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

Type DistanceToLine(Point p, Line L)
{
    Vector v1 = L.b - L.a, v2 = p - L.a;
    return fabs(v1 ^ v2) / Length(v1);
}

Circle TriangleInscribedCircle(Point p1,Point p2,Point p3)
{
    double a = Length(p2,p3);
    double b = Length(p1,p3);
    double c = Length(p1,p2);
    Point p = (p1 * a + p2 * b + p3 * c) / (a + b + c);
    return Circle(p,DistanceToLine(p,Line(p1,p2)));
}

int main()
{
    Point p1, p2, p3;
    p1.read();
    p2.read();
    p3.read();
    Circle c = TriangleInscribedCircle(p1, p2, p3);
    c.print();
    return 0;
}
