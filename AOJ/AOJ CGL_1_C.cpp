#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define EPS 1e-10

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

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

typedef Point Vector;

struct Line
{
    Point a,b;
    Line() {}
    Line(Point a,Point b):a(a),b(b) {}
};

typedef Line SegMent;

//叉积
Type Cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}

//点积
Type Dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}

//长度
Type Length(Vector v)
{
    return sqrt(v.x*v.x+v.y*v.y);
}

int ccw(Point p0,Point p1,Point p2)
{
    Vector a=p1-p0;
    Vector b=p2-p0;
    if(Cross(a,b)>EPS)
        return COUNTER_CLOCKWISE;
    if(Cross(b,a)>EPS)
        return CLOCKWISE;
    if(Dot(a,b)<-EPS)
        return ONLINE_BACK;
    if(Length(a)<Length(b))
        return ONLINE_FRONT;
    if(Length(a)>Length(b))
        return ON_SEGMENT;
}

int main()
{
    Point p0,p1,p2;
    p0.read();
    p1.read();
    int q;
    scanf("%d",&q);
    while(q--)
    {
        p2.read();
        int flag=ccw(p0,p1,p2);
        if(flag==COUNTER_CLOCKWISE)
            puts("COUNTER_CLOCKWISE");
        if(flag==CLOCKWISE)
            puts("CLOCKWISE");
        if(flag==ONLINE_BACK)
            puts("ONLINE_BACK");
        if(flag==ONLINE_FRONT)
            puts("ONLINE_FRONT");
        if(flag==ON_SEGMENT)
            puts("ON_SEGMENT");
    }
    return 0;
}
