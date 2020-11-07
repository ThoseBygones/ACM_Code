/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 单调队列
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

const int MAXN = 1000005;


/* 朴素单调队列 */

int a[MAXN];
int n, k;

struct Queue
{
    int val, pos;
    Queue() {}
    Queue(int val, int pos) : val(val), pos(pos) {}
    bool operator < (const Queue &q) const
    {
        return val < q.val;
    }
} q[MAXN];

void getMin()
{
    memset(q, 0, sizeof(q));
    int head = 1, tail = 0;
    for(int i = 1; i <= n; i++)
    {
        while(head <= tail && q[tail].val >= a[i])  //保持队首元素为最小值
            tail--;
        q[++tail] = Queue(a[i], i);
        if(i >= k)
        {
            while(q[head].pos <= i - k)
                head++;
            printf("%d%c", q[head].val, (i == n ? '\n' : ' '));
        }
    }
}

void getMax()
{
    memset(q, 0, sizeof(q));
    int head = 1, tail = 0;
    for(int i = 1; i <= n; i++)
    {
        while(head <= tail && q[tail].val <= a[i])  //保持队首元素为最小值
            --tail;
        q[++tail] = Queue(a[i], i);
        if(i >= k)
        {
            while(q[head].pos <= i - k)
                head++;
            printf("%d%c", q[head].val, (i == n ? '\n' : ' '));
        }
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    getMin();
    getMax();
    return 0;
}


/* 单调队列 + 出队时二分 */

int a[MAXN];
int q[MAXN], pos[MAXN];
int n, k;

void getMin()
{
    memset(q, 0, sizeof(q));
    memset(pos, 0, sizeof(pos));
    int head = 1, tail = 0;
    for(int i = 1; i <= n; i++)
    {
        if(head <= tail)
        {
            tail = lower_bound(q + head, q + tail + 1, a[i]) - q;
            tail--;
        }
        q[++tail] = a[i];
        pos[tail] = i;
        if(i >= k)
        {
            while(pos[head] <= i - k)
                head++;
            printf("%d%c", q[head], (i == n ? '\n' : ' '));
        }
    }
}

void getMax()
{
    memset(q, 0, sizeof(q));
    int head = 1, tail = 0;
    for(int i = 1; i <= n; i++)
    {
        if(head <= tail)
        {
            tail = lower_bound(q + head, q + tail + 1, a[i], greater<int>()) - q;
            tail--;
        }
        q[++tail] = a[i];
        pos[tail] = i;
        if(i >= k)
        {
            while(pos[head] <= i - k)
                head++;
            printf("%d%c", q[head], (i == n ? '\n' : ' '));
        }
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    getMin();
    getMax();
    return 0;
}
