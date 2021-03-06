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

//距离
Type Length(Point a,Point b){
	Type x = a.x-b.x,y = a.y-b.y;
	return sqrt(x*x+y*y);
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

bool intersect(SegMent s1,SegMent s2)
{
    if(ccw(s1.a,s1.b,s2.a)*ccw(s1.a,s1.b,s2.b)<=0 && ccw(s2.a,s2.b,s1.a)*ccw(s2.a,s2.b,s1.b)<=0)
        return true;
    return false;
}

//点到线段距离
Type DistanceToSegMent(Point p,SegMent seg)
{
    if(seg.a==seg.b) return Length(p,seg.a);
    Vector v1 = seg.b-seg.a,v2 = p-seg.a,v3 = p-seg.b;
    if(sign(Dot(v1,v2))<0) return Length(v2);
    else if(sign(Dot(v1,v3))>0) return Length(v3);
    else return fabs(Cross(v1,v2))/Length(v1);
}

Type DistanceBetweenTwoSegMent(SegMent s1,SegMent s2)
{
    if(intersect(s1,s2))
        return 0.0;
    return min(min(DistanceToSegMent(s1.a,s2),DistanceToSegMent(s1.b,s2)),min(DistanceToSegMent(s2.a,s1),DistanceToSegMent(s2.b,s1)));
}

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        SegMent s1,s2;
        s1.a.read();
        s1.b.read();
        s2.a.read();
        s2.b.read();
        printf("%.10f\n",DistanceBetweenTwoSegMent(s1,s2));
    }
    return 0;
}
