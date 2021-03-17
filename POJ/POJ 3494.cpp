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

const int MAXN = 2005;

int a[MAXN][MAXN];
int h[MAXN];
int l[MAXN], r[MAXN];
int s[MAXN];    //模拟单调栈

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        }
        int ans = 0;
        memset(h, 0, sizeof(h));
        for(int i = 1; i <= n; i++) //枚举行
        {
            for(int j = 1; j <= m; j++) //枚举列
            {
                if(a[i][j])
                    h[j]++;
                else
                    h[j] = 0;
            }
            int top = -1;
            for(int j = 1; j <= m; j++)
            {
                while(top >= 0 && h[j] <= h[s[top]])    //栈顶保存最小值对应的下标
                    top--;
                if(top >= 0)
                    l[j] = s[top] + 1;
                else
                    l[j] = 1;
                s[++top] = j;
            }
            top = -1;
            for(int j = m; j; j--)
            {
                while(top >= 0 && h[j] <= h[s[top]])
                    top--;
                if(top >= 0)
                    r[j] = s[top] - 1;
                else
                    r[j] = m;
                s[++top] = j;
            }
            int res = 0;
            for(int i = 1; i <= m; i++)
                res = max(res, h[i] * (r[i] - l[i] + 1));
            ans = max(ans, res);
        }
        printf("%d\n", ans);
    }
    return 0;
}
