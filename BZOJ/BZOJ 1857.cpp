/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-30
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: BZOJ
 *  Algorithm: 三分套三分
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

typedef double Type;

struct Point
{
    Type x, y;
    Point(Type x=0,Type y=0):x(x),y(y) {}
    void read()
    {
        scanf("%lf%lf",&x,&y);
    }
};

double P,Q,R;

//距离
Type Length(Point p1,Point p2)
{
    Type x = p1.x - p2.x, y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}

Point getMidPoint(Point l,Point r)
{
    return Point((l.x+r.x)/2.0,(l.y+r.y)/2.0);
}

double ternarySearch(Point p,Point c,Point d)
{
    Point l = c, r = d;
    double tmp1 = Length(p,l) / R + Length(l,d) / Q, tmp2;
    while(Length(l,r) >= EPS)
    {
        Point lmid = getMidPoint(l,r);
        Point rmid = getMidPoint(lmid,r);
        tmp1 = Length(p,lmid) / R + Length(lmid,d) / Q;
        tmp2 = Length(p,rmid) / R + Length(rmid,d) / Q;
        if(tmp1 > tmp2)
            l = lmid;
        else
            r = rmid;
    }
    return tmp1;
}

int main()
{
    Point a,b,c,d;
    a.read();
    b.read();
    c.read();
    d.read();
    scanf("%lf%lf%lf",&P,&Q,&R);
    Point l = a, r = b;
    double tmp1=Length(a,l) / P + ternarySearch(l,c,d), tmp2;
    while(Length(l,r) >= EPS)
    {
        Point lmid = getMidPoint(l,r);
        Point rmid = getMidPoint(lmid,r);
        tmp1 = Length(a,lmid) / P + ternarySearch(lmid,c,d);
        tmp2 = Length(a,rmid) / P + ternarySearch(rmid,c,d);
        if(tmp1 > tmp2)
            l = lmid;
        else
            r = rmid;
    }
    printf("%.2f\n",tmp1);
    return 0;
}
