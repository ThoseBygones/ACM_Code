/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-18
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: dp（分组背包问题）
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

int a[MAXN];
int dp[MAXN];   //dp[j]表示前i门课在花费天数为j时的最大收益

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        if(!n && !m)
            break;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) //枚举课程
        {
            for(int j = 1; j <= m; j++) //枚举天数
                scanf("%d", &a[j]);
            for(int j = m; j; j--)  //枚举背包空间
            {
                for(int k = 1; k <= j; k++) //枚举该课程学习的天数
                    dp[j] = max(dp[j], dp[j - k] + a[k]);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
