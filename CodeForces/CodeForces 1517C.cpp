/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:2023-09-06
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
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

const int MAXN = 505;

const int dx[2] = {0, 1};
const int dy[2] = {-1, 0};

int a[MAXN][MAXN];
int n;

void dfs(int x, int y, int val, int step)
{
    a[x][y] = val;
    if(step == val)
        return ;
    for(int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(a[nx][ny] == 0 && nx <= n && ny > 0)
        {
            //printf("-> %d %d\n", nx, ny);
            dfs(nx, ny, val, step + 1);
            break;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        dfs(i, i, x, 1);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            printf("%d%c", a[i][j], j == i ? '\n' : ' ');
    }
    return 0;
}
