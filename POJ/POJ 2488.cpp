/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-30
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: DFS
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

const int MAXN = 30;

const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool vis[MAXN][MAXN];
PII p[MAXN];
int n, m;
bool flag;

bool inMap(int x, int y)
{
    if(x > 0 && x <= m && y > 0 && y <= n)
        return true;
    return false;
}

void dfs(int x, int y, int cnt)
{
    vis[x][y] = true;
    p[cnt] = MP(x, y);
    if(cnt == n * m)
    {
        flag = true;
        return ;
    }
    for(int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inMap(nx, ny) && ! vis[nx][ny])
            dfs(nx, ny, cnt + 1);
        if(flag)
            return ;
    }
    vis[x][y] = false;
}

int main()
{
    int t, kase = 0;
    scanf("%d", &t);
    while(t--)
    {
        if(kase)
            puts("");
        scanf("%d%d", &n, &m);
        memset(vis, false, sizeof(vis));
        flag = false;
        dfs(1, 1, 1);
        printf("Scenario #%d:\n", ++kase);
        if(flag)
        {
            for(int i = 1; i <= n * m; i++)
                printf("%c%d", p[i].first + 'A' - 1, p[i].second);
            puts("");
        }
        else
            puts("impossible");
    }
    return 0;
}
