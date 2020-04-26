/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-26
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 数学规律
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

const int d[4] = {0, 2, 3, 1};

LL cal1(LL val) //计算出每个triple的a
{
    LL tmp = 1;
    while(tmp < val)
    {
        val -= tmp;
        tmp <<= 2;
    }
    return tmp + val - 1;
}

LL cal2(LL x, LL val) //计算出每个triple的b
{
    int tmp = 0;
    LL res = 0;
    while(x)
    {
        res += (1LL << tmp) * d[x % 4];
        tmp += 2;
        x >>= 2;
    }
    return res;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL n;
        scanf("%lld", &n);
        LL gid = (n - 1) / 3 + 1;  //计算出n属于哪个的triple
        LL sid = (n - 1) % 3;  //计算出n在该triple内是第几个
        LL a = cal1(gid);
        LL b = cal2(a, gid);
        LL c = a ^ b;
        if(!sid)
            printf("%lld\n", a);
        else if(sid == 1)
            printf("%lld\n", b);
        else
            printf("%lld\n", c);
    }
    return 0;
}
