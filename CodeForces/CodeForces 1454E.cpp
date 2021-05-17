/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-16
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 拓扑排序找环 + dfs统计子树
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
vector<int> p;  //在环中的结点
bool inloop[MAXN];  //点是否在环中
int deg[MAXN];  //点的度数
int cnt[MAXN];

void topoSort(int n)    //拓扑排序找环
{
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 1)
            q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        deg[u]--;
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(--deg[v] == 1)
                q.push(v);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] > 1)
        {
            p.PB(i);
            inloop[i] = true;
        }
    }
}

void dfs(int u, int fa)
{
    cnt[u] = 1;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(v != fa && !inloop[v])   //该子结点不在环上
        {
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            G[i].clear();
            inloop[i] = false;
            deg[i] = 0;
        }
        p.clear();
        for(int i = 1; i <= n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].PB(v);
            G[v].PB(u);
            deg[u]++, deg[v]++;
        }
        topoSort(n);
        LL ans = 1LL * n * (n - 1); //假设所有点都在还上的结果
        for(auto u: p)   //遍历每个在环上的结点其不在环上子结点
        {
            dfs(u, u);
            //printf("cntu: %d\n", cnt[u]);
            ans -= 1LL * cnt[u] * (cnt[u] - 1) / 2; //计算其不在环上子树的大小
        }
        printf("%lld\n", ans);
    }
    return 0;
}
