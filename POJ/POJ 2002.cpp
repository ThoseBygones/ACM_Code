/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-02-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 哈希
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
const int MOD = 10007;

struct Point
{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
} p[MAXN];

struct HashNode
{
    int x, y, nxt;
    HashNode() {}
    HashNode(int x, int y, int nxt) : x(x), y(y), nxt(nxt) {}
} Hash[MAXN];

int head[MOD];
int cnt;

void init()
{
    cnt = 0;
    for(int i = 0; i < MOD; i++)
        head[i] = -1;
}

void addHash(Point p)
{
    int key = (p.x * p.x + p.y * p.y) % MOD;    //829ms
    //int key = abs(p.x + p.y) % MOD;   //1438ms
    Hash[cnt].x = p.x;
    Hash[cnt].y = p.y;
    Hash[cnt].nxt = head[key];
    head[key] = cnt++;
}

bool findKey(Point p)
{
    int key = (p.x * p.x + p.y * p.y) % MOD;
    //int key = abs(p.x + p.y) % MOD;
    int cur = head[key];
    while(~cur)
    {
        if(Hash[cur].x == p.x && Hash[cur].y == p.y)
            return true;
        cur = Hash[cur].nxt;
    }
    return false;
}

int main()
{
    int n;
    while(~scanf("%d", &n), n)
    {
        init();
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
            addHash(p[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                Point p1 = Point(p[i].x + p[i].y - p[j].y, p[i].y - p[i].x + p[j].x);
                Point p2 = Point(p[j].x + p[i].y - p[j].y, p[j].y - p[i].x + p[j].x);
                if(findKey(p1) && findKey(p2))
                    ans++;
                Point p3 = Point(p[i].x - p[i].y + p[j].y, p[i].y + p[i].x - p[j].x);
                Point p4 = Point(p[j].x - p[i].y + p[j].y, p[j].y + p[i].x - p[j].x);
                if(findKey(p3) && findKey(p4))
                    ans++;
            }
        }
        printf("%d\n", ans / 4);
    }
    return 0;
}
