/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V4.0
 *  Date: 2018-02-21
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: Manacher
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
#define MAXN 100010

int newstr[MAXN<<1];
int rad[MAXN<<1];
int n;

int manacher(int *str)
{
    int j = 1;
    int Max = 0;
    newstr[0] = -1;
    for(int k=0; k<n; k++)
    {
        newstr[j++] = 0;
        newstr[j++] = str[k];
    }
    newstr[j] = 0;
    int mx = 0, id = 0;
    for(int i=1; i<=j; i++)
    {
        if(mx > i)
            rad[i] = min(rad[id*2-i],mx-i);
        else
            rad[i] = 1;
        while(newstr[i-rad[i]] == newstr[i+rad[i]] && newstr[i-rad[i]] <= newstr[i-rad[i]+2])
            rad[i]++;
        Max = max(Max,rad[i]);
        if(rad[i] + i > mx)
        {
            mx = rad[i] + i;
            id = i;
        }
    }
    return Max - 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[MAXN];
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        printf("%d\n",manacher(a));
    }
    return 0;
}
