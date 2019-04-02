/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-04-02
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HIT
 *  Algorithm: 树状数组 + 素数判定
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
#define MAXN 1000010

int a[MAXN];
int bit[MAXN];
int n,q,m;

void add(int i, int x)
{
    while(i <= n)
    {
        bit[i] += x;
        i += lowbit(i);
    }
}

int getsum(int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

bool isPrime(int x)
{
    if(x <= 1)
        return false;
    for(int i=2; i<=sqrt(x); i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}

void init()
{
    memset(bit,0,sizeof(bit));
    int x = isPrime(m);
    for(int i=1; i<=n; i++)
    {
        a[i] = m;
        add(i,x);
    }
}

int main()
{
    int kase = 1;
    while(~scanf("%d%d%d",&n,&q,&m))
    {
        if(n == 0 && q == 0 && m == 0)
            break;
        init();
        printf("CASE #%d:\n",kase++);
        int op,x,y;
        while(q--)
        {
            scanf("%d%d%d",&op,&x,&y);
            if(op)
                printf("%d\n",getsum(y)-getsum(x-1));
            else
            {
                int pre = a[x];
                a[x] += y;
                if(!isPrime(pre) && isPrime(a[x]))  //之前的数不是素数，更新后的是
                    add(x,1);
                else if(isPrime(pre) && !isPrime(a[x])) //之前的数是素数，更新后的不是
                    add(x,-1);
            }
        }
        puts("");
    }
    return 0;
}
