/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-01-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: Nim 博弈 + SG 函数
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

const int MAXN = 205;

int sg[MAXN][MAXN];
int vis[(1 << 8) + 5];

void init()
{
    memset(sg, -1, sizeof(sg));
    sg[2][2] = 0;
}

int solve(int n, int m)
{
    if(~sg[n][m])
        return sg[n][m];
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i <= n / 2; i++) //横着剪
    {
        int x = solve(i, m);    //前一半
        int y = solve(n - i, m);    //后一半
        vis[x ^ y] = 1;
    }
    for(int i = 2; i <= m / 2; i++) //竖着剪
    {
        int x = solve(n, i);    //前一半
        int y = solve(n, m - i);    //后一半
        vis[x ^ y] = 1;
    }
    for(int i = 0; i <= (1 << 8); i++)
    {
        if(!vis[i])
            return sg[n][m] = i;
    }
}

int main()
{
    init();
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        if(!solve(n, m))
            puts("LOSE");
        else
            puts("WIN");
    }
    return 0;
}
