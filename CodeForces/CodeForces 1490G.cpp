/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 前缀和 + 二分
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

const int MAXN = 200005;

LL a[MAXN], sum[MAXN], Max[MAXN];
LL ans[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        Max[0] = -LINF;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
            Max[i] = max(Max[i - 1], sum[i]);
        }
        for(int i = 1; i <= m; i++)
        {
            LL x;
            scanf("%lld", &x);
            if(x <= Max[n]) //一轮一定可以找到这个值
                ans[i] = lower_bound(Max + 1, Max + 1 + n, x) - Max - 1;
            else
            {
                if(sum[n] <= 0) //永远找不到
                    ans[i] = -1;
                else    //需要好几轮才能找到
                {
                    LL k = (x - Max[n]) / sum[n] + ((x - Max[n]) % sum[n] ? 1 : 0);
                    //LL k = (x - Max[n] + sum[n] - 1) / sum[n];
                    //printf("k: %lld\n", k);
                    ans[i] = k * n;
                    ans[i] += lower_bound(Max + 1, Max + 1 + n, x - k * sum[n]) - Max - 1;
                }
            }
        }
        for(int i = 1; i <= m; i++)
            printf("%lld%c", ans[i], (i == m ? '\n' : ' '));
    }
    return 0;
}
