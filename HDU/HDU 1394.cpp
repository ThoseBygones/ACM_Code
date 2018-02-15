//线段树求逆序对
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 5005

class SegTree
{
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

public:
    int a[MAXN];
    int Sum[MAXN<<2];

    void PushUP(int rt)
    {
        Sum[rt] = Sum[rt<<1] + Sum[rt<<1|1];
    }

    void build(int l,int r,int rt)
    {
        Sum[rt] = 0;
        if(l == r)
            return ;
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
    }

    void updateNode(int p,int val,int l,int r,int rt)
    {
        if(l == r)
        {
            Sum[rt]++;
            return ;
        }
        int m = (l + r) >> 1;
        if(p <= m)
            updateNode(p,val,lson);
        else
            updateNode(p,val,rson);
        PushUP(rt);
    }

    int querySum(int L,int R,int l,int r,int rt)
    {
        if(L <= l && r <= R)
            return Sum[rt];
        int m = (l + r) >> 1;
        int ret = 0;
        if(L <= m)
            ret += querySum(L,R,lson);
        if(R > m)
            ret += querySum(L,R,rson);
        return ret;
    }

    int findMinInv(int n)
    {
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum += querySum(a[i],n-1,0,n-1,1);  //求出每个点的你叙述
            updateNode(a[i],n-1,0,n-1,1);
        }
        int ans = sum;
        for(int i=0; i<n; i++)
        {
            sum += n - a[i] - 1 - a[i];
            //假设小于a的个数为t,那么大于a的个数就是n-t-1.
            //当把a移动左移一位时，原来比a大的现在都成了a的逆序对，即逆序数增加n-t-1；但是原来比a小的构成逆序对的数都变成了顺序，因此逆序对减少t
            //所以新序列的逆序数为n-t-t-1
            ans = min(sum,ans);
        }
        printf("%d\n",ans);
    }
} segtree;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        segtree.build(0,n-1,1);
        segtree.findMinInv(n);
    }
    return 0;
}


//树状数组求逆序对
/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-15
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 树状数组求逆序对
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
#define MAXN 5005
using namespace std;

int a[MAXN];
int bit[MAXN];
int n;

void add(int i,int x)
{
    while(i <= n)
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
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);  //下标从1开始
            a[i]++;
        }
        memset(bit,0,sizeof(bit));
        LL ans=0;
        for(int i=1; i<=n; i++)
        {
            add(a[i],1);
            ans+=i-getSum(a[i]);
        }
        LL Min=ans;
        for(int i=1; i<=n; i++)
        {
            ans += (n-a[i]-(a[i]-1));   //a[i]从队首调到队尾，应该加上比它大的n-a[i]个数，再减去比它小的a[i]-1个数（注意，这里的a[i]已经离散化为下标从1开始的）
            Min=min(ans,Min);
        }
        printf("%lld\n",Min);
    }
    return 0;
}
