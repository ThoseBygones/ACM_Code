/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm: 判断凸包
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
    bool operator < (const Point& rhs) const    //先对y排序
    {
        return dcmp(y - rhs.y) < 0 || (dcmp(y - rhs.y)==0 && dcmp(x - rhs.x) < 0);
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
        printf("%.0f %.0f\n", x, y);
    }
};

typedef vector<Point> Polygon;  //组成该平面的逆时针点集

int ConvexHull(vector<Point> &p, vector<Point> &ch)
{
    sort(p.begin(), p.end());    //两个点比大小，先横坐标再纵坐标，升序
    int n = unique(p.begin(), p.end()) - p.begin();//删除重复点
    int m = 0;
    ch.resize(n + 1);
    for(int i = 0; i < n; i++)  //找到下凸包
    {
        while(m > 1 && dcmp((ch[m - 1] - ch[m - 2]) ^ (p[i] - ch[m - 2])) < 0)
            m--;
        ch[m++] = p[i]; //发现右边的点时删除前面的点，再更新
    }
    int k = m;  //下凸包点数，找上凸包时防止误删
    for(int i = n - 2; i >= 0; i--)
    {
        while(m > k && dcmp((ch[m - 1] - ch[m - 2]) ^ (p[i] - ch[m - 2])) < 0)
            m--;
        ch[m++] = p[i];
    }
    if(n > 1)
        m--;
    ch.resize(m);
    return m;  //返回的点集逆时针排序
}

int main()
{
    Polygon poly, ans;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        Point p;
        p.read();
        poly.PB(p);
    }
    int m = ConvexHull(poly, ans);
    printf("%d\n", m);
    for(int i = 0; i < m; i++)
        ans[i].print();
    return 0;
}
