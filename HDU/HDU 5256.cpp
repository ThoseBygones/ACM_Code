/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-07
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: dp(LIS)
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

int a[MAXN];
int dp[MAXN];

int main()
{
    int t, kase = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            a[i] -= i;
        }
        fill(dp, dp + n, INF);
        for(int i = 0; i < n; i++)
            *upper_bound(dp, dp + n, a[i]) = a[i];  //不严格单调递增，从下标开始找第一个比a[i]大的数
        int ans = lower_bound(dp, dp + n, INF) - dp;
        printf("Case #%d:\n%d\n", kase++, n - ans);
    }
    return 0;
}
