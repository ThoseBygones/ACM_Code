/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm: �ж�͹��
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
    bool operator < (const Point& rhs) const    //�ȶ�y����
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
        scanf("%lf%lf", &x, &y);
    }

    void print() const
    {
        printf("%.0f %.0f\n", x, y);
    }
};

typedef vector<Point> Polygon;  //��ɸ�ƽ�����ʱ��㼯

int ConvexHull(vector<Point> &p, vector<Point> &ch)
{
    sort(p.begin(), p.end());    //������ȴ�С���Ⱥ������������꣬����
    int n = unique(p.begin(), p.end()) - p.begin();//ɾ���ظ���
    int m = 0;
    ch.resize(n + 1);
    for(int i = 0; i < n; i++)  //�ҵ���͹��
    {
        while(m > 1 && dcmp((ch[m - 1] - ch[m - 2]) ^ (p[i] - ch[m - 2])) < 0)
            m--;
        ch[m++] = p[i]; //�����ұߵĵ�ʱɾ��ǰ��ĵ㣬�ٸ���
    }
    int k = m;  //��͹������������͹��ʱ��ֹ��ɾ
    for(int i = n - 2; i >= 0; i--)
    {
        while(m > k && dcmp((ch[m - 1] - ch[m - 2]) ^ (p[i] - ch[m - 2])) < 0)
            m--;
        ch[m++] = p[i];
    }
    if(n > 1)
        m--;
    ch.resize(m);
    return m;  //���صĵ㼯��ʱ������
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
