/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: ²¢²é¼¯
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

const int MAXN = 10000005;

int fa[MAXN];
int cnt[MAXN];

int findset(int x)
{
    if(x != fa[x])
        return fa[x] = findset(fa[x]);
    return fa[x];
}

void unionset(int x, int y)
{
    int fx = findset(x);
    int fy = findset(y);
    if(fx != fy)
    {
        fa[fx] = fa[fy];
        cnt[fy] += cnt[fx];
    }
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < MAXN; i++)
        {
            fa[i] = i;
            cnt[i] = 1;
        }
        for(int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            unionset(x, y);
        }
        int ans = 0;
        for(int i = 1; i < MAXN; i++)
        {
            if(fa[i] == i)
                ans = max(ans, cnt[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
