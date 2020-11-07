/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-04
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 优先队列
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

const int MAXN = 100005;

struct Stone
{
    int p, d;
    Stone() {}
    Stone(int p, int d) : p(p), d(d) {}
    bool operator < (const Stone &s) const
    {
        if(p == s.p)
            return d > s.d;
        return p > s.p;
    }
};

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        priority_queue<Stone> pq;
        for(int i = 0; i < n; i++)
        {
            int p, d;
            scanf("%d%d", &p, &d);
            pq.push(Stone(p, d));
        }
        int flag = 1;
        Stone tmp;
        while(!pq.empty())
        {
            tmp = pq.top();
            pq.pop();
            if(flag)
            {
                tmp.p += tmp.d;
                pq.push(tmp);
            }
           flag ^= 1;
        }
        printf("%d\n", tmp.p);
    }
    return 0;
}
