/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:2019-01-08
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
#define MOD 998244353

char a[MAXN],b[MAXN];
int pre[MAXN];

LL quickPow(LL x,LL k,LL mod)
{
    LL res = 1;
    while(k > 0)
    {
        if(k & 1)
            res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int mx = max(n,m);
    memset(a,'0',sizeof(a));
    memset(b,'0',sizeof(b));    //补零
    scanf("%s %s",a+1+mx-n,b+1+mx-m);   //最低位对齐
    /*
    for(int i=0; i<=mx; i++)
        printf("%c",a[i]);
    puts("");
    for(int i=0; i<=mx; i++)
        printf("%c",b[i]);
    puts("");
    */
    for(int i = 1; i <= mx; i++)
        pre[i] = pre[i-1] + (b[i] == '1');
    LL ans = 0;
    for(int i = 1; i <= mx; i++)
    {
        LL sum = (a[i] == '1');
        sum = sum * quickPow(2,mx-i,MOD) % MOD;
        ans = (ans + sum * pre[i] % MOD) % MOD;
    }
    printf("%I64d\n",ans);
    return 0;
}
