/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 线性dp
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

/*int a[MAXN][MAXN];
int dp[MAXN][MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[n][i]);
    printf("%d\n", ans);
    return 0;
}*/

int a[MAXN][MAXN];
int dp[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j; j--)
            dp[j] = max(dp[j], dp[j - 1]) + a[i][j];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}
