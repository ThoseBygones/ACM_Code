/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-03
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: µ¥µ÷Õ» + Ç°×ººÍ / dp
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

const int MAXN = 50005;

LL w[MAXN], h[MAXN];
LL l[MAXN], r[MAXN];
LL sta[MAXN];  //Êý×éÄ£ÄâÕ»

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(n == -1)
            break;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld%lld", &w[i], &h[i]);
            w[i] += w[i - 1];
        }
        int top = -1;
        for(int i = 1; i <= n; i++)  //ÍùÓÒ±ßÑÓÉì
        {
            while(~top && h[sta[top]] >= h[i])
                --top;
            if(~top)
                l[i] = sta[top];
            else
                l[i] = 0;
            //cout << "l[i]: " << l[i] << endl;
            sta[++top] = i;
        }
        top = -1;
        for(int i = n; i; i--)  //Íù×ó±ßÑÓÉì
        {
            while(~top && h[sta[top]] >= h[i])
                --top;
            if(~top)
                r[i] = sta[top] - 1;
            else
                r[i] = n;
            //cout << "r[i]: " << r[i] << endl;
            sta[++top] = i;
        }
        LL ans = 0;
        for(int i = 1; i <= n; i++)
            ans = max(ans, h[i] * (w[r[i]] - w[l[i]]));
        printf("%lld\n", ans);
    }
    return 0;
}
