/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-30
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: bfs + dfs + dp
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

const int MAXN = 200005;

vector<int> G[MAXN];
int d[MAXN];
bool vis[MAXN];
int ans[MAXN];

void bfs(int n)
{
    queue<int> q;
    for(int i = 0; i <= n; i++)
    {
        d[i] = 0;
        vis[i] = false;
    }
    q.push(1);
    d[1] = 0;
    vis[1] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(!vis[v])
            {
                d[v] = d[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void dfs(int u)
{
    vis[u] = true;
    ans[u] = d[u];
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!vis[v] && d[u] < d[v])   //继续搜索
            dfs(v);
        if(d[u] < d[v]) //是否走符合d[v]>d[u]的一步，选择其中最优解
            ans[u] = min(ans[u], ans[v]);
        else    //是否走只能走一次的d[v]<d[u]的一步，选择其中的最优解
            ans[u] = min(ans[u], d[v]);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; i++)
            G[i].clear();
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].PB(v);
        }
        bfs(n);
        for(int i = 0; i <= n; i++)
            vis[i] = false;
        dfs(1);
        for(int i = 1; i <= n; i++)
            printf("%d%c", ans[i], (i == n ? '\n' : ' '));
    }
    return 0;
}
