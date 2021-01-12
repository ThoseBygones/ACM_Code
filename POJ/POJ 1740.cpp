/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-01-12
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 博弈论
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

const int MAXN = 15;

int a[MAXN];

int main()
{
    int n;
    while(~scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if(n & 1)   //奇数堆，则先手必胜
            puts("1");
        else    //偶数堆
        {
            sort(a, a + n);
            bool flag = false;
            for(int i = 0; i < n; i += 2)
            {
                if(a[i] != a[i + 1])    //并非成对相等，则先手必胜
                {
                    puts("1");
                    flag = true;
                    break;
                }
            }
            if(!flag)   //若都成对相等，则先手必败
                puts("0");
        }
    }
    return 0;
}
