/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-30
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: ������
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

const int MAXN = 20005;

bool vis[MAXN];

void init()
{
    memset(vis, false, sizeof(vis));
    vis[1] = true;
    for(int i = 2; i <= 20000; i++)
    {
        if(!vis[i])
        {
            for(int j = 2 * i; j <= 20000; j += i)
                vis[j] = true;
        }
    }
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    int Max = 1, ans = 1;
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        for(int j = x; j; j--)
        {
            if(vis[j])
                continue;
            if(x % j == 0)
            {
                if(Max < j)
                {
                    Max = j;
                    ans = x;
                }
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
