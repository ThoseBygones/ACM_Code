/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-16
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

template<class T> inline T sqr(T x)
{
    return x * x;
}
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

const int MAXN = 1405;

int a[MAXN][MAXN];
int h[MAXN];
int ll[MAXN], rr[MAXN];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    }
    for(int i = 1; i <= m; i++)
    {
        ll[i] = 1;
        rr[i] = m;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int l = 1, r = m;
        for(int j = 1; j <= m; j++)
        {
            if(!a[i][j])
                h[j]++;
            else
                h[j] = 0;
        }
        for(int j = 1; j <= m; j++) //更新左边
        {
            if(!a[i][j])
                ll[j] = max(ll[j], l);  //记录当前连续段的左边界
            else
            {
                l = j + 1;
                ll[j] = 1;
            }
        }
        for(int j = m; j; j--) //更新右边
        {
            if(!a[i][j])
                rr[j] = min(rr[j], r);  //记录当前连续段的右边界
            else
            {
                r = j - 1;
                rr[j] = m;
            }
        }
        for(int j = 1; j <= m; j++)
            ans = max(ans, h[j] * (rr[j] - ll[j] + 1));
    }
    printf("%d\n", ans);
    return 0;
}
