/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-21
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 数论 + 埃式筛法变形
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

const int MAXN = 10000005;

int sum[MAXN], ans[MAXN];

void init()
{
    fill(ans, ans + MAXN, INF);
    for(int i = 1; i < MAXN; i++)
    {
        for(int j = i; j < MAXN; j += i)
            sum[j] += i;
    }
    for(int i = 1; i < MAXN; i++)
    {
        if(sum[i] < MAXN)
            ans[sum[i]] = min(ans[sum[i]], i);
    }
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        if(ans[n] == INF)
            puts("-1");
        else
            printf("%d\n", ans[n]);
    }
    return 0;
}
