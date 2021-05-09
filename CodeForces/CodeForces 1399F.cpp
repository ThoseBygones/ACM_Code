/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-08
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 区间dp + 离散化
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

const int MAXN = 3005;

struct Segment
{
    int l, r;
} seg[MAXN];

int a[MAXN << 1];

int dp[MAXN << 1][MAXN << 1];   //dp[l][r]表示在区间[l, r]内中可以选择的最大线段数量

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &seg[i].l, &seg[i].r);
            a[++cnt] = seg[i].l;
            a[++cnt] = seg[i].r;
        }
        vector<int> v[MAXN << 1];   //记录离散化后对应区间的右端点
        //离散化
        sort(a + 1, a + 1 + cnt);
        cnt = unique(a + 1, a + 1 + cnt) - a - 1;   //去重
        for(int i = 0; i < n; i++)
        {
            seg[i].l = lower_bound(a + 1, a + 1 + cnt, seg[i].l) - a;   //更新离散化后的左端点
            seg[i].r = lower_bound(a + 1, a + 1 + cnt, seg[i].r) - a;   //更新离散化后的右端点
            v[seg[i].l].PB(seg[i].r);
        }
        for(int i = 0; i <= cnt; i++)
            fill(dp[i], dp[i] + 1 + cnt, 0);
        //区间dp
        for(int l = 0; l < cnt; l++)   //枚举区间长度
        {
            for(int i = 1; i + l <= cnt; i++)   //枚举区间左端点
            {
                int j = i + l;  //区间右端点
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); //把稍小的区间都包括进来
                int sum = 0;
                for(int r = 0; r < v[i].size(); r++)    //枚举区间中点（两个区间的合并点）
                {
                    int k = v[i][r];
                    if(k == j)  //区间全覆盖
                        sum++;
                    if(k < j)
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] += sum;
            }
        }
        printf("%d\n", dp[1][cnt]);
    }
    return 0;
}
