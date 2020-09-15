/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-13
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm:
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

LL a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];

int main()
{
    int n, m, l;
    scanf("%d%d%d", &n, &m, &l);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            scanf("%lld", &a[i][j]);
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < l; j++)
            scanf("%lld", &b[i][j]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < l; k++)
        {
            for(int j = 0; j < m; j++)
                c[i][k] += a[i][j] * b[j][k];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < l; j++)
            printf("%lld%c", c[i][j], (j == l - 1 ? '\n' : ' '));
    }
    return 0;
}
