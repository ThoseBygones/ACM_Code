/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-07-20
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: AOJ
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
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
const double EPS = 1e-10;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 100005

//端点的种类
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

#define Vector Point

typedef double Type;

inline int dcmp(double x)
{
    return (x > EPS) - (x < -EPS);
}

//点的定义
struct Point
{
    Type x, y;
    //int belong;   //属于哪一个圆
    Point(Type x=0,Type y=0):x(x),y(y) {}

    Vector operator + (const Vector& rhs) const
    {
        return Vector(x + rhs.x, y + rhs.y);
    }
    Vector operator - (const Point& rhs) const
    {
        return Vector(x - rhs.x, y - rhs.y);
    }
    Vector operator * (Type p) const
    {
        return Vector(x * p, y * p);
    }
    Vector operator / (Type p) const
    {
        return Vector(x / p, y / p);
    }
    bool operator < (const Point& rhs) const
    {
        return dcmp(x - rhs.x) < 0 || (dcmp(x-rhs.x)==0 && dcmp(y-rhs.y) < 0);
    }
    /*
    bool operator < (const Point& rhs) const
    {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
    */
    bool operator == (const Point& rhs) const
    {
        return dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) == 0;
    }
    bool operator > (const Point& rhs) const
    {
        return !(*this < rhs || *this == rhs);
    }
    bool operator >= (const Point& rhs) const
    {
        return !(*this < rhs);
    }
    bool operator <= (const Point& rhs) const
    {
        return (*this < rhs || *this == rhs);
    }
    double operator * (const Vector& rhs) const //点积
    {
        return x * rhs.x + y * rhs.y;
    }
    double operator ^ (const Vector& rhs) const //叉积
    {
        return x * rhs.y - y * rhs.x;
    }

    void read()
    {
        scanf("%lf%lf",&x,&y);
    }

    void print() const
    {
        printf("(%f, %f)",x,y);
    }
};

struct Line
{
    Point a,b;  //直线（线段）的两个端点（线段的时候可把a当作起点）
    Vector v;   //方向向量，v = b - a
    //double ang;//极角
    Line() {}
    Line(Point a,Point b):a(a),b(b)
    {
        v = b - a; /*ang = atan2(v.y, v.x);*/
    }
};

typedef Line Segment;

class EndPoint
{
public:
    Point p;
    int segId,type;    //线段的ID，端点的种类
    EndPoint() {}
    EndPoint(Point p,int segId,int type):p(p),segId(segId),type(type) {}

    bool operator <(const EndPoint &ep) const   //按照y坐标的升序排序
    {
        if(p.y==ep.p.y)
            return type<ep.type;
        else
            return p.y<ep.p.y;
    }
} ep[MAXN<<1];

int manhattanIntersection(vector<Segment> seg)
{
    int sz=seg.size();
    int cnt=0;
    for(int i=0; i<sz; i++)
    {
        //调整端点a,b，保证左小右大
        if(seg[i].a.y==seg[i].b.y)
        {
            if(seg[i].a.x>seg[i].b.x)
                swap(seg[i].a,seg[i].b);
        }
        else if(seg[i].a.y>seg[i].b.y)
            swap(seg[i].a,seg[i].b);

        if(seg[i].a.y==seg[i].b.y)  //将水平线段添加至端点列表
        {
            ep[cnt++] = EndPoint(seg[i].a,i,LEFT);
            ep[cnt++] = EndPoint(seg[i].b,i,RIGHT);
        }
        else    //将垂直线段添加至端点列表
        {
            ep[cnt++] = EndPoint(seg[i].a,i,BOTTOM);
            ep[cnt++] = EndPoint(seg[i].b,i,TOP);
        }
    }

    sort(ep,ep+cnt);

    set<int> bt;
    bt.insert(1000000007);
    int ans=0;

    for(int i=0; i<cnt; i++)
    {
        if(ep[i].type==TOP)
            bt.erase(ep[i].p.x);
        else if(ep[i].type==BOTTOM)
            bt.insert(ep[i].p.x);
        else if(ep[i].type==LEFT)
        {
            set<int>::iterator l=bt.lower_bound(seg[ep[i].segId].a.x);
            set<int>::iterator r=bt.upper_bound(seg[ep[i].segId].b.x);
            ans+=distance(l,r);
        }
    }
    return ans;
}

vector<Segment> s;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        Segment tmp;
        tmp.a.read();
        tmp.b.read();
        s.PB(tmp);
    }
    int ans=manhattanIntersection(s);
    printf("%d\n",ans);
    return 0;
}
