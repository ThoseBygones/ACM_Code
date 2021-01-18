/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-01-18
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 威佐夫博弈
 ********************************************************************************
 *  Algo-Description:
 * > 威佐夫博弈的先手必败局面有：(0, 0), (1, 2), (3, 5), (4, 7), (6, 10), ...
 * > 威佐夫博弈中的先手必败局面特点：
 *   > 两堆的差值是递增的自然数数列：{0, 1, 2, ...}
 *   > 每个先手必败局面中，石子数量小的那一堆石子数量总是未在之前先手必败局面中出现过的最小自然数
 *   > 总结得到，每个先手必败局面石子数量小的那一堆石子数量为该局面两堆石子的数量差 * 黄金分割比（1.618...）
 * > 黄金分割比可以用 (sqrt(5.0) + 1.0) / 2.0 得到
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

int main()
{
    double g = (sqrt(5.0) + 1.0) / 2.0;   //计算黄金分割比
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        if(n > m)
            swap(n, m);
        int res = (int)(g * (m - n));
        puts(res == n ? "0" : "1");
    }
    return 0;
}
