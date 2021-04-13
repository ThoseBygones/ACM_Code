/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-13
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 线段树 + 离散化 + 扫描线
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

const int MAXN = 2010;

int cov[MAXN << 3]; //MAXN = 2020时开4倍数组会WA
double x[MAXN];
double sum[MAXN << 3][2];

struct ScanLine
{
    double l, r, h;
    int flag;
    ScanLine() {}
    ScanLine(double l, double r, double h, int flag) : l(l), r(r), h(h), flag(flag) {}
    bool operator < (const ScanLine &l) const
    {
        return h < l.h;
    }
} sl[MAXN];

void pushUp(int l, int r, int rt)
{
    if(cov[rt]) //线段有被覆盖至少一次
    {
        sum[rt][0] = x[r + 1] - x[l];
        if(cov[rt] > 1)    //若不止被覆盖一次，则全部加上
            sum[rt][1] = sum[rt][0];
        else    //线段只被覆盖一次，则加上之前子孙结点被覆盖一次的长度
            sum[rt][1] = sum[rt << 1][0] + sum[rt << 1 | 1][0];
    }
    else if(l == r)
        sum[rt][0] = sum[rt][1] = 0;
    else
    {
        sum[rt][0] = sum[rt << 1][0] + sum[rt << 1 | 1][0];
        sum[rt][1] = sum[rt << 1][1] + sum[rt << 1 | 1][1];
    }
}

void update(int val, int L, int R, int l, int r, int rt)
{
    if(L <= l && r <= R)
    {
        cov[rt] += val;
        pushUp(l, r, rt);
        return ;
    }
    int mid = (l + r) >> 1;
    if(L <= mid)
        update(val, L, R, lson);
    if(R > mid)
        update(val, L, R, rson);
    pushUp(l, r, rt);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            x[++cnt] = x1;
            sl[cnt] = ScanLine(x1, x2, y1, 1);
            x[++cnt] = x2;
            sl[cnt] = ScanLine(x1, x2, y2, -1);
        }
        sort(x + 1, x + 1 + cnt);
        sort(sl + 1, sl + 1 + cnt);
        int m = unique(x + 1, x + 1 + cnt) - x - 1;   //离散化
        memset(cov, 0, sizeof(cov));
        memset(sum, 0, sizeof(sum));
        double ans = 0.0;
        for(int i = 1; i < cnt; i++)
        {
            int l = lower_bound(x + 1, x + 1 + m, sl[i].l) - x;
            int r = lower_bound(x + 1, x + 1 + m, sl[i].r) - x - 1;
            update(sl[i].flag, l, r, 1, m, 1);
            ans += sum[1][1] * (sl[i + 1].h - sl[i].h);
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
