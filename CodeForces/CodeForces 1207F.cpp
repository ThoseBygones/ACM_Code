/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-18
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 分块
 ********************************************************************************
 *  Algo-Description:
 * > 按照模数i分块，即某个 x % i == y，i <= sqrt(500000)
 * > 第一种操作：单点修改。
 *   > 可以直接修改，同时维护这个数x对i取模的余数的变化（i <= sqrt(500000)）。
 * > 第二种操作：区间查询。
 *   > 如果给定的 x <= sqrt(500000)，则直接得到之前预处理过的结果；
 *   > 如果 x > sqrt(500000)，则直接枚举所有的i（由于枚举时步长为x，循环次数不会超过sqrt(500000)。
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
#define MAXN 710

LL a[500005];
LL block[MAXN][MAXN];   //block[i][j]表示模i余j的数的值

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(t == 1)
        {
            a[x] += y;
            for(int i=1; i<MAXN; i++)
                block[i][x%i] += y;
        }
        else if(t == 2)
        {
            if(x < MAXN)
                printf("%lld\n",block[x][y]);
            else
            {
                LL ans = 0;
                for(int i=y; i<=500000; i+=x)   //循环次数小于等于sqrt(500000)
                    ans += a[i];
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
