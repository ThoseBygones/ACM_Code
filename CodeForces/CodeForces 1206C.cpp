/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-15
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

int a[MAXN<<1];

int main()
{
    int n;
    scanf("%d",&n);
    if(n % 2 == 0)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i=1,x=1; i<=n; i++)
    {
        a[i] = x;
        if(x & 1)
        {
            a[i+n] = x + 1;
            x += 3;
        }
        else
        {
            a[i+n] = x - 1;
            x++;
        }
    }
    for(int i=1; i<=2*n; i++)
    {
        if(i == 1)
            printf("%d",a[i]);
        else
            printf(" %d",a[i]);
    }
    puts("");
    return 0;
}
