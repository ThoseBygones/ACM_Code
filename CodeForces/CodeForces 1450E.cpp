/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-29
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 并查集判断二分图 + Floyd 求解差分约束
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

const int MAXN = 205;

int g[MAXN][MAXN];  //邻接矩阵
int fa[MAXN << 1];

int findSet(int x)
{
    if(x != fa[x])
        return fa[x] = findSet(fa[x]);
    return fa[x];
}

void unionSet(int x, int y)
{
    int fx = findSet(x);
    int fy = findSet(y);
    if(fx != fy)
        fa[fx] = fy;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n * 2; i++)
        fa[i] = i;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i != j)
                g[i][j] = INF;
        }
    }
    bool flag = false;
    for(int i = 0; i < m; i++)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        if(d)   //1 <= a[v] - a[u] <= 1
        {
            g[u][v] = 1;    //a[v] - a[u] <= 1 => u -> v
            g[v][u] = -1;   //a[v] - a[u] >= 1 => a[u] - a[v] <= -1 => v -> u
        }
        else    //-1 <= a[v] - a[u] <= 1 && a[u] != a[v]
        {
            g[u][v] = 1;    //a[v] - a[u] <= 1 => u -> v
            g[v][u] = 1;    //a[v] - a[u] >= -1 => a[u] - a[v] <= 1 => v -> u
        }
        unionSet(u, v + n);
        unionSet(v, u + n);
    }
    for(int i = 1; i <= n; i++)
    {
        //if(fa[i] == fa[i + n])    //也能AC
        if(findSet(i) == findSet(i + n))
        {
            puts("NO");
            return 0;
        }
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
    }
    int ans = -INF, id = -1;
    for(int i = 1; i <= n; i++)
    {
        if(g[i][i] < 0) //floyd判断是否存在负环
        {
            puts("NO");
            return 0;
        }
        for(int j = 1; j <= n; j++)
        {
            if(g[i][j] > ans)
            {
                ans = g[i][j];
                id = i;
            }
        }
    }
    puts("YES");
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++)
        printf("%d%c", g[id][i], (i == n ? '\n' : ' '));
    return 0;
}
