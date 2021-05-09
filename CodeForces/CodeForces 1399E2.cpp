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
    int v, w, c;
    Edge() {}
    Edge(int v, int w, int c) : v(v), w(w), c(c) {}
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
priority_queue<EdgeSum> pq[2];
LL pref[2][MAXN * 20];   //操作次数的前缀和（1e5 * log(1e6)）
int t[2];
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
        int v = G[u][i].v, w = G[u][i].w, c = G[u][i].c;
        if(v != fa)
        {
            dfs(v, u);
            cnt[u] += cnt[v];   //累加子结点的数量（路径数）
            sum += (LL)cnt[v] * w;  //累加权值和
            if(c == 1)
                pq[0].push(EdgeSum(w, cnt[v]));
            else
                pq[1].push(EdgeSum(w, cnt[v]));
        }
    }
}

void solve(int flag, LL s)
{
    while(!pq[flag].empty())
    {
        EdgeSum tmp = pq[flag].top();
        pq[flag].pop();
        pref[flag][++t[flag]] = (LL)tmp.cnt * (tmp.w - tmp.w / 2);  //记录减少量（除以2后向下取整）
        pref[flag][t[flag]] += pref[flag][t[flag] - 1]; //维护前缀和
        if(sum - pref[flag][t[flag]] <= s)
            break;
        if(tmp.w / 2)
            pq[flag].push(EdgeSum(tmp.w / 2, tmp.cnt));    //再次入队
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        LL s;
        scanf("%d%lld", &n, &s);
        for(int i = 0; i <= n; i++)
        {
            G[i].clear();
            cnt[i] = 0;
        }
        while(!pq[0].empty())
            pq[0].pop();
        while(!pq[1].empty())
            pq[1].pop();
        sum = 0;
        for(int i = 1; i < n; i++)
        {
            int u, v, w, c;
            scanf("%d%d%d%d", &u, &v, &w, &c);
            G[u].PB(Edge(v, w, c));
            G[v].PB(Edge(u, w, c));
        }
        dfs(1, -1);
        t[0] = t[1] = 0;
        pref[0][0] = pref[1][0] = 0;
        solve(0, s);
        solve(1, s);
        if(sum <= s)
        {
            puts("0");
            continue;
        }
        //printf("%d %d %d\n", sum, pref[0][t[0]], pref[1][t[1]]);
        int ans = INF;
        for(int i = 0; i <= t[0]; i++)  //枚举花费为1的操作次数
        {
            LL left = sum - pref[0][i];    //花费为1的当前剩余量
            int l = 0, r = t[1];    //二分花费为2的操作次数
            int pos = 0x3f3f3f3f;
            while(l <= r)
            {
                int mid = (l + r) >> 1;
                if(left - pref[1][mid] <= s)
                {
                    pos = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            ans = min(ans, i + pos * 2);
        }
        printf("%d\n", ans);
    }
    return 0;
}
