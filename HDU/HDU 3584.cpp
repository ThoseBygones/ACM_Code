/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-03-31
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 三维树状数组（区间更新 + 单点求值）
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
#define MAXN 105

int bit3D[MAXN][MAXN][MAXN];
int n;

void add3D(int x, int y, int z, int val)   //类似于前缀和
{
    for(int i = x; i <= n; i += lowbit(i))
    {
        for(int j = y; j <= n; j += lowbit(j))
        {
            for(int k = z; k <= n; k += lowbit(k))
                bit3D[i][j][k] += val;
        }
    }
}

int getSum3D(int x,int y,int z)
{
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i))
    {
        for(int j = y; j > 0; j -= lowbit(j))
        {
            for(int k = z; k > 0; k -= lowbit(k))
                sum += bit3D[i][j][k];
        }
    }
    return sum;
}

int main()
{
    int m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(bit3D,0,sizeof(bit3D));
        int op;
        while(m--)
        {
            scanf("%d",&op);
            if(op)
            {
                int x1,y1,z1,x2,y2,z2;
                scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
                //容斥原理
                add3D(x1,y1,z1,1);  //相当于标记为+1
                add3D(x1,y1,z2+1,1);    //相当于标记为-1
                add3D(x1,y2+1,z1,1);    //相当于标记为-1
                add3D(x1,y2+1,z2+1,1);  //相当于标记为+1
                add3D(x2+1,y1,z1,1);    //相当于标记为-1
                add3D(x2+1,y2+1,z1,1);  //相当于标记为+1
                add3D(x2+1,y1,z2+1,1);  //相当于标记为+1
                add3D(x2+1,y2+1,z2+1,1);  //相当于标记为-1
            }
            else
            {
                int x,y,z;
                scanf("%d%d%d",&x,&y,&z);
                printf("%d\n",getSum3D(x,y,z)&1);   //根据奇偶性判断最终到底是0还是被翻转为1
            }
        }
    }
    return 0;
}
