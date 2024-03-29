/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: DFS
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

const int MAXN = 105;

char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m;

bool inMap(int x, int y)
{
    if(x > 0 && x <= n && y > 0 && y <= m)
        return true;
    return false;
}

void dfs(int x, int y)
{
    for(int dx = -1; dx <= 1; dx++)
    {
        for(int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx, ny = y + dy;
            if(inMap(nx, ny) && g[nx][ny] == '@' && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        if(!n && !m)
            break;
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i++)
            scanf("%s", g[i] + 1);
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(g[i][j] == '@' && !vis[i][j])
                {
                    cnt++;
                    vis[i][j] = true;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
