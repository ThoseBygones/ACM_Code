/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-08
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
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

int G[10][10];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }
    if(n < 7)   //点数小于7时点的序号对应骨牌的点数
        printf("%d\n", m);
    else
    {
        int ans = INF;
        for(int i = 1; i <= 7; i++) //枚举重复使用骨牌点数的点
        {
            for(int j = 1; j <= 7; j++)
            {
                int cnt = 0;    //无法放骨牌的边数
                for(int k = 1; k <= 7; k++) //枚举与它们相连的点
                {
                    if(G[i][k] && G[j][k])
                        cnt++;
                }
                ans = min(ans, cnt);
            }
        }
        printf("%d\n", m - ans);
    }
    return 0;
}
