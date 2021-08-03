/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: BFS
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

const int MAXN = 100005;
const int MAXE = 200005;

int head[MAXN];
struct Edge
{
    int to, col, nxt;
    Edge() {}
    Edge(int to, int col, int nxt) : to(to), col(col), nxt(nxt) {}
} e[MAXE << 1];

vector<int> ans;
bool vis[MAXN];
int d[MAXN];
int cnt;
int n, m;

inline void addEdge(int u, int v, int c)
{
    e[cnt].to = v;
    e[cnt].col = c;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

void rbfs()
{
    memset(vis, false, sizeof(vis));
    queue<int> q;
    q.push(n);
    d[n] = 0;
    vis[n] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].to;
            if(!vis[v])
            {
                d[v] = d[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void bfs()
{
    memset(vis, false, sizeof(vis));
    queue<PII> q;
    queue<int> q2;
    vis[1] = true;
    for(int i = head[1]; ~i; i = e[i].nxt)  //找到与结点1相邻的点
    {
        int v = e[i].to;
        if(d[v] == d[1] - 1)    //如果是rbfs过程中结点1的前一步，则bfs过程的下一步可以考虑
            q.push(MP(v, e[i].col));
    }
    while(!q.empty())
    {
        int minc = INF;
        while(!q.empty())
        {
            int v = q.front().first, c = q.front().second;
            q.pop();
            if(c < minc)    //发现更小的颜色，清空队列
            {
                while(!q2.empty())
                    q2.pop();
                minc = c;
            }
            if(c == minc)   //颜色一样，则都入队，下一步均可选
                q2.push(v);
        }
        ans.PB(minc);
        while(!q2.empty())
        {
            int u = q2.front();
            q2.pop();
            if(!vis[u])
            {
                vis[u] = true;
                for(int i = head[u]; ~i; i = e[i].nxt)
                {
                    int v = e[i].to;
                    if(d[v] == d[u] - 1)    //如果是rbfs过程中结点v的前一步，则bfs过程的下一步可以考虑
                        q.push(MP(v, e[i].col));
                }
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 0; i < m; i++)
        {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            addEdge(u, v, c);
            addEdge(v, u, c);
        }
        ans.clear();
        rbfs();
        bfs();
        printf("%d\n", d[1]);
        for(int i = 0; i < ans.size(); i++)
            printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));
    }
    return 0;
}
