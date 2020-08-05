/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-08-04
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

char s[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m;

bool inMap(int x, int y)
{
    if(x >= 0 && y >= 0 && x < n && y < m)
        return true;
    return false;
}

void dfs(int x, int y)
{
    vis[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inMap(nx, ny) && !vis[nx][ny] && s[nx][ny] == '#')
            dfs(nx, ny);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", s[i]);
    bool wrow = false, wcol = false;    //是否存在全白的行和列
    for(int i = 0; i < n; i++)
    {
        int bcnt = 0;   //该行黑色格子数量
        bool black = false;  //是否已经出现过黑色格子
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == '#')
            {
                bcnt++;
                if(j && black && s[i][j - 1] != '#') //如果该行之前的格子有黑色格子且黑色格子不连续
                {
                    puts("-1");
                    return 0;
                }
                black = true;
            }
        }
        if(!bcnt)   //该行没有黑色格子
            wrow = true;
    }
    for(int j = 0; j < m; j++)
    {
        int bcnt = 0;   //该列黑色格子数量
        bool black = false;  //是否已经出现过黑色格子
        for(int i = 0; i < n; i++)
        {
            if(s[i][j] == '#')
            {
                bcnt++;
                if(i && black && s[i - 1][j] != '#') //如果该列之前的格子有黑色格子且黑色格子不连续
                {
                    puts("-1");
                    return 0;
                }
                black = true;
            }
        }
        if(!bcnt)   //该列没有黑色格子
            wcol = true;
    }
    //printf("wrow:%d wcol:%d\n", wrow, wcol);
    if(wrow ^ wcol)   //出现全白行（列），但未出现全白的列（行）
    {
        puts("-1");
        return 0;
    }
    int ans = 0;    //连通块数量
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == '#' && !vis[i][j])
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
