/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-02-21
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: POJ
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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};   //U,L,D,R
const char dS[4] = {'N', 'W', 'S', 'E'};
const char ds[4] = {'n', 'w', 's', 'e'};

struct Player
{
    int x, y;
    string dir;
    Player() {}
    Player(int x, int y, string dir) : x(x), y(y), dir(dir) {}
};

struct State
{
    int bx, by, px, py;
    string dir;
    State() {}
    State(int bx, int by, int px, int py, string dir) : bx(bx), by(by), px(px), py(py), dir(dir) {}
};

char ma[MAXN][MAXN];
bool visb[MAXN][MAXN], visp[MAXN][MAXN];
string ans;
int n, m;

bool check(int x, int y)
{
    if(x >= 0 && x < n && y >= 0 && y < m && ma[x][y] != '#')
        return true;
    return false;
}

bool bfs_player(int sx, int sy, int bx, int by, int ex, int ey, string &strp)
{
    memset(visp, false, sizeof(visp));
    visp[sx][sy] = true;
    visp[bx][by] = true;    //box place is unavailable
    queue<Player> q;
    q.push(Player(sx, sy, ""));
    while(!q.empty())
    {
        Player cur = q.front();
        q.pop();
        if(cur.x == ex && cur.y == ey)
        {
            strp = cur.dir;
            return true;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(check(nx, ny) && !visp[nx][ny])
            {
                visp[nx][ny] = true;
                q.push(Player(nx, ny, cur.dir + ds[i]));
            }
        }
    }
    return false;
}

bool bfs_box(int bx, int by, int px, int py)
{
    memset(visb, false, sizeof(visb));
    visb[bx][by] = true;
    queue<State> q;
    q.push(State(bx, by, px, py, ""));
    while(!q.empty())
    {
        State cur = q.front();
        q.pop();
        if(ma[cur.bx][cur.by] == 'T')
        {
            ans = cur.dir;
            return true;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.bx + dx[i], ny = cur.by + dy[i]; //next direction place
            int rx = cur.bx - dx[i], ry = cur.by - dy[i]; //reversed next direction place
            string pdir = "";
            if(check(nx, ny) && check(rx, ry) && !visb[nx][ny] && bfs_player(cur.px, cur.py, cur.bx, cur.by, rx, ry, pdir))
            {
                //printf("player: %d %d\n", px, py);
                //printf("target: %d %d\n", rx, ry);
                visb[nx][ny] = true;
                q.push(State(nx, ny, cur.bx, cur.by, cur.dir + pdir + dS[i]));
            }
        }
    }
    return false;
}

int main()
{
    int kase = 0;
    while(~scanf("%d %d", &n, &m))
    {
        if(!n && !m)
            break;
        int bx, by, px, py;
        ans = "";
        for(int i = 0; i < n; i++)
        {
            scanf("%s", ma[i]);
            for(int j = 0; j < m; j++)
            {
                if(ma[i][j] == 'B')
                    bx = i, by = j;
                if(ma[i][j] == 'S')
                    px = i, py = j;
            }
        }
        cout << "Maze #" << ++kase << endl;
        if(bfs_box(bx, by, px, py))
            cout << ans << endl;
        else
            cout << "Impossible." << endl;
        cout << endl;
    }
    return 0;
}
