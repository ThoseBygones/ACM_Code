/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-03-31
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 二维树状数组（单点更新 + 区间求和）
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 1005

int bit2D[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n,m;

void add2D(int x, int y, int val)
{
    for(int i = x; i <= n; i += lowbit(i))
    {
        for(int j = y; j <= m; j += lowbit(j))
            bit2D[i][j] += val;
    }
}

int getSum2D(int x, int y)
{
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i))
    {
        for(int j = y; j > 0; j -= lowbit(j))
            sum += bit2D[i][j];
    }
    return sum;
}

int main()
{
    n = m = 1001;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char op[2];
        scanf("%s",op);
        if(op[0] == 'B')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++, y++;
            if(!vis[x][y])
            {
                vis[x][y] = true;
                add2D(x,y,1);
            }
        }
        else if(op[0] == 'D')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++, y++;
            if(vis[x][y])
            {
                vis[x][y] = false;
                add2D(x,y,-1);
            }
        }
        else if(op[0] == 'Q')
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
            x1++, x2++, y1++, y2++;
            if(x1 > x2)
                swap(x1,x2);
            if(y1 > y2)
                swap(y1,y2);
            int ans = getSum2D(x2,y2) - getSum2D(x1-1,y2) - getSum2D(x2,y1-1) + getSum2D(x1-1,y1-1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
