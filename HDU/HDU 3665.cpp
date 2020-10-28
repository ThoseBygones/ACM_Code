/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-15
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: Floyd
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

int d[MAXN][MAXN];
int vis[MAXN];
int n;

void floyd()
{
    for(int k=0; k<n; k++)
    {
        d[k][k]=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}

int main()
{
    while(~scanf("%d", &n))
    {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    d[i][j] = 0;
                else
                    d[i][j] = INF;
            }
        }
        for(int i = 0; i < n; i++)
        {
            int m, p;
            scanf("%d%d", &m, &p);
            vis[i] = p;
            while(m--)
            {
                int v, w;
                scanf("%d%d", &v, &w);
                d[i][v] = w;
            }
        }
        floyd();
        int ans = INF;
        for(int i = 0; i < n; i++)
        {
            if(vis[i])
                ans = min(ans, d[0][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
