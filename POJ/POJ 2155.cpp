/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-17
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
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
#define MAXN 1005
using namespace std;

int bit2D[MAXN][MAXN];
int n;

void add2D(int x,int y,int val)
{
    for(int i = x; i <= n; i += lowbit(i))
    {
        for(int j = y; j <= n; j += lowbit(j))
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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int q;
        scanf("%d%d",&n,&q);
        memset(bit2D,0,sizeof(bit2D));
        while(q--)
        {
            char op[2];
            scanf("%s",op);
            if(op[0]=='C')
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                //类似于前缀和
                add2D(x2+1,y2+1,1);
                add2D(x1,y2+1,1);
                add2D(x2+1,y1,1);
                add2D(x1,y1,1);
            }
            if(op[0]=='Q')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",getSum2D(x,y)%2); //对2取模，反转相当于只取所求值的奇偶性
            }
        }
        puts("");
    }
    return 0;
}
