/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 树状数组
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

const int MAXN = 20005;

struct Cow
{
    int v, x;
    bool operator < (const Cow &c) const
    {
        return v < c.v;
    }
} cow[MAXN];

LL bitcnt[MAXN], bitsum[MAXN];
int m;

void add(LL bit[], int i, int x)
{
    while(i <= m)   //MaxVal等于数值的最大值而不是数组的大小
    {
        bit[i] += x;
        i += lowbit(i);
    }
}

LL getsum(LL bit[], int i)
{
    LL sum = 0;
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
        scanf("%d%d", &cow[i].v, &cow[i].x);
        m = max(m, cow[i].x);
    }
    sort(cow + 1, cow + 1 + n);
    LL ans = 0;
    LL xsum = 0;    //当前所有被插入树状数组中的奶牛的坐标和
    for(int i = 1; i <= n; i++)
    {
        LL cnt = getsum(bitcnt, cow[i].x);
        LL sum = getsum(bitsum, cow[i].x);
        LL lsum = cnt * cow[i].x - sum;   //该奶牛与左侧所有音量比它小的奶牛交流需要的花费总和
        LL rsum = xsum - sum - ((LL)i - cnt - 1) * cow[i].x;  //该奶牛与右侧所有音量比它小的奶牛交流需要的花费总和（该奶牛左侧所有被重复计算过的奶牛应该去除）
        //printf("%lld - %lld\n", lsum, rsum);
        xsum += cow[i].x;
        ans += (lsum + rsum) * cow[i].v;
        add(bitcnt, cow[i].x, 1);
        add(bitsum, cow[i].x, cow[i].x);
    }
    printf("%lld\n", ans);
    return 0;
}
