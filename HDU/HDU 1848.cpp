/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-01-18
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: SGº¯Êý
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

int sg[MAXN];
bool vis[MAXN];
int fib[25];

void init()
{
    fib[1] = 1;
    fib[2] = 2;
    for(int i = 3; i < 25; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        if(fib[i] > 1000)
            break;
    }
    for(int i = 0; i <= 1000; i++)
    {
        //sg[i] = i;
        memset(vis, false, sizeof(vis));
        for(int j = 1; fib[j] <= i; j++)
        {
            vis[sg[i - fib[j]]] = true;
            for(int k = 0; k <= i; k++)
            {
                if(!vis[k])
                {
                    sg[i] = k;
                    break;
                }
            }
        }
    }
}

int main()
{
    init();
    int n, m, p;
    while(~scanf("%d%d%d", &n, &m, &p))
    {
        if(!n && !m && !p)
            break;
        if(sg[n] ^ sg[m] ^ sg[p])
            puts("Fibo");
        else
            puts("Nacci");
    }
    return 0;
}
