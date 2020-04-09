/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-31
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

const LL MOD = 1e9 + 7;

char s[MAXN];
LL f[MAXN];

void init()
{
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i < MAXN; i++)
        f[i] = (f[i-1] + f[i-2]) % MOD;
}

int main()
{
    init();
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(s[i] == 'w' || s[i] == 'm')
        {
            puts("0");
            return 0;
        }
    }
    LL ans = 1, cnt = 1;
    for(int i = 1; i < len; i++)
    {
        if(s[i] == s[i-1] && (s[i] == 'n' || s[i] == 'u'))
            cnt++;
        else
        {
            ans = (ans * f[cnt]) % MOD;
            cnt = 1;
        }
    }
    ans = (ans * f[cnt]) % MOD;
    printf("%lld\n", ans);
    return 0;
}
