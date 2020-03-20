/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-18
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 * > 对于一个长度为n的串，其长度大于1的子串数量为 n * (n - 1) / 2；
 * > 不是“好串”的串只有两种模式 "ABB...B" 和 "BAA..A"；
 * > 从前往后扫一遍，再从后往前扫一遍找到所有这样的串即可
 * > 注意，每次找到这样模式的串时，串 "AB" 总是会被多算一次，减去即可
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
#define MAXN 300005

char s[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    LL ans = 1LL * n * (n - 1) / 2;
    int cnt = 1;
    for(int i=1; i<n; i++)
    {
        if(s[i] != s[i-1])
        {
            ans -= cnt;
            cnt = 1;
        }
        else
            cnt++;
    }
    cnt = 1;
    for(int i=n-1; i; i--)
    {
        if(s[i] != s[i-1])
        {
            ans -= cnt;
            ans++;  //补上重复减去的"AB"串
            cnt = 1;
        }
        else
            cnt++;
    }
    printf("%lld\n",ans);
    return 0;
}
