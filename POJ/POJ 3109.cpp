/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-14
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 树状数组 + 扫描线
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

const int MAXN = 100005;

struct Node
{
    int x, y;
    Node() {}
    Node(int x, int y) : x(x), y(y) {}
    bool operator < (const Node &nd) const
    {
        if(x == nd.x)
            return y < nd.y;
        return x < nd.x;
    }
} p[MAXN];

int bit[MAXN];  //统计平行于x轴的水平扫描线上黑点数量
int y[MAXN];    //离散化x坐标
int ml[MAXN], mh[MAXN]; //离散化后的扫描线上最两端（最下和最上端）的点

void add(int i, int x)
{
    while(i < MAXN)   //MaxVal等于数值的最大值而不是数组的大小
    {
        bit[i] += x;
        i += lowbit(i);
    }
}

int getsum(int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &p[i].x, &p[i].y);
        y[i] = p[i].y;
    }
    sort(y + 1, y + 1 + n);
    sort(p + 1, p + 1 + n);
    int cnt = unique(y + 1, y + 1 + n) - y - 1;
    for(int i = 1; i <= n; i++)
        p[i].y = lower_bound(y + 1, y + 1 + cnt, p[i].y) - y;
    for(int i = 1; i <= n; i++)
    {
        ml[i] = INF;
        mh[i] = -INF;
    }
    for(int i = 1; i <= n; i++)
    {
        if(ml[p[i].y] == INF)   //由于x坐标已经排序，因此该扫描线上最下方的点仅初始化一次
            ml[p[i].y] = p[i].x;
        mh[p[i].y] = p[i].x;    //记录该扫描线上最上方的点
    }
    LL ans = 0;
    int i = 1;
    while(i <= n)
    {
        int l = INF, r = -INF;
        int x = p[i].x;
        int j = i;
        while(i <= n && p[i].x == x)    //x坐标相同（在同一水平扫描线上）的点
        {
            l = min(l, p[i].y);
            r = max(r, p[i].y);
            if(x == ml[p[i].y]) //利用树状数组的统计方式在最左边的值处+1
                add(p[i].y, 1);
            i++;
        }
        ans += getsum(r) - getsum(l - 1);
        while(j < i)
        {
            if(x == mh[p[j].y]) //利用树状数组的统计方式在最右边的值处-1
                add(p[j].y, -1);
            j++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

/*
7
0 1
1 0
2 1
1 2
0 4
2 4
1 5
ans: 9
*/
