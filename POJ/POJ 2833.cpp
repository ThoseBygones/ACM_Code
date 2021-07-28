/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-22
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
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

priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int> > pq2;

int main()
{
    int n1, n2, n;
    while(~scanf("%d%d%d", &n1, &n2, &n))
    {
        if(!n1 && !n2 && !n)
            break;
        LL sum = 0;
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            sum += x;
            pq1.push(x);
            pq2.push(x);
            if(pq1.size() > n2)  //存储最小的n2个数
                pq1.pop();
            if(pq2.size() > n1)  //存储最大的n1个数
                pq2.pop();
        }
        while(!pq1.empty())
        {
            sum -= pq1.top();
            pq1.pop();
        }
        while(!pq2.empty())
        {
            sum -= pq2.top();
            pq2.pop();
        }
        printf("%.6f\n", 1.0 * sum / (n - n1 - n2));
    }
    return 0;
}
