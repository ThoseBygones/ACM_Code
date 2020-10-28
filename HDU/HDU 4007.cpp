/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-13
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: ±©Á¦ + »¬¶¯´°¿Ú
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

const int MAXN = 1005;

struct Point
{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    bool operator <(const Point &p) const
    {
        if(x == p.x)
            return y < p.y;
        return x < p.x;
    }
    void read()
    {
        scanf("%d%d", &x, &y);
    }
} p[MAXN];

int y[MAXN];

int main()
{
    int n, a;
    while(~scanf("%d%d", &n, &a))
    {
        for(int i = 0; i < n; i++)
            p[i].read();
        sort(p, p + n);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = i; j < n; j++)
            {
                if(p[i].x + a >= p[j].x)
                    y[cnt++] = p[j].y;
            }
            sort(y, y + cnt);
            int l = 0, r = 0;
            while(l < cnt)
            {
                while(y[l] + a >= y[r] && r < cnt)
                    r++;
                ans = max(ans, r - l);
                l++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
