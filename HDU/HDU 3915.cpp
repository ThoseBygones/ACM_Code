/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-09-29
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: Nim博弈 + 快速幂 + 高斯消元解异或方程组
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
#define MOD 1000007

int a[MAXN][MAXN];

//快速幂
LL quickPow(LL x,LL k,LL mod)
{
    LL res = 1;
    while(k > 0)
    {
        if(k & 1)
            res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

int Gauss(int n)
{
    int rk = 0;
    for(int i = 0; i<n; i++)
    {
        int r = rk;
        for(int j = rk+1; j<n; j++)
            if(a[j][i])
                r = j;
        if(!a[r][i])
            continue;
        if(r!=rk)
            for(int j = 0; j<=n; j++)
                swap(a[r][j],a[rk][j]);
        for(int k = rk+1; k<n; k++)
            if(a[k][i])
                for(int j = i; j<=n; j++)
                    a[k][j]^=a[rk][j];
        rk++;
    }
    for(int i = rk; i<n; i++)
        if(a[i][n]) //无解
            return -1;
    return n-rk;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            int cnt = 0;
            while(x)    //将每个数字转化为二进制表示
            {
                a[cnt++][i] = x&1;
                x >>= 1;
            }
        }
        int k = Gauss(n);
        if(k == -1)
            puts("0");
        else
            printf("%lld\n",quickPow(2LL,(LL)(k),MOD));
    }
    return 0;
}
