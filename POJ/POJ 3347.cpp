/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-23
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm:
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
#define MAXN 55

struct Square
{
    double l,r,a;
} sq[MAXN];

int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=1; i<=n; i++)
            scanf("%lf",&sq[i].a);
        for(int i=1; i<=n; i++)
        {
            double templ=0;
            for(int j=1; j<i; j++)
                templ=max(templ,sq[j].r-fabs(sq[j].a-sq[i].a)/sqrt(2.0));
            sq[i].l=templ;
            sq[i].r=templ+sq[i].a*sqrt(2.0);
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                if(sq[i].l<sq[j].r)
                {
                    if(sq[i].a<sq[j].a)
                        sq[i].l=sq[j].r;
                    else
                        sq[j].r=sq[i].l;
                }
            }
        }
        bool flag=true;
        for(int i=1; i<=n; i++)
        {
            if(sq[i].r-sq[i].l>=EPS)
            {
                if(flag)
                {
                    printf("%d",i);
                    flag=false;
                }
                else
                    printf(" %d",i);
            }
        }
        puts("");
    }
    return 0;
}
