/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-12
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 数论
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

vector<int> v;

LL solve(int val)
{
    int mid = val >> 1;
    LL ans = 0;
    for(int i = 0; i < v.size(); i += val)  //分组整合巧克力
    {
        for(int j = 0; j < val; j++)    //对每一组内的巧克力进行移动
            ans += abs(v[i+mid] - v[i+j]);
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if(x)
            v.PB(i);
    }
    if(v.size() < 2)
    {
        puts("-1");
        return 0;
    }
    LL ans = LINF;
    for(int i = 2; i * i <= v.size(); i++)  //枚举移动完后每一盒的巧克力数量
    {
        if(v.size() % i == 0)
        {
            ans = min(ans, solve(i));
            ans = min(ans, solve(v.size() / i));
        }
    }
    ans = min(ans, solve(v.size()));
    printf("%lld\n", ans);
    return 0;
}
