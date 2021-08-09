/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-08
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: 模拟
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

vector<int> v[MAXN];

void init(int n)
{
    for(int i = 0; i < n; i++)
        v[i].PB(i);
}

PII getLoc(int x, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            if(v[i][j] == x)
                return MP(i, j);
        }
    }
}

void reduce(PII loc) //还原：将高于某个数的位置还原
{
    for(int i = v[loc.first].size() - 1; i > loc.second; i--)
    {
        int pos = v[loc.first][i];
        v[pos].push_back(pos);
        v[loc.first].pop_back();
    }
}

void moveaway(PII loc1, PII loc2)   //移动：将高于某个数的所有块移走
{
    int cnt = 0;
    for(int i = loc1.second; i < v[loc1.first].size(); i++)
    {
        int pos = v[loc1.first][i];
        v[loc2.first].push_back(pos);
        cnt++;
    }
    while(cnt--)
        v[loc1.first].pop_back();
}

void print(int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << i << ":";
        for(int j = 0; j < v[i].size(); j++)
            cout << " " << v[i][j];
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    init(n);
    string op1;
    while(cin >> op1)
    {
        if(op1 == "quit")
            break;
        string op2;
        int x, y;
        cin >> x >> op2 >> y;
        //cout << op1 << " + " << x << " + " << op2 << " + " << y << endl;
        PII a = getLoc(x, n);
        PII b = getLoc(y, n);
        if(a.first == b.first)
            continue;
        if(op1 == "move")
            reduce(a);  //清空a上方所有块
        if(op2 == "onto")
            reduce(b);  //清空b上方所有块
        moveaway(a, b); //把a和a上方的所有块移动到b上方
    }
    print(n);
    return 0;
}
