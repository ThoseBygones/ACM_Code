/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-30
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 线段相交判定
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
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
        scanf(" (%lf,%lf)",&x,&y);
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

bool OnSegment(Point &p,Segment& S)
{
    //小于0不包含端点，小于等于包含端点
    return dcmp((S.a-p)^(S.b-p)) == 0 && dcmp((S.a-p)*(S.b-p)) <= 0;
}

bool SegmentProperIntersect(Segment &s1,Segment& s2)
{
    Type c1 = (s1.b - s1.a) ^ (s2.a - s1.a), c2 = (s1.b - s1.a) ^ (s2.b - s1.a),
         c3 = (s2.b - s2.a) ^ (s1.a - s2.a), c4 = (s2.b - s2.a) ^ (s1.b - s2.a);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

bool SegmentNotProperIntersect(Segment& s1,Segment& s2)
{
    return OnSegment(s1.a,s2) || OnSegment(s1.b,s2) || OnSegment(s2.a,s1) || OnSegment(s2.b,s1);
}

struct Shape
{
    char id[2],type[10];
    int cnt;
    Point p[25];
} shape[30];

int kase;

void init()
{
    scanf("%s",shape[kase].type);
    char tmp=shape[kase].type[0];
    if(tmp=='l')    //直线
    {
        shape[kase].cnt=2;
        for(int i=0; i<2; i++)
            shape[kase].p[i].read();
    }
    else if(tmp=='t')   //三角形
    {
        shape[kase].cnt=3;
        for(int i=0; i<3; i++)
            shape[kase].p[i].read();
    }
    else if(tmp=='s')   //正方形
    {
        shape[kase].cnt=4;
        for(int i=0; i<4; i+=2)
            shape[kase].p[i].read();
        shape[kase].p[1].x=(shape[kase].p[0].x+shape[kase].p[2].x-shape[kase].p[0].y+shape[kase].p[2].y)/2.0;
        shape[kase].p[3].x=(shape[kase].p[0].x+shape[kase].p[2].x+shape[kase].p[0].y-shape[kase].p[2].y)/2.0;
        shape[kase].p[1].y=(shape[kase].p[0].x-shape[kase].p[2].x+shape[kase].p[0].y+shape[kase].p[2].y)/2.0;
        shape[kase].p[3].y=(-shape[kase].p[0].x+shape[kase].p[2].x+shape[kase].p[0].y+shape[kase].p[2].y)/2.0;
    }
    else if(tmp=='r')   //矩形
    {
        shape[kase].cnt=4;
        for(int i=0; i<3; i++)
            shape[kase].p[i].read();
        shape[kase].p[3].x=shape[kase].p[0].x+shape[kase].p[2].x-shape[kase].p[1].x;
        shape[kase].p[3].y=shape[kase].p[0].y+shape[kase].p[2].y-shape[kase].p[1].y;
    }
    else if(tmp=='p')   //多边形
    {
        int n;
        scanf("%d",&n);
        shape[kase].cnt=n;
        for(int i=0; i<n; i++)
            shape[kase].p[i].read();
    }
    kase++;
}

bool cmp(Shape x,Shape y)
{
    return x.id[0]<y.id[0];
}

vector <int> ans[30];

int main()
{
    kase=0;
    while(~scanf("%s",shape[kase].id))
    {
        if(shape[kase].id[0]=='.')
            break;
        init();
        while(~scanf("%s",shape[kase].id))
        {
            if(shape[kase].id[0]=='-')
                break;
            init();
        }
        sort(shape,shape+kase,cmp);
        for(int i=0; i<30; i++)
            ans[i].clear();
        for(int i=0; i<kase; i++)
        {
            for(int j=0; j<kase; j++)
            {
                if(i==j)
                    continue;
                for(int k=0; k<shape[i].cnt; k++)
                {
                    bool flag=false;
                    for(int l=0; l<shape[j].cnt; l++)
                    {
                        Segment s1(shape[i].p[k%shape[i].cnt],shape[i].p[(k+1)%shape[i].cnt]);
                        Segment s2(shape[j].p[l%shape[j].cnt],shape[j].p[(l+1)%shape[j].cnt]);
                        //s1.a.print();
                        //s2.b.print();
                        if(SegmentProperIntersect(s1,s2) || SegmentNotProperIntersect(s1,s2))
                        {
                            flag=true;
                            ans[i].PB(j);
                            break;
                        }
                    }
                    if(flag)
                    break;
                }
            }
        }
        for(int i=0; i<kase; i++)
        {
            printf("%c ",shape[i].id[0]);
            int sz=ans[i].size();
            if(!sz)
                printf("has no intersections\n");
            else if(sz==1)
                printf("intersects with %c\n",shape[ans[i][0]].id[0]);
            else if(sz==2)
                printf("intersects with %c and %c\n",shape[ans[i][0]].id[0],shape[ans[i][1]].id[0]);
            else
            {
                printf("intersects with ");
                for(int j=0; j<sz-1; j++)
                    printf("%c, ",shape[ans[i][j]].id[0]);
                printf("and %c\n",shape[ans[i][sz-1]].id[0]);
            }
        }
        puts("");
        kase=0;
    }
    return 0;
}
