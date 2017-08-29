#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define EPS 1e-10

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
    out<<fixed<<setprecision(10)<<p.x<<" "<<p.y;
    return out;
}

typedef Point Vector;

struct Line
{
    Point a,b;
    Line() {}
    Line(Point a,Point b):a(a),b(b) {}
};

typedef Line SegMent;

//长度
Type Length(Vector v)
{
    return sqrt(v.x*v.x+v.y*v.y);
}

Type Norm(Vector v)
{
    return v.x*v.x+v.y*v.y;
}

//点积
Type Dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}

Point project(SegMent s,Point p)
{
    Vector x=s.b-s.a;
    Type r=Dot(p-s.a,x)/Norm(x);
    return s.a+x*r;
}

Point reflect(SegMent s,Point p)
{
    return p+(project(s,p)-p)*2.0;
}

int main()
{
    SegMent s;
    s.a.read();
    s.b.read();
    int q;
    scanf("%d",&q);
    while(q--)
    {
        Point a;
        a.read();
        Point ans=reflect(s,a);
        cout << ans << endl;
    }
    return 0;
}
