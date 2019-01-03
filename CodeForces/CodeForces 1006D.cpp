/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-02
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
#define MAXN 100005

char a[MAXN],b[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    int ans = 0;
    for(int i=0; i<n/2; i++)
    {
        int l=i,r=n-i-1;
        if((a[l] == b[l] && a[r] == b[r]) || (a[l] == a[r] && b[l] == b[r]) || (a[l] == b[r] && a[r] == b[l]))  //两两相等
            continue;
        else if(a[l] == b[l] || a[r] == b[r] || a[l] == b[r] || a[r] == b[l] || b[l] == b[r])   //只有一个相等，且不是a[l]与a[r]相等（因为只能改a）
            ans++;
        else
            ans += 2;
    }
    if(n&1 && a[n/2] != b[n/2])
        ans++;
    printf("%d\n",ans);
    return 0;
}
