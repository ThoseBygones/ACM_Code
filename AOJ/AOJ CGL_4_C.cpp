/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-07-29
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: AOJ
 *  Algorithm:
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
#define MAXN 105

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

Point LineIntersection(Line &L1,Line &L2)
{
    Vector u = L1.a - L2.a;
    Vector v1 = L1.b - L1.a, v2 = L2.b - L2.a;
    if(dcmp(v1 ^ v2) == 0)
    {
        if(dcmp(u ^ v1))
            return Point(-INF,-INF);//平行
        else
            return Point(-INF,-INF);//在一条线上
    }
    Type t = (v2 ^ u) / (v1 ^ v2);
    return L1.a + v1 * t;
}

bool OnSegment(Point &p,Segment& S)
{
    //小于0不包含端点，小于等于包含端点
    return dcmp((S.a-p)^(S.b-p)) == 0 && dcmp((S.a-p)*(S.b-p)) <= 0;
}

typedef vector<Point> Polygon;  //组成该平面的逆时针点集

double PolygonArea(Polygon &poly)
{
    if(poly.size() == 0)
        return 0;
    double area = 0;
    for(int i=1; i<poly.size()-1; i++)
        area += ((poly[i] - poly[0]) ^ (poly[i + 1] - poly[0]));
    return area / 2;
}

//用有向直线A->B切割多边形poly，返回“左侧”。 如果退化，可能会返回一个单点或者线段
Polygon CutPolygon(Polygon& poly,Point A,Point B)
{
    Polygon newpoly;
    int n = poly.size();
    for(int i = 0; i < n; i++)
    {
        Point C = poly[i];
        Point D = poly[(i+1)%n];
        if(dcmp((B-A)^(C-A)) >= 0)
            newpoly.PB(C);
        if(dcmp((B-A)^(C-D)) != 0)
        {
            Line l1 = Line(A,B);
            Line l2 = Line(C,D);
            Point ip = LineIntersection(l1,l2);
            Segment seg = Segment(C,D);
            if(OnSegment(ip,seg))
                newpoly.PB(ip);
        }
    }
    return newpoly;
}

Polygon poly;

int main()
{
    int n;
    scanf("%d",&n);
    Point p;
    for(int i=0; i<n; i++)
    {
        p.read();
        poly.PB(p);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        Point a,b;
        a.read();
        b.read();
        Polygon newpoly=CutPolygon(poly,a,b);
        printf("%f\n",PolygonArea(newpoly));
    }
    return 0;
}
