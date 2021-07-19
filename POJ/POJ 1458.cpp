/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 线性dp（最长公共子序列LCS）
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

char a[MAXN], b[MAXN];
int dp[MAXN][MAXN]; //dp[i][j]表示序列a[1...i]和b[1...j]的最长公共子序列

int main()
{
    while(~scanf("%s%s", a + 1, b + 1))
    {
        //memset(dp, 0, sizeof(dp));
        int n = strlen(a + 1);
        int m = strlen(b + 1);
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for(int j = 0; j <= m; j++)
            dp[0][j] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a[i] == b[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
