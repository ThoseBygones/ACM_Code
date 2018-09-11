/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-05-13
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
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

struct Node
{
    int id;
    int val;
    int cnt;
} a[MAXN];

set<int> s[MAXN];
int b[MAXN];

bool cmp1(Node x,Node y)
{
    return x.val<y.val;
}

bool cmp2(Node x,Node y)
{
    return x.id<y.id;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i].val);
        a[i].id=i;
        a[i].cnt=0;
    }
    for(int i=0; i<k; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(a[u].val>a[v].val)
            s[u].insert(v);
        else if(a[u].val<a[v].val)
            s[v].insert(u);
    }
    sort(a+1,a+n+1,cmp1);
    //for(int i=1; i<=n; i++)
    //    cout << s[i].size() << endl;
    for(int i=1; i<=n; i++)
        b[i]=a[i].val;
    for(int i=1; i<=n; i++)
    {
        int pos=upper_bound(b+1,b+1+n,b[i]-1)-b-1;
        a[i].cnt=pos;
    }
    sort(a+1,a+1+n,cmp2);
    for(int i=1; i<=n; i++)
    {
        printf("%d",a[i].cnt-s[i].size());
        printf(i==n?"\n":" ");
    }
    return 0;
}
