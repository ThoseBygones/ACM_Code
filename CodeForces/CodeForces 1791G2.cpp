/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-01-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 排序 + 前缀和 + 二分查找
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

PII p[MAXN];
LL presum[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, c;
        scanf("%d%d", &n, &c);
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            p[i] = MP(min(x + i, x + n + 1 - i), x + i);    //<min(从0点出发再传送的代价, 从n+1点出发再传送的代价), 第一次选择该点从0点出发的代价>
        }
        sort(p + 1, p + 1 + n); //对每个点按最小代价排序
        for(int i = 1; i <= n; i++)
            presum[i] = presum[i - 1] + p[i].first;   //对每个点从0点或从n+1点出发两种选择的最小代价求前缀和
        int ans = 0;
        for(int i = 1; i <= n; i++) //枚举第一次出发（从0点出发）到达的点
        {
            if(p[i].second <= c)    //该点可以选择
            {
                int l = 0, r = n, res = 0;   //二分查找前缀和结束的位置
                while(l <= r)
                {
                    int mid = (l + r) >> 1;
                    LL sum = presum[mid];
                    if(i <= mid)    //第一次出发到达的点已经被计算在该方案中了
                        sum -= p[i].first;
                    if(p[i].second + sum <= c)
                    {
                        res = mid;
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                }
                //printf("%d:%d->",i,res);
                if(res >= i)    //如果第一次出发（从0点出发）到达的点被包括了
                    res--;  //去掉重复计数
                ans = max(ans, res + 1);    //加上第一次出发的次数
            }
            //printf("\n");
        }
        printf("%d\n", ans);
    }
    return 0;
}
