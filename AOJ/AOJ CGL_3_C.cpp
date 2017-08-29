#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define EPS 1e-10
#define PB push_back

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

struct Polygon
{
    vector<Point> v;
};

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

int contains(Polygon g, Point p)
{
    int sz=g.v.size();
    bool flag=false;
    for(int i=0; i<sz; i++)
    {
        Vector a=g.v[i]-p;
        Vector b=g.v[(i+1)%sz]-p;
        if(fabs(Cross(a,b))==0 && Dot(a,b)<EPS)
            return 1;   //点在多边形边上
        if(a.y>b.y)
            swap(a,b);
        if(a.y<EPS && b.y>EPS && Cross(a,b)>EPS)
            flag=!flag;
    }
    return flag?2:0;   //点在多边形内/点在多边形外
}

int main()
{
    int n;
    scanf("%d",&n);
    Polygon poly;
    for(int i=1; i<=n; i++)
    {
        Point temp;
        temp.read();
        poly.v.PB(temp);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        Point p;
        p.read();
        int ans=contains(poly,p);
        printf("%d\n",ans);
    }
    return 0;
}
