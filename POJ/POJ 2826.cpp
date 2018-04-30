/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-25
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 线段相交判定
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
const double EPS = 1e-8;
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

Point LineIntersection(Segment L1,Segment L2)
{
    Vector u = L1.a - L2.a;
    Vector v1 = L1.b - L1.a, v2 = L2.b - L2.a;
    Type t = (v2 ^ u) / (v1 ^ v2);
    return L1.a + v1 * t;
}

bool SegmentIntersect(Segment &s1,Segment& s2)
{
    Type c1 = (s1.b - s1.a) ^ (s2.a - s1.a), c2 = (s1.b - s1.a) ^ (s2.b - s1.a),
         c3 = (s2.b - s2.a) ^ (s1.a - s2.a), c4 = (s2.b - s2.a) ^ (s1.b - s2.a);
    return dcmp(c1) * dcmp(c2) <= 0 && dcmp(c3) * dcmp(c4) <= 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        Segment s[3];
        for(int i=1; i<=2; i++)
        {
            s[i].a.read();
            s[i].b.read();
        }
        if(!SegmentIntersect(s[1],s[2]) || s[1].a.y == s[1].b.y || s[2].a.y == s[2].b.y || dcmp((s[1].b - s[1].a) ^ (s[2].b - s[2].a)) == 0)
        {
            printf("0.00\n");
            continue;
        }
        //求两线段交点，并去除交点以下的线段
        Point p = LineIntersection(s[1],s[2]);
        for(int i=1; i<=2; i++)
        {
            if(s[i].a.y < s[i].b.y || (s[i].a.y == s[i].b.y && s[i].a.x < s[i].b.x))
                swap(s[i].a,s[i].b);   //把线段中点y值大的移到线段的a端点
            s[i].b = p;    //b端变为交点
        }
        if(s[1].a.y > s[2].a.y)
            swap(s[1],s[2]); //把线段a端y值大的移到水线段s[1]去
        if((s[1].a.x - p.x) * (s[1].a.y - p.y) * (s[2].a.x - p.x) * (s[2].a.y - p.y) > -EPS)//判断两直线斜率相乘是否大于0，除法和乘法正负性不变，就是4，5的情况和跟4,5对称的情况
        {
            Segment temp(s[1].a,Point(s[1].a.x,s[2].a.y));
            if(SegmentIntersect(temp,s[2])) //判断线段a端y值比较小的 线段 向上延长 跟 另一条线段是否相交,相交就说明 上面的板盖住了下面的板， 不能装水 。
            {
                printf("0.00\n");
                continue;
            }
        }
        // 剩下的情况都可以装水， 根据木桶效应，两个线段的高度应该取两个之中最低的
        if(s[1].a.y > s[2].a.y)
            s[1].a = LineIntersection(s[1],Segment(Point(0,s[2].a.y),Point(1,s[2].a.y)));
        else if(s[1].a.y < s[2].a.y)
            s[2].a = LineIntersection(s[2],Segment(Point(0,s[1].a.y),Point(1,s[1].a.y)));
        //计算面积
        printf("%.2f\n",fabs((s[2].b - s[2].a) ^ (s[1].b - s[1].a)) / 2 + EPS);
    }
    return 0;
}

/*
9
6259 2664 8292 9080
1244 2972 9097 9680

0 1 1 0
1 0 2 1

0 1 2 1
1 0 1 2

0 0 10 10
0 0 9 8

0 0 10 10
0 0 8 9

0.9 3.1 4 0
0 3 2 2

0 0 0 2
0 0 -3 2

1 1 1 4
0 0 2 3

1 2 1 4
0 0 2 3
*/
/*
6162.65
1.00
0.00
0.00
4.50
0.50
3.00
0.75
0.00
*/
