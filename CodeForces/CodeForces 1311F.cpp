/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-04
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 树状数组 + 离散化
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define MAXN 200005

struct Point
{
    int x,v;
    bool operator <(const Point &p) const
    {
        return x < p.x;
    }
} p[MAXN];

int v[MAXN];    //记录点的速度
LL cnt[MAXN];  //离散化后与v[i]速度相等的点的数量
LL sum[MAXN];   //第i个点的的坐标值（距离坐标原点的距离）
int n;

void add(int i, int x, LL bit1[], LL bit2[])
{
    while(i <= n)
    {
        bit1[i]++;
        bit2[i] += (LL)x;
        i += lowbit(i);
    }
}

LL getsum(int i, LL bit[])
{
    LL sum = 0;
    while(i > 0)
    {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&p[i].x);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&p[i].v);
        v[i] = p[i].v;
    }
    sort(p+1,p+1+n);
    sort(v+1,v+1+n);
    int m = unique(v+1,v+1+n) - v - 1;  //对点的速度去重
    LL ans = 0;
    for(int i=1; i<=n; i++)
    {
        int pos = lower_bound(v+1,v+1+m,p[i].v) - v;    //查找当前点的速度排第几
        ans += getsum(pos,cnt) * p[i].x - getsum(pos,sum);  //坐标在该点左边且比该点速度小的点的数量 * 该点的坐标值 - 坐标在该点左边且比该点速度小的点的坐标和
        add(pos,p[i].x,cnt,sum);    //将该点插入树状数组中
    }
    printf("%lld\n",ans);
    return 0;
}
