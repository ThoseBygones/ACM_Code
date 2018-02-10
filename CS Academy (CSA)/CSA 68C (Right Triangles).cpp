/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-10
 *  Subject: ACM-ICPC
 *  Language: C/C++
 *  OJ: CS Academy (CSA)
 *  Algorithm: 树状数组
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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

typedef int Type;

struct Point
{
    Type x,y;
    int idx,ans;
    double k;
    Point(Type x,Type y,int idx,int ans,double k):x(x),y(y),idx(idx),ans(ans),k(k) {}
    Point() {}
    void read()
    {
        scanf("%d %d",&x,&y);
    }
};

Point p[MAXN];
int bit[MAXN<<2];
int n;

bool cmp1(Point &p1,Point &p2)
{
    return p1.k<p2.k;
}

bool cmp2(Point &p1,Point &p2)
{
    return p1.idx<p2.idx;
}

void add(int i,int x)
{
    while(i<MAXN)   //2<=n<=1e5
    {
        bit[i]+=x;
        i+=lowbit(i);
    }
}

int getsum(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=bit[i];
        i-=lowbit(i);
    }
    return sum;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        p[i].read();
        p[i].idx=i;
        p[i].k=1.0*p[i].y/p[i].x;
    }
    sort(p+1,p+n+1,cmp1);
    for(int i=1; i<=n; i++)
    {
        p[i].ans=getsum(p[i].x);
        add(p[i].x,1);
    }
    sort(p+1,p+1+n,cmp2);
    for(int i=1; i<=n; i++)
        printf("%d\n",p[i].ans);
    return 0;
}
