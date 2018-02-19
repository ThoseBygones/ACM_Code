/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-15
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 离散化 + 树状数组
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

struct Node
{
    int val;
    int idx;
} a[MAXN];

int bit[MAXN];
int Hash[MAXN];

bool cmp(Node x,Node y)
{
    if(x.val==y.val)
        return x.idx<=y.idx;
    return x.val<y.val;
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
    int sum=0;
    while(i > 0)
    {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

int main()
{
    int t,kase=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i].val);
            a[i].idx=i;
        }
        sort(a+1,a+1+n,cmp);
        memset(bit,0,sizeof(bit));
        LL ans=0;
        for(int i=1; i<=n; i++)
        {
            add(a[i].idx,1);
            ans+=i-getSum(a[i].idx);
        }
        printf("Scenario #%d:\n%lld\n\n",kase++,ans);
    }
    return 0;
}
