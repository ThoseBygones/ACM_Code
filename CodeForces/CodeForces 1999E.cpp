/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 前缀和 + 贪心
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

LL sum[MAXN];  //前缀和

int getCnt(int val)
{
    int cnt = 0;
    while(val > 0)
    {
        val /= 3;
        cnt++;
    }
    return cnt;
}

void init()
{
    for(int i = 1; i <= MAXN; i++)
        sum[i] = sum[i - 1] + getCnt(i);
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        LL ans = sum[r] - sum[l] + 2 * getCnt(l);
        printf("%lld\n", ans);
    }
    return 0;
}
