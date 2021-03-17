/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-02-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 单调栈
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

int h[MAXN];    //长方形的高
int l[MAXN], r[MAXN];   //以i为起点的长方形能向左延伸到的端点和向右延伸到的端点
int s[MAXN];    //模拟单调栈

int main()
{
    int n;
    while(~scanf("%d", &n), n)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        int top = -1;
        for(int i = 1; i <= n; i++)  //寻找左端点
        {
            while(top >= 0 && h[i] <= h[s[top]])    //栈顶记录最小值
                top--;
            if(top >= 0) //栈非空
                l[i] = s[top] + 1;
            else
                l[i] = 1;
            s[++top] = i;
        }
        top = -1;
        for(int i = n; i; i--)  //寻找右端点
        {
            while(top >= 0 && h[i] <= h[s[top]])    //栈顶记录最小值
                top--;
            if(top >= 0)    //栈非空
                r[i] = s[top] - 1;
            else
                r[i] = n;
            s[++top] = i;

        }
        LL ans = 0;
        /*
        for(int i = 1; i <= n; i++)
            printf("%d %d\n", l[i], r[i]);
        */
        for(int i = 1; i <= n; i++)
            ans = max(ans, (LL)h[i] * (r[i] - l[i] + 1));
        printf("%lld\n", ans);
    }
    return 0;
}
