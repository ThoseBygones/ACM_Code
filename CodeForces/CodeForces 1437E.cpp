/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-08
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 差分数组 + dp(LIS) + 分段处理
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

const int MAXN = 500005;

int a[MAXN], b[MAXN];
int dp[MAXN];   //LIS数组

int solve(int l, int r)
{
    int cnt = 0;
    dp[++cnt] = a[l];
    for(int i = l + 1; i < r; i++)
    {
        if(a[i] >= dp[cnt])
            dp[++cnt] = a[i];
        else
        {
            int pos = upper_bound(dp + 1, dp + 1 + cnt, a[i]) - dp; //二分找到下标
            if(pos != 1)    //第一个位置不能改
                dp[pos] = a[i];
        }
    }
    int pos = upper_bound(dp + 1, dp + 1 + cnt, a[r]) - dp;
    return r - l + 1 - pos;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] -= i;
    }
    a[0] = -INF, a[n + 1] = INF;
    for(int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    b[0] = 0, b[m + 1] = n + 1;
    bool flag = true;
    int ans = 0;
    for(int i = 0; i <= m; i++)
    {
        if(a[b[i]] > a[b[i + 1]])   //不能修改的序列不是升序
        {
            flag = false;
            break;
        }
        ans += solve(b[i], b[i + 1]);
    }
    if(flag)
        printf("%d\n", ans);
    else
        puts("-1");
    return 0;
}
