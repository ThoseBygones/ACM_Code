/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-10-16
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 蛇形填数
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

const int MAXN = 55;
const int dx[4] = {1, 0, -1, 0};    //下右上左
const int dy[4] = {0, 1, 0, -1};

int a[MAXN][MAXN];
int n;

void dfs(int x, int y, int flag, int l, int r)
{
    if(flag)
        a[x][y] = l++;
    else
        a[x][y] = r--;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx > 0 && nx <= n && ny > 0 && ny <= n && !a[nx][ny])
        {
            dfs(nx, ny, flag ^ 1, l, r);
            break;  //可以有也可以没有，不影响结果
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                a[i][j] = 0;
        }
        dfs(1, 1, 1, 1, n * n);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                printf("%d%c", a[i][j], j == n ? '\n' : ' ');
        }
    }
    return 0;
}
