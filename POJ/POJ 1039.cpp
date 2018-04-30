/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-25
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
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

bool LineIntersectSegment(Line &L,Segment &S)
{
    Vector a(S.a-L.a);
    Vector b(S.b-L.a);
    Vector c(L.b-L.a);
    int dcmpA = dcmp(c ^ a);
    int dcmpB = dcmp(c ^ b);
    return dcmpA * dcmpB <= 0;
}

Point LineIntersection(Line &L1,Line& L2)
{
    Vector u = L1.a - L2.a;
    Vector v1 = L1.b - L1.a, v2 = L2.b - L2.a;
    Type t = (v2 ^ u) / (v1 ^ v2);
    return L1.a + v1 * t;
}

Point u[25],b[25];    //upper points & bottom points

int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=0; i<n; i++)
        {
            u[i].read();
            b[i].x=u[i].x;
            b[i].y=u[i].y-1.0;
        }
        double ans=-1e9;
        bool flag=false;
        for(int i=0; i<n; i++)  //枚举upper points
        {
            if(flag)    //是否完全穿透的标记
                break;
            for(int j=0; j<n; j++)  //枚举bottom points
            {
                Line l(u[i],b[j]);
                int k=0;
                while(k<n)  //枚举每个横截面
                {
                    Segment s(u[k],b[k]);
                    if(!LineIntersectSegment(l,s))
                        break;
                    k++;
                }
                if(k==n)
                {
                    flag=true;
                    break;
                }
                if(k>=max(i,j)) //光线可以通过当前截面后再往前
                {
                    Segment s1(u[k-1],u[k]), s2(b[k-1],b[k]);
                    if(LineIntersectSegment(l,s1))    //判断光线是否与后面的上侧管壁相交
                    {
                        Point p=LineIntersection(l,s1);
                        ans=max(ans,p.x);
                    }
                    if(LineIntersectSegment(l,s2))    //判断光线是否与后面的上侧管壁相交
                    {
                        Point p=LineIntersection(l,s2);
                        ans=max(ans,p.x);
                    }
                }
            }
        }
        if(flag)
            puts("Through all the pipe.");
        else
            printf("%.2f\n",ans);
    }
    return 0;
}
