/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-28
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

map<LL, int> mp;
vector<int> prime;
bool vis[MAXN];

void init() //预处理出所有的素数
{
    for(int i = 2; i < MAXN; i++)
    {
        if(!vis[i])
        {
            prime.PB(i);
            for(int j = i * 2; j < MAXN; j += i)
                vis[j] = true;
        }
    }
}

int main()
{
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    LL ans = 0;
    for(int i = 1; i <= n; i++)
    {
        vector<PII> v;  //记录分解后的底数和幂数
        int val;
        scanf("%d", &val);
        if(val == 1)
            v.PB(MP(1, 1));
        else
        {
            for(int j = 0; j < prime.size() && prime[j] <= val; j++)
            {
                int cnt = 0;
                while(val % prime[j] == 0)
                {
                    cnt++;
                    val /= prime[j];
                }
                if(cnt % k)
                    v.PB(MP(prime[j], cnt % k));
            }
        }
        LL sum1 = 1, sum2 = 1;
        for(PII p: v)
        {
            for(int j = 1; j <= k - p.second; j++)  //计算这个数要凑成x^k还需要补上的值
                sum1 *= p.first;
            for(int j = 1; j <= p.second; j++)  //计算这个数从而帮别的数凑成x^k能提供的值
                sum2 *= p.first;
        }
        if(sum1 <= 1e5) //需要的的值不太大，可能有别的数能补上（因为ai<=1e5）（该判断没有也罢，不会导致TLE）
            ans += mp[sum1];
        mp[sum2]++;
    }
    printf("%lld\n", ans);
    return 0;
}
