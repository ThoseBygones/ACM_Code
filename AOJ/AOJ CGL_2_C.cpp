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

//叉积
Type Cross(Vector a,Vector b){
	return a.x*b.y-a.y*b.x;
}

Point CrossPoint(SegMent s1,SegMent s2)
{
    Vector x=s2.b-s2.a;
    double d1=fabs(Cross(x,s2.a-s1.a));
    double d2=fabs(Cross(x,s2.b-s1.b));
    double t=d1/(d1+d2);
    return s1.a+(s1.b-s1.a)*t;
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
        Point ans=CrossPoint(s1,s2);
        cout << ans << endl;
    }
    return 0;
}
