/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-01-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm:
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

const int MAXN = 1005;

const int dx[4] = {0, 1, 0, -1}; //left, down, right, up
const int dy[4] = {-1, 0, 1, 0};

bool vis[MAXN][MAXN];
int a[MAXN][MAXN];
int n, m;

bool inMap(int x, int y)
{
    if(x >= 1 && x <= n & y >= 1 && y <= m)
        return true;
    return false;
}

int bfs(int x, int y)
{
    queue<PII> q;
    int sum = 0;
    vis[x][y] = true;
    q.push(MP(x, y));
    while(!q.empty())
    {
        PII x = q.front();
        q.pop();
        sum += a[x.first][x.second];
        for(int i = 0; i < 4; i++)
        {
            int nx = x.first + dx[i];
            int ny = x.second + dy[i];
            if(inMap(nx, ny) && !vis[nx][ny] && a[nx][ny])
            {
                vis[nx][ny] = true;
                q.push(MP(nx, ny));
            }
        }
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                vis[i][j] = false;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(!vis[i][j] && a[i][j])
                    ans = max(ans, bfs(i, j));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
