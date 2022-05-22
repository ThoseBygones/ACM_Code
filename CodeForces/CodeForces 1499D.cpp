/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-20
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 数论
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

const int MAXN = 20000005;

vector<int> prime;
int cnt[MAXN];  //cnt[i]表示i的素因子种类数
bool vis[MAXN];

void init()
{
    cnt[1] = 0;
    for(int i = 2; i < MAXN; i++)
    {
        if(!vis[i])
        {
            prime.PB(i);
            cnt[i] = 1;
        }
        for(int j = 0; j < prime.size() && i * prime[j] < MAXN; j++)
        {
            vis[i * prime[j]] = true;
            if(i % prime[j] == 0)
            {
                cnt[i * prime[j]] = cnt[i];
                break;
            }
            cnt[i * prime[j]] = cnt[i] + 1;
        }
    }
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int c, d, x;
        scanf("%d%d%d", &c, &d, &x);
        LL ans = 0;
        for(int gcd = 1; sqr(gcd) <= x; gcd++) //枚举 gcd(a,b) 的值
        {
            if(x % gcd == 0)
            {
                int tmp = x / gcd + d;
                if(tmp % c == 0)
                    ans += 1LL << cnt[tmp / c]; //每一个数 p 或 q（p * q = (x / gcd + d) / c）的贡献为 2 ^ cnt[(x / gcd + d) / c]
                if(sqr(gcd) != x)
                {
                    tmp = x / (x / gcd) + d;
                    if(tmp % c == 0)
                        ans += 1LL << cnt[tmp / c]; //如果 p 和 q 不等，则两个数的值分别累加
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
