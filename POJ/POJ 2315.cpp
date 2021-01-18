/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-01-18
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: Nimk博弈 + SG函数
 ********************************************************************************
 *  Algo-Description:
 * > Nimk博弈：每次可以选m堆石子取一定数量的石子，则累加每堆石子的二进制的每一位
 *   > 如果所有 mod (d + 1) == 0，则先手必败；
 *   > 否则先手必胜。
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

const int MAXN = 35;

int a[MAXN];
int sg[MAXN];
int n, m, l, r;

int getDis(int x)
{
    return (int)(1.0 * x / (2.0 * PI * r)) + 1;
}

bool check()
{
    for(int i = 0; i < 31; i++)
    {
        if(sg[i] % (m + 1)) //(m + 1)进制异或不等于0，则为必胜态
            return true;
    }
    return false;
}

int main()
{
    while(~scanf("%d%d%d%d", &n, &m, &l, &r))
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        memset(sg, 0, sizeof(sg));
        int k = getDis(l);
        for(int i = 0; i < n; i++)
        {
            int x = getDis(a[i]) % k;
            for(int j = 0; x; j++)  //分离出每一位
            {
                sg[j] += x & 1;
                x >>= 1;
            }
        }
        puts(check() ? "Alice" : "Bob");
    }
    return 0;
}
