/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-09-03
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: dfs
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

const int MAXN = 15;

int vis[MAXN];
int ans[MAXN];
int n, cnt;

bool check(int row)
{
    for(int i = 1; i < row; i++)    //之前几行斜线方向和横线方向是否已经有皇后
    {
        if(abs(row - i) == abs(vis[row] - vis[i]) || vis[row] == vis[i])
            return false;
    }
    return true;
}

void dfs(int row)
{
    if(row > n)
    {
        cnt++;
        return ;
    }
    for(int i = 1; i <= n; i++)
    {
        vis[row] = i;
        if(check(row))
            dfs(row + 1);
    }
}

int main()
{
    for(n = 1; n <= 10; n++)
    {
        cnt = 0;
        dfs(1);
        ans[n] = cnt;
    }
    while(~scanf("%d", &n), n)
        printf("%d\n", ans[n]);
    return 0;
}
