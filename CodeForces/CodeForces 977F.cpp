/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-09-03
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp + STL Map
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

int a[MAXN];
map<int,int> dp;    //dp[i]表示以元素i为末尾的序列的大小

int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    int num=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        dp[a[i]] = dp[a[i]-1] + 1;
        if(ans<dp[a[i]])
        {
            ans=dp[a[i]];
            num=a[i];
        }
    }
    printf("%d\n",ans);
    int pos=num-ans+1;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==pos)
        {
            if(a[i]!=num)
                printf("%d ",i);
            else
                printf("%d\n",i);
            pos++;
        }
    }
    return 0;
}
