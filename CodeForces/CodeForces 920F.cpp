/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-03-05
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 线段树（特殊类型区间修改与查询）
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
#define MAXN 300005
#define MAXM 1000005

struct Node
{
    int l,r;
    LL sum,Max; //sum维护区间和，Max维护区间最大值
} tree[MAXN<<2];

int a[MAXN];
int cnt[MAXM];

void pushUp(int rt)
{
    tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
    tree[rt].Max = max(tree[rt<<1].Max,tree[rt<<1|1].Max);
}

void build(int l,int r,int rt)
{
    tree[rt].l = l, tree[rt].r = r;
    if(tree[rt].l == tree[rt].r)
    {
        tree[rt].sum = tree[rt].Max = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(rt);
}

void updateInterval(int ll,int rr,int rt)   //这种区间修改比较特殊，相当于单点修改，因此不需要（也不能）使用延迟标记
{
    if(tree[rt].Max <= 2) //D(2)==2, D(1)==1，区间最大值小于等于2时该区间就不需要修改了
        return ;
    if(tree[rt].l == tree[rt].r)
    {
        tree[rt].sum = tree[rt].Max = cnt[tree[rt].sum];
        return ;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(ll <= mid)
        updateInterval(ll,rr,rt<<1);
    if(rr > mid)
        updateInterval(ll,rr,rt<<1|1);
    pushUp(rt);
}

LL querySum(int ll,int rr,int rt)
{
    if(ll <= tree[rt].l && tree[rt].r <= rr)
        return tree[rt].sum;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    LL ans = 0;
    if(ll <= mid)
        ans += querySum(ll,rr,rt<<1);
    if(rr > mid)
        ans += querySum(ll,rr,rt<<1|1);
    return ans;
}

void init() //预处理，复杂度O(NlogN)（n*(1+1/2+1/3+...+1/n)=nlogn）
{
    for(int i=1; i<=1000000; i++)
    {
        for(int j=i; j<=1000000; j+=i)
            cnt[j]++;
    }
}

int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    build(1,n,1);
    for(int i=0; i<m; i++)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1)
            updateInterval(l,r,1);
        else
            printf("%I64d\n",querySum(l,r,1));
    }
    return 0;
}
