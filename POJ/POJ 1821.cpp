/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-13
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 单调队列优化dp
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
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

const int MAXM = 105;
const int MAXN = 16005;

int q[MAXN];    //单调队列（维护最大值）
int dp[MAXM][MAXN]; //dp[i][j]表示前i个工人完成前j块木板的粉刷任务分配（其中可能有木板不粉刷）后能得到的最大收入

struct Person
{
    int l, p, s;
    Person() {}
    Person(int l, int p, int s) : l(l), p(p), s(s) {}
    bool operator < (const Person &p) const
    {
        return s < p.s;
    }
} per[MAXM];

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= m; i++)
        {
            int l, p, s;
            scanf("%d%d%d", &l, &p, &s);
            per[i] = Person(l, p, s);
        }
        sort(per + 1, per + 1 + m);
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 1; i <= m; i++) //枚举工人
        {
            int head = 1, tail = 0;
            for(int k = max(0, per[i].s - per[i].l); k < per[i].s; k++)    //枚举第i个工人刷到的木板区间左边界（左边界-1）
            {
                //使用单调队列找到使dp[i][k]+(j-k)*per[i].p最大的k值
                //由于j不变时，j*per[i].p相当于常数项，故只维护使dp[i][k]-k*per[i].p的最大的k值
                while(head <= tail && dp[i - 1][q[tail]] - per[i].p * q[tail] < dp[i - 1][k] - per[i].p * k)
                    --tail;
                q[++tail] = k;
            }
            for(int j = 1; j <= n; j++) //枚举第i个工人刷到的木板区间右边界
            {
                //方案一：第j块木板不粉刷
                //方案二：第j块木板由第i-1个工人粉刷，之后的木板粉刷换工人
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                //方案三：第j块木板由第i个工人粉刷
                if(j >= per[i].s) //第i个工人确实刷到了第per[i].s块木板
                {
                    while(head <= tail && j - q[head] > per[i].l)   //第i个工人粉刷的跨度超过了p[i].l
                        ++head;
                    if(head <= tail)
                        dp[i][j] = max(dp[i][j], dp[i - 1][q[head]] + per[i].p * (j - q[head]));
                }
            }
        }
        printf("%d\n", dp[m][n]);
    }
    return 0;
}
