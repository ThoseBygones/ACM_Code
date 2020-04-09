/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-31
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 最小生成树prim
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
#define MAXN 2005

LL g[MAXN][MAXN];
bool vis[MAXN];
int dis[MAXN];
int x[MAXN], y[MAXN], c[MAXN], k[MAXN];
int pre[MAXN];  //记录生成树的路径
int n;

LL getDis(int u, int v, int val)
{
    return 1LL * (abs(x[u] - x[v]) + abs(y[u] - y[v])) * val;
}

LL prim()
{
    for(int i = 0; i <= n; i++)
        dis[i] = g[0][i];
    vis[0] = true;
    dis[0] = 0;
    LL sum = 0;
    for(int i = 1; i <= n; i++)
    {
        int pos = -1;
        int Min = INF;
        for(int j = 0; j <= n; j++)
        {
            if(!vis[j] && dis[j] < Min)
            {
                Min = dis[j];
                pos = j;
            }
        }
        sum += Min;
        vis[pos] = true;
        for(int j = 0; j <= n; j++)
        {
            if(!vis[j] && g[pos][j] < dis[j])
            {
                dis[j] = g[pos][j];
                pre[j] = pos;
            }
        }
    }
    return sum;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &k[i]);
    for(int i = 1; i <= n; i++) //两个城市之间建边
    {
        for(int j = i + 1; j <= n; j++)
            g[i][j] = g[j][i] = getDis(i, j, k[i] + k[j]);
    }
    for(int i = 1; i <= n; i++) //每个城市和超级源点之间建边（表示在该城市建发电厂的费用）
        g[0][i] = c[i];
    LL ans = prim();
    vector<int> pg; //发电厂
    vector<PII> e;  //边集
    for(int i = 1; i <= n; i++)
    {
        if(!pre[i])
            pg.PB(i);
        else
            e.PB(MP(pre[i], i));
    }
    printf("%lld\n", ans);
    printf("%d\n", pg.size());
    for(int i = 0; i < pg.size(); i++)
        printf("%d%c", pg[i], (i == pg.size() - 1 ? '\n' : ' '));
    printf("%d\n", e.size());
    for(int i = 0; i < e.size(); i++)
        printf("%d %d\n", e[i].first, e[i].second);
    return 0;
}
