/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 二分求第k大值
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

LL n, m;

LL getVal(LL i, LL j)
{
    return sqr(i) + 1LL * 100000 * i + sqr(j) - 1LL * 100000 * j + i * j;
}

bool check(LL val)
{
    LL cnt = 0;
    for(LL j = 1; j <= n; j++) //枚举每一列
    {
        LL l = 1, r = n;
        LL ans = 0;
        while(l <= r)   //二分求每一列符合要求值的数量
        {
            LL mid = (l + r) / 2;
            if(getVal(mid, j) <= val)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cnt += ans;
    }
    return cnt >= m;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld%lld", &n, &m);
        LL l = -1 * 100000 * n, r = (n + 100000) * n;
        LL ans = 0;
        while(l <= r)   //对于每一列，i的值单调递增，对第k大值进行二分
        {
            LL mid = (l + r) / 2;
            if(check(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
