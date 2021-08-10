/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: 队列
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

const int MAXN = 105;

queue<int> q;
int a[MAXN], b[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        while(!q.empty())
            q.pop();
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
            q.push(i);
        }
        sort(b, b + n, greater<int>());
        int pos = 0, Max = 0, ans = 0;
        while(!q.empty())
        {
            Max = b[pos];
            int cur = q.front();
            q.pop();
            if(a[cur] < Max)    //优先级小于队列中优先级最高的任务
                q.push(cur);
            else
            {
                ans++;
                if(cur == m)    //优先级最高的是我的任务
                {
                    printf("%d\n", ans);
                    break;
                }
                else    //不是我的任务，先完成该任务
                    pos++;
            }
        }
    }
    return 0;
}
