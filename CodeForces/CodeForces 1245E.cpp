/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-09
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 概率dp / 数学期望
 ********************************************************************************
 *  Algo-Description:
 * > 把地图上的点依次编号为1~100，起点为100，终点为1。
 * > to[]数组表示从to[i]号点爬梯子能到达i号点。
 * > dp[i]表示i号点到1号点的期望步数（数学期望）。
 *   > 当 2 <= i <= 6 时，状态转移方程为 dp[i] = 6 / (i - 1) * (1 + SIGMA(dp[j])) (1 <= j < i)
 *   > 当 7 <= i <= 100时，状态转移方程为 dp[i] = 1 + 1 / 6 * (SIGMA(min(dp[i-j], dp[to[i-j]]))) (1 <= j <= 6)
 *   > 即如果目标在6步以内，直接计算数学期望；6步以外计算下一步走1-6步（不包括走梯子和走梯子两种方案最小值）的数学期望。
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 105

int to[MAXN];   //该点可以直通哪一点
double dp[MAXN];    //dp[i]表示从位置i到位置1（终点）的期望步数

int getId(int x, int y)
{
    if(x & 1)   //奇数行
        return (x - 1) * 10 + y;
    else //偶数行
        return x * 10 + 1 - y;
}

int main()
{
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            int val;
            scanf("%d", &val);
            int id = getId(i, j);   //计算梯子的终点
            to[id] = getId(i - val, j); //计算梯子的起点
        }
    }
    for(int i = 2; i <= 6; i++)
    {
        for(int j = 1; j < i; j++)
            dp[i] += dp[j];
        dp[i] = (dp[i] + 6.0) / (i - 1);
    }
    for(int i = 7; i <= 100; i++)
    {
        for(int j = 1; j <= 6; j++)
            dp[i] += (min(dp[i-j], dp[to[i-j]]) + 1.0) / 6.0;
    }
    printf("%.10f\n", dp[100]);
    return 0;
}
