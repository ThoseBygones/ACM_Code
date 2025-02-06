/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-02-06
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dfs判环
 ********************************************************************************
 *  Algo-Description:
 * > 建图，将每个约束看做一条有向边：点 a -> b，权值为 d；反向边为点 b -> a，权值为 -d。
 * > 问题转化为一个图论问题，如果要满足所有约束，那么如果图中存在环，则所有的环上的边权值和应为 0（若只存在自环则环上的边权值和必定为 0）。
 * > dfs 遍历所有点，检查是否存在环，存在环则判断每个环边权值和是否为 0。
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

const int MAXN = 200005;

vector<PII> e[MAXN];
LL d[MAXN];
bool vis[MAXN];
int n, m;
bool flag;

void dfs(int u)
{
    vis[u] = 1;
    for(auto x: e[u])
    {
        int v = x.first, w = x.second;
        if(!vis[v]) //未构成环（自环不算），则继续往下遍历
        {
            d[v] = d[u] + w;
            dfs(v);
        }
        else    //构成环，则判断该环的权值和是否为0
        {
            if(d[u] + w != d[v])    //该环的权值和不为0，说明存在冲突
            {
                flag = false;
                return ;
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; i++)
        {
            e[i].clear();
            d[i] = 0;
            vis[i] = 0;
        }
        for(int i = 1; i <= m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            e[u].PB(MP(v, w));
            e[v].PB(MP(u, -w));
        }
        flag = true;
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
                dfs(i);
            if(!flag)
                break;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
