/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-03-10
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
#define MOD 1000000007
#define MAXN 100005

int s1[MAXN],s2[MAXN];

int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return d;
}

int modInv(int a,int m)
{
    int x,y;
    exgcd(a,m,x,y);
    return (m + x % m) % m;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%d",&s1[i]);
    for(int i=0; i<n; i++)
        scanf("%d",&s2[i]);
    int eq = modInv(m,MOD);
    int ans = 0;
    int temp = 1; //到第i个字符，s1仍与s2相等的概率
    for(int i=0; i<n; i++)
    {
        if(s1[i] == 0 && s2[i] == 0)
        {
            ans = (ans + (LL)temp * (((LL)m * (m - 1) / 2) % MOD) % MOD * modInv((LL)m * m % MOD,MOD)) % MOD;
            temp = (LL)temp * m % MOD * modInv((LL)m * m % MOD,MOD) % MOD;
        }
        else if(s1[i] == 0 && s2[i] != 0)
        {
            ans = (ans + (LL)temp * (m - s2[i]) % MOD * eq) % MOD;
            temp = (LL)temp * eq % MOD;
        }
        else if(s1[i] != 0 && s2[i] == 0)
        {
            ans = (ans + (LL)temp * (s1[i] - 1) % MOD * eq) % MOD;
            temp = (LL)temp * eq % MOD;
        }
        else if(s1[i] > s2[i])
        {
            ans = (ans + temp) % MOD;
            break;
        }
        else if(s1[i] < s2[i])
            break;
    }
    printf("%d\n",ans);
    return 0;
}
