/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-16
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp + 数论（质因数分解）
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
const int MAXV = 10000005;

int a[MAXN], mp[MAXV];  //经过质因数分解并且去除幂次为偶数的因数之后映射到的新的值
int cnt[MAXV];  //每个数出现的次数（计数桶）
int l[MAXN][22];    //l[i][k]表示以位置i为结尾的段，之前修改的次数不超过k次时，该段向左延伸最远能够延伸到的位置（左端点）
int dp[MAXN][22];   //dp[i][k]表示前i个数修改不超过k次时，能划分出的最小段数

int divide(int x)
{
    int val = 1;
    for(int i = 2; i * i <= x; i++)
    {
        int cnt = 0;
        while(x % i == 0)
        {
            cnt++;
            x /= i;
        }
        if(cnt & 1)
            val *= i;
    }
    if(x > 1)
        val *= x;
    return val;
}

void pre(int n, int k)  //预处理l[][]数组
{
    for(int j = 0; j <= k; j++) //枚举修改次数
    {
        int rep_cnt = 0, pos = 1;   //重复次数、当前状态下能向左延伸到的最左端点
        for(int i = 1; i <= n; i++)
        {
            cnt[a[i]]++;
            if(cnt[a[i]] > 1)
                rep_cnt++;
            while(rep_cnt > j)  //修改次数超了，则用尺取法找到符合修改次数的最左端点
            {
                if(cnt[a[pos]] > 1)
                    rep_cnt--;
                --cnt[a[pos++]];
            }
            l[i][j] = pos;
        }
        while(pos <= n) //清空cnt数组（下次使用前清空）
            --cnt[a[pos++]];
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if(!mp[a[i]])
               mp[a[i]] = divide(a[i]);
            a[i] = mp[a[i]];
            for(int j = 0; j <= k; j++)
                dp[i][j] = l[i][j] = INF;
        }
        pre(n, k);
        /*for(int i = 1; i <= n; i++)
        {
            printf("a[i]: %d - ", a[i]);
            for(int j = 0; j <= k; j++)
                printf("%d ", l[i][j]);
            puts("");
        }*/
        for(int i = 1; i <= n; i++) //枚举位置
        {
            for(int j = 0; j <= k; j++) //枚举修改次数
            {
                for(int x = 0; x <= j; x++) //枚举当前段修改次数
                    dp[i][j] = min(dp[i][j], dp[l[i][x] - 1][j - x] + 1);   //dp[i][j]从当前段少修改x次的最佳方案中转移来（位置i修改）
            }
        }
        printf("%d\n", dp[n][k]);
    }
    return 0;
}
