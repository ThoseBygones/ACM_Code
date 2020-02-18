/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-18
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 组合数学 + 容斥原理
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
#define MAXN 300005
#define MOD 998244353

PII p[MAXN];
int cnt1[MAXN],cnt2[MAXN];
map<PII,int> cnt3;
LL fac[MAXN];

bool cmp(PII x,PII y)
{
    if(x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}

int main()
{
    int n;
    scanf("%d",&n);
    fac[0] = 1;
    for(int i=1; i<=n; i++)
    {
        fac[i] = fac[i-1] * i % MOD;    //求出n!
        scanf("%d%d",&p[i].first,&p[i].second);
        cnt1[p[i].first]++;
        cnt2[p[i].second]++;
        cnt3[p[i]]++;
    }
    sort(p+1,p+1+n,cmp);
    LL res1 = 1, res2 = 1;
    for(int i=0; i<=n; i++)
    {
        if(cnt1[i] > 1)
            res1 = res1 * fac[cnt1[i]] % MOD;   //求出第一关键字非严格递增序列的数量
        if(cnt2[i] > 1)
            res2 = res2 * fac[cnt2[i]] % MOD;   //求出第二关键字非严格递增序列的数量
    }
    bool flag = true;   //序列的两个关键字是否可能同时有序
    for(int i=1; i<n; i++)
    {
        if(p[i].second > p[i+1].second)
        {
            flag = false;
            break;
        }
    }
    LL ans;
    if(flag)
    {
        LL res3 = 1;
        for(auto &it: cnt3)
        {
            if(it.second > 1)
                res3 = res3 * fac[it.second] % MOD;
        }
        ans = ((fac[n] - res1 - res2 + res3) % MOD + MOD) % MOD;  //容斥，总数减去集合1减去集合2加上集合12的交集
    }
    else
        ans = ((fac[n] - res1 - res2) % MOD + MOD) % MOD;
    printf("%lld\n",ans);
    return 0;
}
