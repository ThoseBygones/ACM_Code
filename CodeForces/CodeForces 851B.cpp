#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define MAXN 1005
#define EPS 0

typedef LL Type;

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
        scanf("%I64d %I64d",&x,&y);
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

//距离
Type Length(Point a,Point b)
{
    Type x = a.x-b.x,y = a.y-b.y;
    return x*x+y*y;
}

Type check(Point a,Point b,Point c)
{
    if((b.y-a.y)*(c.x-b.x)==(c.y-b.y)*(b.x-a.x))
        return false;
    return true;
}

int main()
{
    Point a,b,c;
    a.read();
    b.read();
    c.read();
    if(check(a,b,c) && Length(a,b)==Length(b,c))
        puts("Yes");
    else
        puts("No");
    return 0;
}
