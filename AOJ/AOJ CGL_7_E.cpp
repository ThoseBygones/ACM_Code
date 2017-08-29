#include <iostream>
#include <iomanip>
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
    out<<fixed<<setprecision(8)<<p.x<<" "<<p.y;
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

//计算向量极角
Type Angle(Vector v)
{
    return atan2(v.y,v.x);
}

//圆交点
void getCircleInterSection(Circle c1,Circle c2,vector<Point> &ret)
{
    Type d = Length(c1.p,c2.p);
    /*if(sign(d)==0)
    {
        if(sign(c1.r-c2.r)==0) return -1;//两圆重合
        return 0;//内含
    }
    if(sign(c1.r+c2.r-d)<0) return 0;//相离
    if(sign(fabs(c1.r-c2.r)-d)>0) return 0;//内含
        */
    Type a = Angle(c2.p-c1.p);
    Type da = acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    Point p1 = c1.getPoint(a-da),p2 = c1.getPoint(a+da);
    ret.PB(p1);
    //if(p1==p2) return 1;
    ret.PB(p2);
    //return 2;
}

int main()
{
    Circle c1,c2;
    c1.p.read();
    scanf("%lf",&c1.r);
    c2.p.read();
    scanf("%lf",&c2.r);
    vector <Point> ans;
    getCircleInterSection(c1,c2,ans);
    sort(ans.begin(),ans.end());
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
