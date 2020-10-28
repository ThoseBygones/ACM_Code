/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 最大化平均值
 ********************************************************************************
 *  Algo-Description:
 * > 二分答案 x
 * > Sigma(v[i]) / Sigma(w[i]) >= x
 * > => Sigma(v[i]) >= x * Sigma(w[i])
 * > => Sigma(v[i]) - x * Sigma(w[i]) >= 0
 * > => Sigma(v[i] - x * w[i]) >= 0
 * > 根据 v[i] - x * w 的大小进行贪心即可
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

int n, k;

struct Jewel
{
    int v, w, id;
    double val;
    bool operator <(const Jewel &j) const
    {
        return val > j.val;
    }
} j[MAXN];

bool check(double val)  //检查实际的平均值是否满足二分得到的val值
{
    for(int i = 0; i < n; i++)
        j[i].val = (double)j[i].v - val * j[i].w;
    sort(j, j + n);
    double sum = 0.0;
    for(int i = 0; i < k; i++)
        sum += j[i].val;
    return sum >= 0.0;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &j[i].v, &j[i].w);
        j[i].id = i + 1;
    }
    double l = 0.0, r = 10000000.0;
    while(r - l >= EPS)
    {
        double mid = (l + r) / 2.0;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    for(int i = 0; i < k; i++)
        printf("%d%c", j[i].id, (i == k - 1 ? '\n' : ' '));
    return 0;
}
