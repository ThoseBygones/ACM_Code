/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-20
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 枚举 + 前缀和 + 后缀和
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
LL pre[MAXN], suf[MAXN];   //前/后缀和

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i-1] + a[i];
    for(int i = n; i; i--)
        suf[i] = suf[i+1] + a[i];
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == a[i-1])
            sum++;
        else
            sum = 1;
        if(sum >= k)    //本身相等数字数量就够
        {
            puts("0");
            return 0;
        }
    }
    LL ans = LINF;
    for(int i = 1; i <= n; i++) //枚举k个相同的数等于多少
    {
        if(i >= k)  //只调整小于a[i]的数
            ans = min(ans, 1LL * a[i] * i - pre[i] - (i - k));  //多于k个的数加到a[i]-1即可
        if(n - i + 1 >= k)  //只调整大于a[i]的数
            ans = min(ans, suf[i] - 1LL * a[i] * (n - i + 1) - (n - i + 1 - k));    //多于k个的数减到a[i]+1即可
        //都需要调整
        ans = min(ans, 1LL * a[i] * i - pre[i] + suf[i] - 1LL * a[i] * (n - i + 1) - (n - k));    //多于k个的数少操作一次即可
    }
    printf("%lld\n", ans);
    return 0;
}
