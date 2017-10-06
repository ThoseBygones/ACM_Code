#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define MAXN 105
#define EPS 1e-6
#define INF 1e18

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

//距离
Type Length(Point a,Point b)
{
    Type x = a.x-b.x,y = a.y-b.y;
    return sqrt(x*x+y*y);
}

//长度
Type Length(Vector v)
{
    return sqrt(v.x*v.x+v.y*v.y);
}

//叉积
Type Cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}

Type Cross(Point &a,Point &b,Point &c)
{
    return Cross(a-c,b-c);
}

//点积
Type Dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
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

Point p[MAXN];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    if(m+k<n+2 || m+k>n+4)
    {
        puts("-1");
        return 0;
    }
    for(int i=0; i<n; i++)
        p[i].read();
    double ans=INF;
    int j;
    SegMent s;
    for(int i=0; i<n; i++)
    {
        if(m+k==n+2)    //切割线的端点为多边形的顶点
        {
            j=(i+k-1)%n;
            ans=min(ans,Length(p[i],p[j]));
            j=(i+m-1)%n;
            ans=min(ans,Length(p[i],p[j]));
        }
        else if(m+k==n+3)   //切割线的一个端点为多边形的顶点，另一个端点在多边形的一条边上
        {
            j=(i+k-2)%n;
            s.a=p[j],s.b=p[(j+1)%n];
            ans=min(ans,DistanceToSegMent(p[i],s));
            j=(i+m-2)%n;
            s.a=p[j],s.b=p[(j+1)%n];
            ans=min(ans,DistanceToSegMent(p[i],s));
        }
        else if(m+k==n+4)   //切割线的两个端点分别在多边形的两条不同的边上，枚举其中一个点的位置
        {
            j=(i+k-2)%n;
            s.a=p[j],s.b=p[(j+1)%n];
            ans=min(ans,DistanceToSegMent(p[i],s));
            ans=min(ans,DistanceToSegMent(p[(i+1)%n],s));
            j=(i+m-2)%n;
            s.a=p[j],s.b=p[(j+1)%n];
            ans=min(ans,DistanceToSegMent(p[i],s));
            ans=min(ans,DistanceToSegMent(p[(i+1)%n],s));
        }
    }
    printf("%.3f\n",ans);
    return 0;
}
