/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: BFS + 贪心
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

const int MAXN = 300005;

int head[MAXN];

struct Edge
{
    int to, nxt;
    Edge() {}
    Edge(int to, int nxt) : to(to), nxt(nxt) {}
} e[MAXN << 1];

bool vis[MAXN];
bool live[MAXN];    //该点是否已经住人
int cnt, node, ans;

inline void addEdge(int u, int v)
{
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    vis[x] = true;
    node++; //结点数
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        bool flag = true;   //该点是否可以住老师
        for(int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].to;
            if(live[v])
                flag = false;
            if(!vis[v])
            {
                node++;
                vis[v] = true;
                q.push(v);
            }
        }
        if(flag)
        {
            ans++;  //可以住的老师数量增加
            live[u] = true;
        }
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
        cnt = ans = node = 0;
        for(int i = 1; i <= n; i++)
        {
            head[i] = -1;
            vis[i] = live[i] = false;
        }
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        bfs(1);
        if(node == n)   //全图连通
        {
            puts("YES");
            printf("%d\n", ans);
            bool flag = false;
            for(int i = 1; i <= n; i++)
            {
                if(live[i])
                {
                    if(flag)
                        printf(" %d", i);
                    else
                        printf("%d", i);
                    flag = true;
                }
            }
            puts("");
        }
        else
            puts("NO");
    }
    return 0;
}
