/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:2025-02-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dfs判环 + bfs求环上最短路径
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
queue<int> q;
int d[MAXN];    //每个点到离Valeriu最近的环上点的距离
bool vis[MAXN];
int n, pos; //pos为离Valeriu最近的环上点

void dfs(int u, int fa) //dfs判环
{
    vis[u] = true;
    for(auto v: G[u])
    {
        if(~pos)    //已经找到最近的上环点了，则结束搜索
            return;
        if(v != fa)
        {
            if(!vis[v])
                dfs(v, u);
            else    //已经形成环，则第一个被重复访问的点就是离Valeriu最近的环上点
                pos = v;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        scanf("%d%d%d", &n, &a, &b);
        for(int i = 1; i <= n; i++)
        {
            G[i].clear();
            vis[i] = false;
            d[i] = INF;
        }
        for(int i = 1; i <= n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].PB(v);
            G[v].PB(u);
        }
        pos = -1;
        dfs(b, -1);
        q.push(pos);
        d[pos] = 0;
        while(!q.empty())   //bfs求各点到离Valeriu最近的环上点的距离
        {
            int u = q.front();
            q.pop();
            for(auto v: G[u])
            {
                if(d[v] == INF)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        puts(d[a] > d[b] ? "YES" : "NO");
    }
    return 0;
}
