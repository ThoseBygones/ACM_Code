/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-15
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 离散化 + 树状数组求逆序对
 ********************************************************************************
 *  Algo-Description:
 *  > 将线段的s和e当做是(s,e)一个二维平面上的点，题目就变成问每一个点的左上角有多少个点。
 *  > 于是题目几乎变成 POJ 2352 Stars
 *  > 注意，POJ 2352 Stars 问左下角有多少个点。此题要求左上角有多少个点，且点并未按照某一坐标有序。
 *  > 处理方式：先按照 e（区间右端点）由大到小排，e相同时按照s（区间左端点）由小到大排。
 *  > 另外，需要离散化。且区间重合的线段需要特殊处理——直接赋值。
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
using namespace std;

struct Range
{
    int s,e;
    int idx;
} r[MAXN];

int bit[MAXN];
int cnt[MAXN];  //记录比第i只牛强壮的牛的数量

bool cmp(Range x,Range y)
{
    if(x.e==y.e)
        return x.s<y.s;
    return x.e>y.e;
}

void add(int i,int x)
{
    while(i < MAXN)
    {
        bit[i] += x;
        i += lowbit(i);
    }
}

int getSum(int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&r[i].s,&r[i].e);
            r[i].idx=i;
        }
        sort(r+1,r+1+n,cmp);
        memset(bit,0,sizeof(bit));
        memset(cnt,0,sizeof(cnt));
        for(int i=1; i<=n; i++)
        {
            if(i!=1 && r[i-1].s==r[i].s && r[i-1].e==r[i].e)    //区间完全重合，则比它们强壮的牛的数量应该相等
                cnt[r[i].idx]=cnt[r[i-1].idx];
            else
                cnt[r[i].idx]=getSum(r[i].s+1); //下标从1开始
            add(r[i].s+1,1);
        }
        for(int i=1; i<=n; i++)
        {
            if(i!=n)
                printf("%d ",cnt[i]);
            else
                printf("%d\n",cnt[i]);
        }
    }
    return 0;
}
