#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define EPS 1e-15
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
    out<<fixed<<setprecision(10)<<p.x<<" "<<p.y;
    return out;
}

bool cmp(Point a,Point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

typedef Point Vector;

struct Line{
	Point a,b;
	Line(){}
	Line(Point a,Point b):a(a),b(b){}
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

//直线和圆交点
void getLineCircleIntersection(Line l,Circle C,vector<Point>& ret)
{
    Vector v = l.b-l.a;
    Type a = v.x,b = l.a.x-C.p.x,c = v.y,d = l.a.y-C.p.y;
    Type e = a*a+c*c,f = 2*(a*b+c*d),g = b*b+d*d-C.r*C.r;
    Type delta = f*f-4*e*g;
    Type t1,t2;
    if(sign(delta)<0) return;//相离
    if(sign(delta)==0)
    {
        t1 = t2 = -f/(2*e);
        ret.PB(l.a+v*t1);
        ret.PB(l.a+v*t2);   //本题中要求相切的时候（即只有一个交点的时候）记录两个相同的交点
    }
    else
    {
        t1 = (-f-sqrt(delta))/(2*e);
        //if(sign(t1-1)<=0&&sign(t1)>=0) //这条判断表示线段
            ret.PB(l.a+v*t1);
        t2 = (-f+sqrt(delta))/(2*e);
        //if(sign(t2-1)<=0&&sign(t2)>=0) //这条判断表示线段
            ret.PB(l.a+v*t2);
    }
}

int main()
{
    Circle c;
    c.p.read();
    scanf("%lf",&c.r);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        Line l;
        l.a.read();
        l.b.read();
        vector <Point> ans;
        getLineCircleIntersection(l,c,ans);
        sort(ans.begin(),ans.end(),cmp);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
