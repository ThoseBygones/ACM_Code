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

const int MAXN = 1005;

list<int> l[MAXN];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    while(q--)
    {
        int op;
        scanf("%d", &op);
        if(op == 0)
        {
            int t, x;
            scanf("%d%d", &t, &x);
            l[t].PB(x);
        }
        else if(op == 1)
        {
            int t;
            scanf("%d", &t);
            if(l[t].empty())
                puts("");
            else
            {
                for(auto it = l[t].begin(); it != l[t].end(); it++)
                {
                    if(it == l[t].begin())
                        printf("%d", *it);
                    else
                        printf(" %d", *it);
                }
                puts("");
            }
        }
        else if(op == 2)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            auto it = l[t].end();
            l[t].splice(it, l[s]);
        }
    }
    return 0;
}
