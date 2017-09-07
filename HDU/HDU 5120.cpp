#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define LL long long
#define PII pair
#define MP make_pair
#define PB push_back
#define EPS 1e-10
#define PI acos(-1)

typedef double Type;

int sign(Type x)
{
    return x<-EPS?-1:(x>EPS?1:0);
}

struct Point
{
    Type x,y;
    Point(Type x,Type y):x(x),y(y) {}
    Point() {}
    void read()
    {
        scanf("%lf %lf",&x,&y);
    }
    bool operator==(const Point& p) const
    {
        return sign(x-p.x)==0&&sign(y-p.y)==0;
    }
    Point operator-(const Point& p) const
    {
        return Point(x-p.x,y-p.y);
    }
    Point operator*(const Type t) const
    {
        return Point(t*x,t*y);
    }
    Point operator+(const Point & p) const
    {
        return Point(x+p.x,y+p.y);
    }
    bool operator<(const Point& p) const
    {
        return sign(x-p.x)==0?sign(y-p.y)<0:sign(x-p.x)<0;
    }
};

ostream& operator<<(ostream& out,Point p)
{
    out<<p.x<<" "<<p.y;
    return out;
}

struct Circle
{
    Point p;
    Type r;
    Circle() {}
    Circle(Point p,Type r):p(p),r(r) {}
    //通过圆心角获得点坐标
    Point getPoint(double a)
    {
        return Point(p.x+cos(a)*r,p.y+sin(a)*r);
    }
};

//距离
Type Length(Point a,Point b)
{
    Type x = a.x-b.x,y = a.y-b.y;
    return sqrt(x*x+y*y);
}

//两圆面积交
Type getInterArea(Circle a,Circle b)
{
    Type dis = Length(a.p,b.p);
    if(sign(a.r+b.r-dis)<=0) return 0;
    if(sign(abs(a.r-b.r)-dis)>=0)
    {
        Type r = min(a.r,b.r);
        return PI*r*r;
    }
    Type cosX = (dis*dis+a.r*a.r-b.r*b.r)/(2*dis*a.r);
    Type X = acos(cosX);
    Type cosY = (dis*dis+b.r*b.r-a.r*a.r)/(2*dis*b.r);
    Type Y = acos(cosY);
    return a.r*a.r*X+b.r*b.r*Y-dis*a.r*sin(X);
}

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double r,R;
        scanf("%lf%lf",&r,&R);
        Circle cb1,cb2,cs1,cs2;
        Point a,b;
        a.read();
        b.read();
        cb1.p=cs1.p=a;
        cb2.p=cs2.p=b;
        cb1.r=cb2.r=R;
        cs1.r=cs2.r=r;
        Type ans=getInterArea(cb1,cb2)+getInterArea(cs1,cs2)-getInterArea(cb1,cs2)-getInterArea(cb2,cs1);
        printf("Case #%d: %.6f\n",kase++,ans);
    }
    return 0;
}
