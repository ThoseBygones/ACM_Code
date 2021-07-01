/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-01
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 前缀和 + 前/后缀最大/小值
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

char s[MAXN];
int pre[MAXN], pre_max[MAXN], pre_min[MAXN];  //前缀和、前缀和最大值、前缀和最小值
int suf_max[MAXN], suf_min[MAXN];   //后缀最大值、后缀最小值

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s", s + 1);
        for(int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + (s[i] == '+' ? 1 : -1);
            pre_max[i] = max(pre_max[i - 1], pre[i]);
            pre_min[i] = min(pre_min[i - 1], pre[i]);
        }
        suf_max[n + 1] = suf_min[n + 1] = 0;
        for(int i = n; i; i--)
        {
            suf_max[i] = max(0, suf_max[i + 1] + (s[i] == '+' ? 1 : -1));
            suf_min[i] = min(0, suf_min[i + 1] + (s[i] == '+' ? 1 : -1));
        }
        while(m--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int Max = max(0, pre_max[l - 1]);
            int Min = min(0, pre_min[l - 1]);
            Max = max(Max, pre[l - 1] + suf_max[r + 1]);
            Min = min(Min, pre[l - 1] + suf_min[r + 1]);
            printf("%d\n", Max - Min + 1);
        }
    }
    return 0;
}
