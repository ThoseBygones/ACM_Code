/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-04-01
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HIT
 *  Algorithm: 二维树状数组
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
#define MAXN 1030

int bit2D[MAXN][MAXN];
int n;

void add2D(int x, int y, int val)   //类似于前缀和
{
    for(int i = x; i <= n; i += lowbit(i))  //n为矩阵其中一维的大小
    {
        for(int j = y; j <= n; j += lowbit(j))  //m为矩阵另外一维的大小
            bit2D[i][j] += val;
    }
}

int getSum2D(int x,int y)
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
    int op;
    while(~scanf("%d",&op))
    {
        if(op == 0)
        {
            memset(bit2D,0,sizeof(bit2D));
            scanf("%d",&n);
        }
        else if(op == 1)
        {
            int x,y,a;
            scanf("%d%d%d",&x,&y,&a);
            x++, y++;
            add2D(x,y,a);
        }
        else if(op == 2)
        {
            int l,b,r,t;
            scanf("%d%d%d%d",&l,&b,&r,&t);
            l++, b++, r++, t++;
            printf("%d\n",getSum2D(r,t)-getSum2D(l-1,t)-getSum2D(r,b-1)+getSum2D(l-1,b-1));
        }
        else
            continue;
    }
    return 0;
}
