/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-21
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

/* IDA* 算法*/

const int dx[4] = {-1, 1, 0, 0};    //上下左右
const int dy[4] = {0, 0, -1, 1};    //上下左右

int pz[16];
int md[16][16];
int sum;
int ans = 45;

void init()
{
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 16; j++)
            md[i][j] = abs(i / 4 - j / 4) + abs(i % 4 - j % 4);
    }
    /*for(int i = 0; i < 16; i++)
        cout << pz[i] << endl;
    for(int i = 0; i < 16; i++)
    {
        if(i % 4 == 3)
            printf("%d\n", md[pz[i]][i]);
        else
            printf("%d ", md[pz[i]][i]);
    }*/
}

bool inPuzzle(int x, int y)
{
    if(x >= 0 && x < 4 && y >= 0 && y < 4)
        return true;
    return false;
}

bool check(int val) //检查操作的次数已经大于计划的步数
{
    if(sum == 0 && ans > val)
        ans = val;
    return val + sum < ans;
}

void dfs(int step, int x, int y, int dir)
{
    for(int i = 0; i < 4; i++)  //枚举下一步的四个方向
    {
        if((i ^ 1) != dir)  //不是反方向
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //printf("(%d, %d)\n", nx, ny);
            if(inPuzzle(nx, ny))
            {
                sum -= md[pz[nx * 4 + ny]][nx * 4 + ny];
                swap(pz[x * 4 + y], pz[nx * 4 + ny]);   //交换相邻两个块并重新计算距离
                sum += md[pz[x * 4 + y]][x * 4 + y];
                //cout << sum << endl;
                if(check(step + 1))
                    dfs(step + 1, nx, ny, i);
                sum -= md[pz[x * 4 + y]][x * 4 + y];
                swap(pz[x * 4 + y], pz[nx * 4 + ny]);   //还原两个块并重新计算距离
                sum += md[pz[nx * 4 + ny]][nx * 4 + ny];
            }
        }
    }
}

int main()
{
    for(int i = 0; i < 16; i++)
    {
        scanf("%d", &pz[i]);
        pz[i]--;
    }
    init();
    sum = 0;
    for(int i = 0; i < 16; i++) //求出每个块到目标位置的曼哈顿距离和
    {
        if(~pz[i])
            sum += md[pz[i]][i];
    }
    int x = -1, y = -1;
    for(int i = 0; i < 16; i++)
    {
        if(pz[i] == -1)
        {
            x = i / 4;
            y = i % 4;
        }
    }
    check(0);
    dfs(0, x, y, -1);
    printf("%d\n", ans);
    return 0;
}


/* A*算法 */

const int dx[4] = {-1, 1, 0, 0};    //上下左右
const int dy[4] = {0, 0, -1, 1};    //上下左右

int md[16][16];

struct Puzzle
{
    int m[16], space, sumd, step;
    bool operator < (const Puzzle &p) const
    {
        for(int i = 0; i < 16; i++)
        {
            if(m[i] != p.m[i])
                return m[i] < p.m[i];
        }
        return false;
    }
};

struct State
{
    Puzzle p;
    int est;    //估计的距离限制
    State() {}
    State(Puzzle p, int est) : p(p), est(est) {}
    bool operator < (const State &s) const
    {
        return est > s.est;
    }
};

void init()
{
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 16; j++)
            md[i][j] = abs(i / 4 - j / 4) + abs(i % 4 - j % 4);
    }
}

int getMDSum(Puzzle pz)
{
    int sum = 0;
    for(int i = 0; i < 16; i++) //求出每个块到目标位置的曼哈顿距离和
    {
        if(~pz.m[i])
            sum += md[pz.m[i]][i];
    }
    return sum;
}

bool inPuzzle(int x, int y)
{
    if(x >= 0 && x < 4 && y >= 0 && y < 4)
        return true;
    return false;
}

int astar(Puzzle pz)
{
    priority_queue<State> pq;
    pz.sumd = getMDSum(pz);
    pz.step = 0;
    map<Puzzle, bool> vis;
    State s = State(pz, getMDSum(pz));
    pq.push(s);
    while(!pq.empty())
    {
        s = pq.top();
        pq.pop();
        Puzzle cur = s.p;
        if(cur.sumd == 0)
            return cur.step;
        vis[cur] = true;
        int x = cur.space / 4;
        int y = cur.space % 4;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(inPuzzle(nx, ny))
            {
                Puzzle nxt = cur;
                nxt.sumd -= md[nxt.m[nx * 4 + ny]][nx * 4 + ny];
                swap(nxt.m[x * 4 + y], nxt.m[nx * 4 + ny]);
                nxt.sumd += md[nxt.m[x * 4 + y]][x * 4 + y];
                nxt.space = nx * 4 + ny;
                if(!vis[nxt])
                {
                    nxt.step++;
                    State ns = State(nxt, nxt.step + nxt.sumd);
                    pq.push(ns);
                }
            }
        }
    }
    return 45;
}

int main()
{
    init();
    Puzzle pz;
    for(int i = 0; i < 16; i++)
    {
        scanf("%d", &pz.m[i]);
        pz.m[i]--;
        if(pz.m[i] == -1)
            pz.space = i;
    }
    /*for(int i = 0; i < 16; i++)
    {
        if(i % 4 == 3)
            printf("%d\n", md[pz.m[i]][i]);
        else
            printf("%d ", md[pz.m[i]][i]);
    }*/
    printf("%d\n", astar(pz));
}
