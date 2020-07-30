/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-30
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 优先队列 / dp
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 2005;

/* 方法一：贪心 + 优先队列 */

LL a[MAXN], b[MAXN];

struct Problem
{
    LL l, len;
    Problem() {}
    Problem(LL l, LL len) : l(l), len(len) {}
    bool operator <(const Problem &p) const //解决用时时间长的题目优先
    {
        if(len == p.len)
            return l > p.l;
        return len < p.len;
    }
};

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &b[i]);
            b[i] += b[i - 1];
        }
        priority_queue<Problem> pq;
        LL cur_time = 0;
        for(int i = 1; i <= n; i++)
        {
            if(cur_time + a[i] <= b[i]) //这个问题能在Bob完成之前解出
            {
                pq.push(Problem(cur_time, a[i]));
                cur_time += a[i];
            }
            else if(!pq.empty())    //这个问题不能在Bob完成之前解出，但是之前有做过的题目可以反悔不做
            {
                Problem tmp = pq.top();
                if(cur_time + a[i] - tmp.len <= b[i])    //（反悔）选择不做之前解出的题目中用时最长的那个
                {
                    pq.pop();
                    cur_time -= tmp.len;
                    pq.push(Problem(cur_time, a[i]));
                    cur_time += a[i];
                }
            }
        }
        printf("%d\n", pq.size());
    }
    return 0;
}


/* 方法二：动态规划 */

LL dp[MAXN][MAXN]; //dp[i][j]表示对于前i题，Alice拿到j分时比对手少用的最大时间
LL a[MAXN], b[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &b[i]);
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                if(~dp[i - 1][j - 1])   //前一状态合法
                {
                    dp[i][j - 1] = max(dp[i][j - 1], dp[i - 1][j - 1] + b[i]);  //第i题不做
                    if(dp[i - 1][j - 1] >= a[i] - b[i])  //如果第i题做了能拿到分
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - (a[i] - b[i]));
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= n; i++)
        {
            if(~dp[n][i])
                ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}

