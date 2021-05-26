/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: bfs
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 1005;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int g[MAXN][MAXN];
int step[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m;

bool inMap(int x, int y)    //判断是否在地图范围内
{
    if(x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}

bool check(int x, int y)    //检查周围是否有与该格子颜色不同的格子
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inMap(nx, ny) && g[nx][ny] == g[x][y])
            return true;
    }
    return false;
}

void bfs()
{
    queue<PII> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(check(i, j))
            {
                q.push(MP(i, j));
                vis[i][j] = true;
                //step[i][j] = 0;
            }
        }
    }
    while(!q.empty())
    {
        PII cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(inMap(nx, ny) && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                step[nx][ny] = step[cur.first][cur.second] + 1;
                q.push(MP(nx, ny));
            }
        }
    }
}

int main()
{
    int q;
    scanf("%d%d%d", &n, &m, &q);
    char tmp[MAXN];
    for(int i = 0; i < n; i++)
    {
        scanf("%s", tmp);
        for(int j = 0; j < m; j++)
            g[i][j] = tmp[j] - '0';
    }
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%d ", g[i][j]);
        puts("");
    }*/
    bfs();
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%d ", step[i][j]);
        puts("");
    }*/
    while(q--)
    {
        int x, y;
        LL t;
        scanf("%d%d%lld", &x, &y, &t);
        x--, y--;
        if(vis[x][y] && step[x][y] <= t)   //该点在询问的时间点被影响
            printf("%d\n", g[x][y] ^ ((t - step[x][y]) & 1));
        else
            printf("%d\n", g[x][y]);
    }
    return 0;
}
