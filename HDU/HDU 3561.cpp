/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-13
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 两圆交点
 ********************************************************************************
 *  Algo-Description:
 * > 求出所有圆的交点；
 * > 计算每个交点以及每个圆的圆心被所有圆覆盖的次数和；
 * > 取最大值即可。
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

const int MAXN = 105;

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

Type Length(Point p1,Point p2)
{
    Type x = p1.x - p2.x, y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}

double Angle(Vector v)
{
    return atan2(v.y, v.x);
}

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

int getTwoCirclesIntersection(Circle c1, Circle c2, vector<Point> &ret)
{
    Type d = Length(c1.p, c2.p);
    if(dcmp(d) == 0)
    {
        if(dcmp(c1.r - c2.r) == 0)
            return -1;  //两圆重合
        return 0;   //内含
    }
    if(dcmp(c1.r + c2.r - d) < 0)
        return 0;   //相离
    if(dcmp(fabs(c1.r - c2.r) - d) > 0)
        return 0;   //内含
    Type a = Angle(c2.p - c1.p);
    Type da = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    Point p1 = c1.polarCoordinates(a - da), p2 = c1.polarCoordinates(a + da);
    ret.PB(p1);
    if(p1 == p2)
        return 1;
    ret.PB(p2);
    return 2;
}

bool isInCircle(Point p, Circle C)
{
    return dcmp((p - C.p) * (p - C.p) - C.r * C.r) <= 0;
}


Circle c[MAXN];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        vector<Point> ans;
        for(int i = 0; i < n; i++)
        {
            c[i].read();
            ans.PB(c[i].p);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
                getTwoCirclesIntersection(c[i], c[j], ans);
        }
        int Max = 0;
        for(int i = 0; i < ans.size(); i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(isInCircle(ans[i], c[j]))
                    cnt++;
            }
            Max = max(Max, cnt);
        }
        printf("%d\n", Max);
    }
    return 0;
}
