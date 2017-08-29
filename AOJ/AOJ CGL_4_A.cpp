#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define EPS 1e-10
#define MAXN 100005
#define INF 0x7fffffff

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
    out<<fixed<<setprecision(0)<<p.x<<" "<<p.y;
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

bool cmp(Point a,Point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

//求凸包，如果不希望凸包边上有输入点，把<=改成<
int ConvexHull(Point *p,int n,Point *ch)
{
    sort(p,p+n,cmp);
    int m = 0;
    for(int i = 0; i<n; i++)
    {
        while(m>1&&sign(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i>=0; i--)
    {
        while(m>k&&sign(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<0) m--;
        ch[m++] = p[i];
    }
    if(n>1) m--;
    return m;
}

Point p[MAXN];
Point ch[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        p[i].read();
    int sz=ConvexHull(p,n,ch);
    cout << sz << endl;
    int t=0;
    for(int i=0; i<sz; i++)
    {
        if(ch[t].y>ch[i].y)
            t=i;
    }
    for(int i=t; i<sz; i++)
        cout << ch[i] << endl;
    for(int i=0; i<t; i++)
        cout << ch[i] << endl;
    return 0;
}
