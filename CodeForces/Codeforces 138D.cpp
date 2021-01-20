/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-01-20
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForce
 *  Algorithm: 博弈 + SG函数 + 坐标变换 + DFS
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

const int MAXN = 25;

int sg[2][MAXN << 1][MAXN << 1][MAXN << 1][MAXN << 1];  //sg[0/1][x1][y1][x2][y2]表示左上角为(x1, y1)，右下角为(x2, y2)的矩形的SG函数值
char rec[MAXN][MAXN];
int n, m;

int dfs(int x1, int y1, int x2, int y2, int flag)
{
    if(x1 > x2 || y1 > y2)
        return 0;
    if(~sg[flag][x1][y1][x2][y2])
        return sg[flag][x1][y1][x2][y2];
    bool vis[MAXN << 4] = {false};
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(((i + j) & 1) == flag)   //对应奇棋盘和偶棋盘
            {
                int x = i + j, y = i - j + m;   //坐标变换
                if(x1 <= x && x <= x2 && y1 <= y && y <= y2)
                {
                    if(rec[i][j] == 'L')    //对应于坐标变换后的矩形横着切
                        vis[dfs(x1, y1, x - 2, y2, flag) ^ dfs(x + 2, y1, x2, y2, flag)] = true;
                    if(rec[i][j] == 'R')    //对应于坐标变换后的矩形竖着切
                        vis[dfs(x1, y1, x2, y - 2, flag) ^ dfs(x1, y + 2, x2, y2, flag)] = true;
                    if(rec[i][j] == 'X')    //对应于坐标变换后的矩形十字切
                        vis[dfs(x1, y1, x - 2, y - 2, flag) ^ dfs(x + 2, y1, x2, y - 2, flag) ^ dfs(x1, y + 2, x - 2, y2, flag) ^ dfs(x + 2, y + 2, x2, y2, flag)] = true;
                }
            }
        }
    }
    for(int i = 0; ; i++)
    {
        if(!vis[i])
            return sg[flag][x1][y1][x2][y2] = i;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(sg, -1, sizeof(sg));
    for(int i = 1; i <= n; i++)
        scanf("%s", rec[i] + 1);
    if(dfs(2, 1, n + m, n + m - 1, 0) ^ dfs(3, 1, n + m, n + m - 1, 1))
        puts("WIN");
    else
        puts("LOSE");
    return 0;
}
