/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-15
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 位运算 + Floyd算法求最小环
 ********************************************************************************
 *  Algo-Description:
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
#define MAXN 100005

LL a[MAXN];
int vis[65];    //2^60 > 1e18
int G[65<<1][65<<1];    //若长度为3的环不存在，则此图最多有61*2个点
int d[65<<1][65<<1];

int main()
{
    int n;
    scanf("%d",&n);
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        LL val;
        scanf("%lld",&val);
        if(val) //去掉值为0的点，因为值为0的结点必定是孤立的
            a[cnt++] = val;
    }

    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<=60; j++)
        {
            LL b = a[i] >> j;
            if(b & 1)
                vis[j]++;
        }
    }
    for(int i=0; i<=60; i++)
    {
        if(vis[i] >= 3)
        {
            puts("3");
            return 0;
        }
    }
    for(int i=0; i<cnt; i++)
    {
        for(int j=i+1; j<cnt; j++)
        {
            if(a[i] & a[j])
                G[i][j] = G[j][i] = d[i][j] = d[j][i] = 1;
            else
                G[i][j] = G[j][i] = d[i][j] = d[j][i] = INF;
        }
    }
    /*Floyd算法求最短路（最小环）*/
    int ans = INF;
    for(int k=0; k<cnt; k++)
    {
        //从k点回到k点的最小环
        for(int i=0; i<k; i++)
        {
            if(G[i][k] == INF)
                continue;
            for(int j=i+1; j<k; j++)
            {
                if(d[i][j] == INF || G[k][j] == INF)
                    continue;
                ans = min(ans,d[i][j]+G[i][k]+G[k][j]);
            }
        }
        //Floyd更新最短路
        for(int i=0; i<cnt; i++)
        {
            if(d[i][k] == INF)
                continue;
            for(int j=0; j<cnt; j++)
            {
                if(d[k][j] == INF)
                    continue;
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    if(ans == INF)
        puts("-1");
    else
        printf("%d\n",ans);
    return 0;
}
