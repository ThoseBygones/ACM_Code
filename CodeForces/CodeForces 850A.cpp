#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define EPS 1e-8
#define PI acos(-1.0)

typedef double Type;

int sign(Type x)
{
    return x<-EPS?-1:(x>EPS?1:0);
}

struct Point
{
    Type x1,x2,x3,x4,x5;
    Point(Type x1,Type x2,Type x3,Type x4,Type x5):x1(x1),x2(x2),x3(x3),x4(x4),x5(x5) {}
    Point() {}
    void read()
    {
        scanf("%lf %lf %lf %lf %lf",&x1,&x2,&x3,&x4,&x5);
    }
    bool operator==(const Point& p) const
    {
        return sign(x1-p.x1)==0&&sign(x2-p.x2)==0&&sign(x3-p.x3)==0&&sign(x4-p.x4)==0&&sign(x5-p.x5)==0;
    }
    Point operator-(const Point& p) const
    {
        return Point(x1-p.x1,x2-p.x2,x3-p.x3,x4-p.x4,x5-p.x5);
    }
};

typedef Point Vector;

Type Length(Point a,Point b)
{
    Type x1 = a.x1 - b.x1;
    Type x2 = a.x2 - b.x2;
    Type x3 = a.x3 - b.x3;
    Type x4 = a.x4 - b.x4;
    Type x5 = a.x5 - b.x5;
    return sqrt(x1*x1+x2*x2+x3*x3+x4*x4+x5*x5);
}

//长度
Type Length(Vector v)
{
    return sqrt(v.x1*v.x1+v.x2*v.x2+v.x3*v.x3+v.x4*v.x4+v.x5*v.x5);
}

//点积
Type Dot(Vector a,Vector b)
{
    return a.x1*b.x1+a.x2*b.x2+a.x3*b.x3+a.x4*b.x4+a.x5*b.x5;
}

//两个向量的夹角
Type Angle(Vector A,Vector B)
{
    return acos(Dot(A,B)/Length(A)/Length(B));
}

Point p[MAXN];
vector <int> ans;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        p[i].read();
    for(int i=1; i<=n; i++)
    {
        bool good = true;
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                if(i!=j && j!=k)
                {
                    Vector a=p[j]-p[i];
                    Vector b=p[k]-p[i];
                    if(Angle(a,b)>=0 && Angle(a,b)<PI/2.0)
                    {
                        good=false;
                        break;
                    }
                }
            }
            if(!good)
                break;
        }
        if(good)
            ans.push_back(i);
    }
    printf("%d\n",ans.size());
    for(int i=0; i<ans.size(); i++)
        printf("%d\n",ans[i]);
    return 0;
}
