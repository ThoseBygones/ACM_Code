/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-08
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dfs + 贪心 + 暴力枚举
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

const int MAXN = 100005;

struct Edge
{
    int v, w;
    Edge() {}
    Edge(int v, int w) : v(v), w(w) {}
} e[MAXN << 1];

struct EdgeSum
{
    int w, cnt;
    EdgeSum() {}
    EdgeSum(int w, int cnt) : w(w), cnt(cnt) {}
    bool operator < (const EdgeSum &es) const
    {
        return (LL)cnt * (w - w / 2) < (LL)es.cnt * (es.w - es.w / 2);
    }
};

vector<Edge> G[MAXN];
int cnt[MAXN];
priority_queue<EdgeSum> pq;
LL sum;

void dfs(int u, int fa)
{
    if(G[u].size() == 1 && ~fa)   //走到了叶子结点
    {
        cnt[u] = 1;
        return ;
    }
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].v, w = G[u][i].w;
        if(v != fa)
        {
            dfs(v, u);
            cnt[u] += cnt[v];   //累加子结点的数量（路径数）
            sum += (LL)cnt[v] * w;  //累加权值和
            pq.push(EdgeSum(w, cnt[v]));
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
        LL s;
        scanf("%d%lld", &n, &s);
        for(int i = 0; i <= n; i++)
        {
            G[i].clear();
            cnt[i] = 0;
        }
        while(!pq.empty())
            pq.pop();
        sum = 0;
        for(int i = 1; i < n; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].PB(Edge(v, w));
            G[v].PB(Edge(u, w));
        }
        dfs(1, -1);
        int ans = 0;
        while(sum > s)
        {
            EdgeSum tmp = pq.top();
            pq.pop();
            sum -= (LL)tmp.cnt * (tmp.w - tmp.w / 2);   //除以2后向下取整
            ans++;
            pq.push(EdgeSum(tmp.w / 2, tmp.cnt));    //再次入队
        }
        printf("%d\n", ans);
    }
    return 0;
}
