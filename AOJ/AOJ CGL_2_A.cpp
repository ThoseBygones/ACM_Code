#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define EPS 1e-6

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

bool isOrthogonal(Vector a,Vector b)
{
    return Dot(a,b)==0.0;
}

bool isParallel(Vector a,Vector b)
{
    return Cross(a,b)==0.0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        Point a,b,c,d;
        a.read();
        b.read();
        c.read();
        d.read();
        Vector x,y;
        x=a-b;
        y=c-d;
        if(isOrthogonal(x,y))
            puts("1");
        else if(isParallel(x,y))
            puts("2");
        else
            puts("0");
    }
    return 0;
}
