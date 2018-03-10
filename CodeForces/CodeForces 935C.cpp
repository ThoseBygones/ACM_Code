/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-03-10
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
using namespace std;
template<class T> inline T sqr(T x)
{
    return x * x;
}
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

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

//距离
Type Length(Point a,Point b){
	Type x = a.x-b.x,y = a.y-b.y;
	return sqrt(x*x+y*y);
}

struct Circle
{
    Point p;
    Type r;
    Circle() {}
    void read()
    {
        scanf("%lf %lf %lf",&r,&p.x,&p.y);
    }
    Circle(Point p,Type r):p(p),r(r) {}
    //通过圆心角获得点坐标
    Point getPoint(double a)
    {
        return Point(p.x+cos(a)*r,p.y+sin(a)*r);
    }
};

int main()
{
    Circle flat;
    flat.read();
    Point fafa;
    fafa.read();
    double dis=Length(flat.p,fafa);
    if(dis==0)
    {
        printf("%.16f %.16f %.16f\n",flat.p.x+flat.r/2.0,flat.p.y,flat.r/2.0);
        return 0;
    }
    if(dis>flat.r)
    {
        printf("%.16f %.16f %.16f\n",flat.p.x,flat.p.y,flat.r);
        return 0;
    }
    double r=(dis+flat.r)/2.0;
    double sina=(flat.p.y-fafa.y)/dis;
    double cosa=(flat.p.x-fafa.x)/dis;
    double nx=fafa.x+cosa*r;
    double ny=fafa.y+sina*r;
    printf("%.16f %.16f %.16f\n",nx,ny,r);
    return 0;
}
