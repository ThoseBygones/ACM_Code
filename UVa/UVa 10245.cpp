/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: 分治法求平面最近点对
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define Vector Point

typedef double Type;

const int MAXN = 10005;

inline int dcmp(double x)
{
    return (x > EPS) - (x < -EPS);
}

//点的定义
struct Point
{
    Type x, y;
    //int belong;   //属于哪一个圆
    Point(Type x = 0, Type y = 0) : x(x), y(y) {}

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
        scanf("%lf%lf", &x, &y);
    }

    void print() const
    {
        printf("(%f, %f)", x, y);
    }
};

Type Length(Point p1,Point p2)
{
    Type x = p1.x - p2.x, y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}


Point p[MAXN];
int tmp[MAXN];

bool cmp(Point a, Point b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool cmpy(int idxa, int idxb)
{
    return p[idxa].y < p[idxb].y;
}

double closestPair(int left, int right)
{
    double d = INF;
    if(left == right)
        return d;
    if(left + 1 == right)
        return Length(p[left], p[right]);
    int mid = (left + right) >> 1;
    double d1 = closestPair(left, mid);
    double d2 = closestPair(mid + 1, right);
    d = min(d1, d2);
    int k = 0;
    //分离出宽度为d的区间
    for(int i = left; i <= right; i++)
    {
        if(fabs(p[mid].x - p[i].x) <= d)
            tmp[k++] = i;
    }
    sort(tmp, tmp + k, cmpy);
    //线性扫描
    for(int i = 0; i < k; i++)
    {
        for(int j = i + 1; j < k && p[tmp[j]].y - p[tmp[i]].y < d; j++)
        {
            double d3 = Length(p[tmp[i]], p[tmp[j]]);
            if(d > d3)
                d = d3;
        }
    }
    return d;
}

int main()
{
    int n;
    while(~scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i++)
            p[i].read();
        sort(p, p + n, cmp);
        double ans = closestPair(0, n - 1);
        if(ans >= 10000.0)
            puts("INFINITY");
        else
            printf("%.4f\n", ans);
    }
    return 0;
}

/*
3
0 0
10000 10000
20000 20000
5
0 2
6 67
43 71
39 107
189 140
0

ans:
INFINITY
36.2215
*/
