/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-20
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 线段相交
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

//向量的模
Type Length(Vector v)
{
    return sqrt(v * v);
}

Vector Normal(Vector v)
{
    Type l = Length(v);
    return Vector(-v.y / l, v.x / l);
}

struct Line
{
    Point a,b;  //直线（线段）的两个端点（线段的时候可把a当作起点）
    Vector v;   //方向向量，v = b - a
    //double ang;//极角
    Line() {}
    Line(Point a,Point b):a(a),b(b) {/*ang = atan2(v.y, v.x);*/ v = b - a;}
    Line move(double d)
    {
        return Line(a+Normal(v)*d,b+Normal(v)*d);
    }
    bool operator < (const Line& rhs) const
    {
        //根据原点极角排序(小的在前；极角相同，长度小的在前)
        //return ang < L.ang;
        if (v.y * rhs.v.y > 0)  //同上同下
        {
            if ((v ^ rhs.v) != 0)
                return (v ^ rhs.v) > 0;
            return Length(v) > Length(rhs.v);   //极角相同，长的小
        }
        if (v.y * rhs.v.y < 0)
            return v.y < 0; //一上一下
        if (v.y == 0)
        {
            if (rhs.v.y == 0)
            {
                if (v.x * rhs.v.x < 0)
                    return v.x > rhs.v.x;
                return Length(v) > Length(rhs.v);   //极角相同长的小
            }
            if (v.x > 0)
                return rhs.v.y > 0;
            return false;
        }
        if (rhs.v.x > 0)
            return v.y < 0;
        return true;
    }
};

typedef Line Segment;

bool OnSegment(Point &p,Segment& S)
{
    //小于0不包含端点，小于等于包含端点
    return dcmp((S.a-p)^(S.b-p)) == 0 && dcmp((S.a-p)*(S.b-p)) <= 0;
}

//线段规范相交
bool SegmentProperIntersect(Segment &s1,Segment& s2)
{
    Type c1 = (s1.b - s1.a) ^ (s2.a - s1.a), c2 = (s1.b - s1.a) ^ (s2.b - s1.a),
         c3 = (s2.b - s2.a) ^ (s1.a - s2.a), c4 = (s2.b - s2.a) ^ (s1.b - s2.a);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

//线段不规范相交（使用的时候结合线段规范相交的函数一起判断）
bool SegmentNotProperIntersect(Segment& s1,Segment& s2)
{
    return OnSegment(s1.a,s2) || OnSegment(s1.b,s2) || OnSegment(s2.a,s1) || OnSegment(s2.b,s1);
}

Segment s[105];

int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=0; i<n; i++)
        {
            s[i].a.read();
            s[i].b.read();
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(SegmentProperIntersect(s[i],s[j]) || SegmentNotProperIntersect(s[i],s[j]))
                    cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
