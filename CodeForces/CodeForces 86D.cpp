/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-09-28
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ:
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
#define MAXN 200010
#define MAXM 1000005

typedef LL Type;

int a[MAXN];
int cnt[MAXM];
Type ans[MAXN];
LL sum;

const int sq_n = 333;

struct Query
{
    int l,r,idx;
    bool operator<(const Query& q) const
    {
        int l1 = l/sq_n,l2 = q.l/sq_n;
        if(l1==l2)
            return r<q.r;
        else
            return l1<l2;
    }
} q[MAXN];

//添加一个位置
void addPos(int pos)
{
    sum -= (LL)cnt[a[pos]] * cnt[a[pos]] * a[pos];
    cnt[a[pos]]++;
    sum += (LL)cnt[a[pos]] * cnt[a[pos]] * a[pos];
}

//移除一个位置
void removePos(int pos)
{
    sum -= (LL)cnt[a[pos]] * cnt[a[pos]] * a[pos];
    cnt[a[pos]]--;
    sum += (LL)cnt[a[pos]] * cnt[a[pos]] * a[pos];
}

int solve(Query& q,int last,int l,int r)
{
    while(l>q.l)
    {
        l--;
        addPos(l);
    }
    while(r<q.r)
    {
        r++;
        addPos(r);
    }
    while(r>q.r)
    {
        removePos(r);
        r--;
    }
    while(l<q.l)
    {
        removePos(l);
        l++;
    }
    return last;
}

//m是询问个数
void mo(int m)
{
    sort(q,q+m);
    int l = 1,r = 1;
    int last = 0;
    cnt[a[1]]++;
    sum = a[1];
    for(int i = 0; i<m; i++)
    {
        last = solve(q[i],last,l,r);
        l = q[i].l,r = q[i].r;
        //处理ans[q[i].idx]
        ans[q[i].idx] = sum;
    }
    //输出ans
    for(int i=0; i<m; i++)
        printf("%I64d\n",ans[i]);
}

int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<t; i++)
    {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].idx = i;
    }
    mo(t);
    return 0;
}
