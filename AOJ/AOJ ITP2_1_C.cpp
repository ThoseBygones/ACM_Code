/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-22
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

list<int> l;

int main()
{
    int q;
    scanf("%d", &q);
    auto it = l.end();
    while(q--)
    {
        int op;
        scanf("%d", &op);
        if(op == 0)
        {
            int x;
            scanf("%d", &x);
            it = l.insert(it, x);
        }
        else if(op == 1)
        {
            int x;
            scanf("%d", &x);
            advance(it, x);
        }
        else if(op == 2)
            it = l.erase(it);
    }
    for(auto x: l)
        printf("%d\n", x);
    return 0;
}
