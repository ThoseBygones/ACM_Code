/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-22
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm: 离散化
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

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int xa[MAXN], xb[MAXN], ya[MAXN], yb[MAXN];
int G[MAXN * 3][MAXN * 3];
int n;

bool inRange(int x, int m)
{
    if(x > 0 && x <= m)
        return true;
    return false;
}

int discrete(int a1[], int a2[], int m)
{
    int cnt = 0;
    int Hash[MAXN * 3];
    for(int i = 0; i < n; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int p1 = a1[i] + j;
            int p2 = a2[i] + j;
            if(inRange(p1, m))
                Hash[++cnt] = p1;
            if(inRange(p2, m))
                Hash[++cnt] = p2;
        }
    }
    sort(Hash + 1, Hash + 1 + cnt);
    cnt = unique(Hash + 1, Hash + 1 + cnt) - Hash - 1;
    for(int i = 0; i < n; i++)
    {
        a1[i] = lower_bound(Hash + 1, Hash + 1 + cnt, a1[i]) - Hash - 1;
        a2[i] = lower_bound(Hash + 1, Hash + 1 + cnt, a2[i]) - Hash - 1;
    }
    return cnt;
}

bool inMap(int x, int y, int w, int h)
{
    if(x >= 0 && x < w && y >= 0 && y < h)
        return true;
    return false;
}

int main()
{
    int w, h;
    while(~scanf("%d%d", &w, &h))
    {
        if(!w && !h)
            break;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d", &xa[i], &ya[i], &xb[i], &yb[i]);
            xa[i]++, ya[i]++;   //直线的左端点+1（一条胶带的一段与另一条胶带的一段相邻不等于相接，因为这两条胶带可能不在一条直线上）
        }
        w = discrete(xa, xb, w);
        h = discrete(ya, yb, h);
        memset(G, 0, sizeof(G));
        for(int i = 0; i < n; i++)
        {
            for(int x = xa[i]; x <= xb[i]; x++)
            {
                for(int y = ya[i]; y <= yb[i]; y++)
                    G[x][y] = 1;
            }
        }
        int cnt = 0;
        for(int x = 0; x < w; x++)
        {
            for(int y = 0; y < h; y++)
            {
                if(!G[x][y])
                {
                    G[x][y] = 1;
                    cnt++;
                    queue<PII> q;
                    q.push(MP(x, y));
                    while(!q.empty())
                    {
                        PII tmp = q.front();
                        q.pop();
                        for(int i = 0; i < 4; i++)
                        {
                            int nx = tmp.first + dx[i];
                            int ny = tmp.second + dy[i];
                            if(inMap(nx, ny, w, h) && !G[nx][ny])
                            {
                                G[nx][ny] = 1;
                                q.push(MP(nx, ny));
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

