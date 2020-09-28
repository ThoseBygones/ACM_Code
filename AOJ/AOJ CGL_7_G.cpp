/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm: 两圆公切线
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
        printf("%.10f %.10f\n", x, y);
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
        scanf("%lf",&r);
    }
    void print()
    {
        printf("%.20f %.20f %.20f\n", p.x, p.y, r);
    }
};

//距离
Type Length(Point p1,Point p2)
{
    Type x = p1.x - p2.x, y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}

//向量的模
Type Length(Vector v)
{
    return sqrt(v * v);
}

//计算向量极角（需要<cmath>头文件）
double Angle(Vector v)
{
    return atan2(v.y, v.x);
}

int getTangents(Circle A, Circle B, vector<Point> &v)
{
    Point ta[5], tb[5];
    Point *a = ta, *b = tb;
    if(A.r < B.r)
    {
        swap(A, B);
        swap(a, b);
    }
    int cnt = 0;
    Type d2 = sqr(Length(A.p, B.p));
    Type rdiff = A.r - B.r;
    Type rsum = A.r + B.r;
    if(dcmp(d2 - rdiff * rdiff) < 0)
        return 0;   //内含
    Vector va = B.p - A.p;
    Type base = Angle(va);
    if(dcmp(d2) == 0 && dcmp(A.r - B.r) == 0)
        return -1;  //无限条切线
    if(dcmp(d2 - rdiff * rdiff) == 0)   //内切
    {
        a[cnt] = A.polarCoordinates(base);
        b[cnt++] = B.polarCoordinates(base);
        v.PB(Point(ta[0]));
        return 1;
    }
    //有外公切线
    Type ang = acos((A.r - B.r) / sqrt(d2));
    a[cnt] = A.polarCoordinates(base + ang);
    b[cnt++] = B.polarCoordinates(base + ang);
    a[cnt] = A.polarCoordinates(base - ang);
    b[cnt++] = B.polarCoordinates(base - ang);
    if(dcmp(d2 - rsum * rsum) == 0) //一条内公切线
    {
        a[cnt] = A.polarCoordinates(base);
        b[cnt++] = B.polarCoordinates(PI + base);
    }
    else if(dcmp(d2 - rsum * rsum) > 0)
    {
        Type ang = acos((A.r + B.r) / sqrt(d2));
        a[cnt] = A.polarCoordinates(base + ang);
        b[cnt++] = B.polarCoordinates(PI + base + ang);
        a[cnt] = A.polarCoordinates(base - ang);
        b[cnt++] = B.polarCoordinates(PI + base - ang);
    }
    for(int i = 0; i < cnt; i++)
        v.PB(Point(ta[i]));
    return cnt;
}

int main()
{
    Circle c1, c2;
    c1.read();
    c2.read();
    vector<Point> ans;
    int cnt = getTangents(c1, c2, ans);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < cnt; i++)
        ans[i].print();
    return 0;
}
