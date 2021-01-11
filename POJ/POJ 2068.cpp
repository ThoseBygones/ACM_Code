/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-01-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 博弈论
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

const int MAXN = 25;

int a[MAXN];
int dp[MAXN][(1 << 13) + 5];    //dp[i][j]表示轮到第i个人取，还剩下j个石头时能否取胜
int n;

int dfs(int i, int j)
{
    if(!j)
        return dp[i][j] = 1;
    if(~dp[i][j])
        return dp[i][j];
    for(int k = 1; k <= a[i] && k <= j; k++)    //枚举自己的取法
    {
        if(!dfs((i + 1) % (2 * n), j - k))  //下一个人存在一种必败的取法
            return dp[i][j] = 1;
    }
    return dp[i][j] = 0;
}

int main()
{
    while(~scanf("%d", &n), n)
    {
        int s;
        scanf("%d", &s);
        for(int i = 0; i < 2 * n; i++)
            scanf("%d", &a[i]);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", dfs(0, s));
    }
    return 0;
}
