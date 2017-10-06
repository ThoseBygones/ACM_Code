#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
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

Circle c[MAXN];

int main()
{
    int n;
    Point P(0.0,0.0);
    double r,d;
    scanf("%lf%lf",&r,&d);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        c[i].p.read();
        scanf("%lf",&c[i].r);
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        double dis=Length(P,c[i].p);
        if(dis>=r-d+c[i].r && dis<=r-c[i].r)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
