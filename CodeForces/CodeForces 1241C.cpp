/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-20
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 二分 + 贪心
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

int p[MAXN];
int n, x, y;
LL a, b, k;
LL lcm;

bool check(LL val)
{
    //printf("val: %d\n", val);
    LL sum = 0;
    int pos = 1;
    for(LL i = lcm; i <= val; i += lcm)    //先从比率最高的开始贪心
        sum += 1LL * p[pos++] / 100 * (x + y);
    //printf("1. %lld\n",sum);
    for(LL i = a; i <= val; i += a) //再从x%和y%中比率高的开始贪心
    {
        if(i % lcm) //lcm的倍数不重复计算
            sum += 1LL * p[pos++] / 100 * x;
    }
    //printf("2. %lld\n",sum);
    for(LL i = b; i <= val; i += b) //在从x%和y%中比率低的开始贪心
    {
        if(i % lcm) //lcm的倍数不要重复计算
            sum += 1LL * p[pos++] / 100 * y;
    }
    //printf("-> %lld\n",sum);
    return sum >= k;
}

int main()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        sort(p + 1, p + 1 + n, greater<int>());
        scanf("%d%lld%d%lld%lld", &x, &a, &y, &b, &k);
        if(x < y)
        {
            swap(x, y);
            swap(a, b);
        }
        lcm = a * b / __gcd(a, b);
        //printf("lcm: %d\n",lcm);
        LL l = 1, r = n, ans = -1;
        while(l <= r)   //二分售出的票数
        {
            LL mid = (l + r) >> 1;
            if(check(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
