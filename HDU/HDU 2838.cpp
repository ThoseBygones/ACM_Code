/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-03-30
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 树状数组求逆序对数 + 逆序对数值和
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
#define MAXN 100005

int n;
int bitcnt[MAXN];   //bitcnt表示每个数前面比它小的数的个数
LL bitsum[MAXN];    //bitsum表示每个数前面比它小的数的和

void add(int i, int x, int val)
{
    while(i <= n)
    {
        bitcnt[i] += x;
        bitsum[i] += val;
        i += lowbit(i);
    }
}

int getsum1(int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += bitcnt[i];
        i -= lowbit(i);
    }
    return sum;
}

LL getsum2(int i)
{
    LL sum = 0;
    while(i > 0)
    {
        sum += bitsum[i];
        i -= lowbit(i);
    }
    return sum;
}

int main()
{
    scanf("%d",&n);
    memset(bitcnt,0,sizeof(bitcnt));
    memset(bitsum,0,sizeof(bitsum));
    LL ans = 0;
    for(int i=1; i<=n; i++)
    {
        int a;
        scanf("%d",&a);
        add(a,1,a);
        int x1 = i - getsum1(a);    //求出a的逆序对数量
        if(x1)
        {
            LL x2 = getsum2(n) - getsum2(a);    //前n个数的和 - 比a小的数的和 = 比a大的数的和
            ans += (LL)x1 * a + x2;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
