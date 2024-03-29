/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-05
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: STL Multiset
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

const int MAXN = 10005;

multiset<int> ms;
bool vis[MAXN];

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i <= n; i++)
            vis[i] = false;
        ms.clear();
        for(int i = 0; i < m; i++)
        {
            int x;
            scanf("%d", &x);
            vis[x] = true;
        }
        int cnt = 0;
        int p = 1;  //初始policy
        char op[2];
        while(scanf("%s", op))
        {
            if(op[0] == 'e')
                break;
            if(op[0] == 'a')
            {
                int x;
                scanf("%d", &x);
                ms.insert(x);
            }
            if(op[0] == 'p')
            {
                int x;
                scanf("%d", &x);
                p = x;
            }
            if(op[0] == 'r')
            {
                if(ms.empty())
                    puts("-1");
                else
                {
                    if(p == 1)
                    {
                        if(vis[++cnt])
                            printf("%d\n", *ms.begin());
                        ms.erase(*ms.begin());
                    }
                    else
                    {
                        if(vis[++cnt])
                            printf("%d\n", *ms.rbegin());
                        ms.erase(*ms.rbegin());
                    }
                }
            }
        }
        puts("");
    }
    return 0;
}
