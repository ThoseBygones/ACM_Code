#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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

Type Cross(Point &a,Point &b,Point &c)
{
    return Cross(a-c,b-c);
}

//点积
Type Dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}

//线段规范相交
bool SegMentProperIntersect(SegMent &s1,SegMent& s2){
	Type c1 = Cross(s1.b-s1.a,s2.a-s1.a),c2 = Cross(s1.b-s1.a,s2.b-s1.a),
c3 = Cross(s2.b-s2.a,s1.a-s2.a),c4 = Cross(s2.b-s2.a,s1.b-s2.a);
	return sign(c1)*sign(c2)<0&&sign(c3)*sign(c4)<0;
}

//判断点在线段上
bool OnSegMent(Point &p,SegMent& s)
{
    //小于0不包含端点，小于等于包含端点
    return sign(Cross(s.a-p,s.b-p))==0&&sign(Dot(s.a-p,s.b-p))<=0;
}

//线段不规范相交
bool SegMentNotProperIntersect(SegMent& s1,SegMent& s2)
{
    return OnSegMent(s1.a,s2)||OnSegMent(s1.b,s2)||OnSegMent(s2.a,s1)||OnSegMent(s2.b,s1);
}

SegMent s[15];
int fa[15];
int dep[15];

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

void unionset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
    {
        if(dep[xx]>dep[yy]) //比较两个集合的深度
            fa[yy]=xx;
        else
        {
            fa[xx]=yy;
            if(dep[xx]==dep[yy])
                dep[yy]++;
        }
    }
}

int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=1; i<=n; i++)
        {
            s[i].a.read();
            s[i].b.read();
            fa[i]=i;
            dep[i]=0;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(SegMentProperIntersect(s[i],s[j])||SegMentNotProperIntersect(s[i],s[j]))
                    unionset(i,j);
            }
        }
        int a,b;
        while(~scanf("%d%d",&a,&b))
        {
            if(a==0 && b==0)
                break;
            if(findset(a)==findset(b))
                puts("CONNECTED");
            else
                puts("NOT CONNECTED");
        }
    }
    return 0;
}
