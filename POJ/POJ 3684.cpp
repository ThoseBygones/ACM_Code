/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-29
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 数学计算
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

const int MAXN = 105;
const double g = 10.0;

double ans[MAXN];
int n;
double h, r, t;

double cal(int val)
{
    if(val < 0)
        return h;
    double tt = sqrt(2 * h / g);    //一次下落的用时
    int times = (int)(val / tt);    //下落次数
    double t1;
    if(times & 1)  //接触地面后反弹向上
        t1 = tt * (times + 1) - val;
    else
        t1 = val - times * tt;
    return h - g * t1 * t1 / 2.0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%lf%lf%lf", &n, &h, &r, &t);
        for(int i = 0; i < n; i++)
            ans[i] = cal(t - i);
        sort(ans, ans + n);
        for(int i = 0; i < n; i++)
            printf("%.2f%c", ans[i] + 2.0 * r * i / 100.0, (i == n - 1 ? '\n' : ' '));
    }
    return 0;
}
