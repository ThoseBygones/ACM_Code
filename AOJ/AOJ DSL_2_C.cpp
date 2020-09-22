/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-22
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm: kd树范围查找
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

const int MAXN = 500005;

struct Node
{
    int id;
    int p, l, r;
    Node() {}
    Node(int id, int p, int l, int r) : id(id), p(p), l(l), r(r) {}
} tr[MAXN];

struct Point
{
    int id, x, y;
    Point() {}
    Point(int id, int x, int y) : id(id), x(x), y(y) {}
    bool operator < (const Point &p) const
    {
        return id < p.id;
    }
    void read()
    {
        scanf("%d%d", &x, &y);
    }
    void print()
    {
        printf("%d\n", id);
    }
} p[MAXN];

vector<Point> ans;
int n, dfs_clock;

bool cmpX(Point p1, Point p2)
{
    return p1.x < p2.x;
}

bool cmpY(Point p1, Point p2)
{
    return p1.y < p2.y;
}

int build(int l, int r, int dep)    //建树（右边界不取）
{
    if(l >= r)
        return -1;
    int mid = (l + r) >> 1;
    int rt = dfs_clock++;
    if(dep & 1) //奇数时对x轴排序
        sort(p + l, p + r, cmpX);
    else
        sort(p + l, p + r, cmpY);
    tr[rt].id = mid;
    tr[rt].l = build(l, mid, dep + 1);
    tr[rt].r = build(mid + 1, r, dep + 1);
    return rt;
}

void searchRange(int lx, int rx, int ly, int ry, int rt, int dep)
{
    int x = p[tr[rt].id].x;
    int y = p[tr[rt].id].y;
    if(lx <= x && x <= rx && ly <= y && y <= ry)
        ans.PB(p[tr[rt].id]);
    if(dep & 1) //查找x轴
    {
        if(~tr[rt].l && lx <= x)
            searchRange(lx, rx, ly, ry, tr[rt].l, dep + 1);
        if(~tr[rt].r && x <= rx)
            searchRange(lx, rx, ly, ry, tr[rt].r, dep + 1);
    }
    else    //查找y轴
    {
        if(~tr[rt].l && ly <= y)
            searchRange(lx, rx, ly, ry, tr[rt].l, dep + 1);
        if(~tr[rt].r && y <= ry)
            searchRange(lx, rx, ly, ry, tr[rt].r, dep + 1);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        p[i].read();
        p[i].id = i;
        tr[i] = Node(0, -1, -1, -1);
    }
    dfs_clock = 0;
    build(0, n, 0);
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int sx, tx, sy, ty;
        scanf("%d%d%d%d", &sx, &tx, &sy, &ty);
        ans.clear();
        searchRange(sx, tx, sy, ty, 0, 0);
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
            ans[i].print();
        puts("");
    }
    return 0;
}
