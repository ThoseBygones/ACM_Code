/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm: �жϵ���͹��λ�ù�ϵ
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

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
//#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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

//��Ķ���
struct Point
{
    Type x, y;
    //int belong;   //������һ��Բ
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
    double operator * (const Vector& rhs) const //���
    {
        return x * rhs.x + y * rhs.y;
    }
    double operator ^ (const Vector& rhs) const //���
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
    Point a,b;  //ֱ�ߣ��߶Σ��������˵㣨�߶ε�ʱ��ɰ�a������㣩
    Vector v;   //����������v = b - a
    //double ang;//����
    Line() {}
    Line(Point a,Point b):a(a),b(b)
    {
        v = b - a; /*ang = atan2(v.y, v.x);*/
    }
};

typedef Line Segment;

bool OnSegment(Point &p,Segment& S)
{
    //С��0�������˵㣬С�ڵ��ڰ����˵�
    return dcmp((S.a-p)^(S.b-p)) == 0 && dcmp((S.a-p)*(S.b-p)) <= 0;
}

typedef vector<Point> Polygon;  //��ɸ�ƽ�����ʱ��㼯

int isPointInPolygon(Point p, Polygon &poly)
{
    int wn = 0;
    int n = poly.size();
    for(int i = 0; i < n; i++)
    {
        Segment seg(poly[i], poly[(i + 1) % n]);
        if(OnSegment(p, seg))
            return 1;  //�ڶ���α߽���
        int k = dcmp((poly[(i + 1) % n] - poly[i]) ^ (p - poly[i]));
        int d1 = dcmp(poly[i].y - p.y);
        int d2 = dcmp(poly[(i + 1) % n].y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0)
            wn++;
        if(k < 0 && d2 <= 0 && d1 > 0)
            wn--;
    }
    if(wn)
        return 2;   //�ڶ�����ڲ�
    return 0;   //�ڶ�����ⲿ
}

int main()
{
    Polygon poly;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        Point p;
        p.read();
        poly.PB(p);
    }
    int q;
    scanf("%d", &q);
    while(q--)
    {
        Point p;
        p.read();
        printf("%d\n", isPointInPolygon(p, poly));
    }
    return 0;
}
