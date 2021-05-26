/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 数论（质因数分解） + 规律
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 200000;

vector<int> prime[MAXN + 5];

void getfac(int val)
{
    for(int i = 2; i * i <= val; i++)
    {
        if(val % i == 0)
        {
            int cnt = 0;
            while(val % i == 0)
            {
                cnt++;
                val /= i;
            }
            prime[i].PB(cnt);
        }
    }
    if(val > 1)
        prime[val].PB(1);
}

LL quickPow(LL x, LL k)
{
    LL res = 1;
    while(k > 0)
    {
        if(k & 1)
            res *= x;
        x *= x;
        k >>= 1;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        getfac(x);
    }
    LL ans = 1;
    for(int i = 2; i <= MAXN; i++)
    {
        if(prime[i].size() == n)
        {
            sort(prime[i].begin(), prime[i].end());
            ans *= quickPow(i, prime[i][1]);
        }
        else if(prime[i].size() == n - 1)
        {
            sort(prime[i].begin(), prime[i].end());
            ans *= quickPow(i, prime[i][0]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
