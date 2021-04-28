/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-06-08
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 分治 + 优先队列
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

const int MAXN = 200005;

struct Segment
{
    int l, r, len;
    Segment() {}
    Segment(int l, int r, int len) : l(l), r(r), len(len) {}
    bool operator <(const Segment & s) const
    {
        if(len == s.len)
            return l > s.l;
        return len < s.len;
    }
};

int ans[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int cnt = 1;
        priority_queue<Segment> pq;
        pq.push(Segment(1, n, n));
        while(!pq.empty())
        {
            Segment seg = pq.top();
            pq.pop();
            int l = seg.l, r = seg.r;
            int mid = (l + r) >> 1;
            ans[mid] = cnt++;
            if(mid - l >= 1)
                pq.push(Segment(l, mid - 1, mid - l));
            if(r - mid >= 1)
                pq.push(Segment(mid + 1, r, r - mid));
        }
        for(int i = 1; i <= n; i++)
            printf("%d%c", ans[i], (i == n ? '\n' : ' '));
    }
    return 0;
}
