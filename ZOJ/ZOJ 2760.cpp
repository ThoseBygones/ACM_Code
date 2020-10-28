/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-20
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: ZOJ
 *  Algorithm: 最大流 dinic / sap 算法 + 最短路floyd算法
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
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

#define MAXN 105
#define MAXE 20010

class SAP_QuickVersion
{
private:
    struct Edge
    {
        int from,to,next,cap;
        Edge(int from,int to,int next,int cap):from(from),to(to),next(next),cap(cap) {}
        Edge() {}
    } e[MAXE];

    int cnt;
    int head[MAXN];
    int dep[MAXN];
    int gap[MAXN];//gap[x]=y :说明残留网络中dep[i]==x的个数为y

    int n;
    int node;  //node是总的点的个数，包括源点和汇点
    int G[MAXN][MAXN], dis[MAXN][MAXN];

    void addEdge(int u,int v,int w)
    {
        e[cnt].from=u;
        e[cnt].to=v;
        e[cnt].cap=w;
        e[cnt].next=head[u];
        head[u]=cnt++;
        e[cnt].from=v;
        e[cnt].to=u;
        e[cnt].cap=0;
        e[cnt].next=head[v];
        head[v]=cnt++;
    }

    void bfs(int st,int ed)
    {
        memset(dep,-1,sizeof(dep));
        memset(gap,0,sizeof(gap));
        gap[0] = 1;
        int que[MAXN];
        int fnt,rear;
        fnt = rear = 0;
        dep[ed] = 0;
        que[rear++] = ed;
        while(fnt != rear)
        {
            int u = que[fnt++];
            if(fnt == MAXN)
                fnt = 0;
            for(int i=head[u]; ~i; i=e[i].next)
            {
                int v = e[i].to;
                if(dep[v] != -1)
                    continue;
                que[rear++] = v;
                if(rear == MAXN)
                    rear = 0;
                dep[v] = dep[u] + 1;
                ++gap[dep[v]];
            }
        }
    }

    void floyd()
    {
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

public:
    void init(int n)
    {
        cnt = 0;
        this -> n = n;
    }

    int SAP(int st,int ed)
    {
        int res = 0;
        bfs(st,ed);
        int cur[MAXN];
        int S[MAXN];
        int top = 0;
        memcpy(cur,head,sizeof(head));
        int u = st;
        int i;
        while(dep[st] < node)
        {
            if(u == ed)
            {
                int temp = INF;
                int inser;
                for(i=0; i<top; i++)
                {
                    if(temp > e[S[i]].cap)
                    {
                        temp = e[S[i]].cap;
                        inser = i;
                    }
                }
                for(i=0; i<top; i++)
                {
                    e[S[i]].cap -= temp;
                    e[S[i]^1].cap += temp;
                }
                res += temp;
                top = inser;
                u = e[S[top]].from;
            }
            if(u != ed && gap[dep[u]-1] == 0) //出现断层，无增广路
                break;
            for(i=cur[u]; ~i; i=e[i].next)
            {
                if(e[i].cap != 0 && dep[u] == dep[e[i].to] + 1)
                    break;
            }
            if(i != -1)
            {
                cur[u] = i;
                S[top++] = i;
                u = e[i].to;
            }
            else
            {
                int Min = node;
                for(i=head[u]; ~i; i=e[i].next)
                {
                    if(e[i].cap == 0)
                        continue;
                    if(Min > dep[e[i].to])
                    {
                        Min = dep[e[i].to];
                        cur[u] = i;
                    }
                }
                --gap[dep[u]];
                dep[u] = Min+1;
                ++gap[dep[u]];
                if(u != st)
                    u = e[S[--top]].from;
            }
        }
        return res;
    }

    void buildGraph(int s, int t)
    {
        memset(head, -1, sizeof(head));
        node = n;
        for(int i = 0; i < n; i++)
        {
            if(dis[s][i] == INF)
                continue;
            for(int j = 0; j < n; j++)
            {
                if(i == j || G[i][j] == INF || dis[j][t] == INF)
                    continue;
                if(dis[s][t] == dis[s][i] + G[i][j] + dis[j][t])
                    addEdge(i, j, 1);
            }
        }
    }

    void solve()
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &G[i][j]);
                if(G[i][j] == -1)
                    G[i][j] = INF;
                if(i == j)
                    G[i][j] = 0;
                dis[i][j] = G[i][j];
            }
        }
        int s, t;
        scanf("%d%d", &s, &t);
        if(s == t)
            puts("inf");
        else
        {
            floyd();
            buildGraph(s, t);
            int ans = SAP(s, t);
            printf("%d\n", ans);
        }
    }
} sap;


class Dinic
{
private:
    int d[MAXN];
    int head[MAXN],nxt[MAXE],cur[MAXN];
    struct Edge
    {
        int from,to,cap,flow;
        Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow) {}
        Edge() {}
    } e[MAXE];

    int s,t,cnt;
    int n,m;
    int node;
    int G[MAXN][MAXN], dis[MAXN][MAXN];

    bool bfs()
    {
        for(int i = 0; i<=node; i++) d[i] = -1;
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(int i = head[x]; ~i; i = nxt[i])
            {
                Edge &ed = e[i];
                if(d[ed.to]==-1&&ed.cap>ed.flow)
                {
                    d[ed.to] = d[x]+1;
                    q.push(ed.to);
                }
            }
        }
        return d[t]!=-1;
    }
    int dfs(int x,int a)
    {
        if(x==t||a==0) return a;
        int flow = 0,f;
        for(; ~cur[x]; cur[x] = nxt[cur[x]])
        {
            Edge &ed = e[cur[x]];
            if(d[ed.to]==d[x]+1&&(f = dfs(ed.to,min(ed.cap-ed.flow,a)))>0)
            {
                flow+=f;
                ed.flow+=f;
                e[cur[x]^1].flow-=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }

    void addEdge(int from,int to,int cap)
    {
        e[cnt] = Edge(from,to,cap,0);
        int tmp = head[from];
        head[from] = cnt;
        nxt[cnt++] = tmp;
        e[cnt] = Edge(to,from,0,0);
        tmp = head[to];
        head[to] = cnt;
        nxt[cnt++] = tmp;
    }

    void floyd()
    {
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
public:
    void init(int n)
    {
        cnt = 0;
        this -> n = n;
    }

    int maxFlow()
    {
        int flow = 0;
        while(bfs())
        {
            for(int i = 0; i<=node; i++) cur[i] = head[i];
            flow+=dfs(s,INF);
        }
        return flow;
    }

    void buildGraph()
    {
        memset(head, -1, sizeof(head));
        node = n;
        for(int i = 0; i < n; i++)
        {
            if(dis[s][i] == INF)
                continue;
            for(int j = 0; j < n; j++)
            {
                if(i == j || dis[i][j] == INF || dis[j][t] == INF)
                    continue;
                if(dis[s][t] == dis[s][i] + G[i][j] + dis[j][t])
                    addEdge(i, j, 1);
            }
        }
    }

    void solve()
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &G[i][j]);
                if(G[i][j] == -1)
                    G[i][j] = INF;
                if(i == j)
                    G[i][j] = 0;
                dis[i][j] = G[i][j];
            }
        }
        scanf("%d%d", &s, &t);
        if(s == t)
            puts("inf");
        else
        {
            floyd();
            buildGraph();
            int ans = maxFlow();
            printf("%d\n", ans);
        }
    }
} dinic;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        //sap.init(n);
        //sap.solve();
        dinic.init(n);
        dinic.solve();
    }
    return 0;
}
