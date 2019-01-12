/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-11
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

int main()
{
    LL a,b;
    scanf("%I64d%I64d",&a,&b);
    LL s = a + b;
    LL len = LINF;  //单色砖能铺成的最小边长（长边）
    LL ans = LINF;
    for(LL i = 1; i * i <= s; i++)  //枚举大砖块的边长（短边）
    {
        if(a % i == 0)
            len = min(len,a/i);
        if(b % i == 0)
            len = min(len,b/i);
        if(s % i == 0)  //能构成大矩形
        {
            LL l = s / i;   //大矩形的边长（长边）
            if(len <= l)    //单色砖能铺成的最小边长（长边）小于大矩形的边长（长边）
                ans = min(ans,2*(l+i));
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
