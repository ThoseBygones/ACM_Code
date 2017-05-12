//邻接矩阵+DFS+收缩顶点
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

int edge[MAXN][MAXN];
int vis[MAXN];
int dfn[MAXN];
int low[MAXN];
int cnt[MAXN];
int index;
int num;
int n,m;

void tarjan(int u,int fa)
{
    vis[u]=1;
    dfn[u]=low[u]=++index;
    for(int v=1; v<=n; v++)
    {
        if(edge[u][v])
        {
            if(!vis[v])
            {
                tarjan(v,u);
                low[u]=min(low[u],low[v]);
            }
            else
            {
                if(v!=fa)
                    low[u]=min(low[u],dfn[v]);
            }
        }
    }
}

int main()
{
    int u,v;
    while(~scanf("%d%d",&n,&m))
    {
        memset(edge,0,sizeof(edge));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(vis,0,sizeof(vis));
        index=0;
        num=0;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u][v]=edge[v][u]=1;
        }
        tarjan(1,-1);
        memset(cnt,0,sizeof(cnt));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(edge[i][j])
                {
                    if(low[i]!=low[j])
                        cnt[low[j]]++;
                }
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(cnt[i]==1)
                ans++;
        }
        printf("%d\n",(ans+1)/2);
    }
    return 0;
}


//堆栈+DFS+收缩顶点（？？？没看懂！！！）
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

vector<int> vec[MAXN];
stack<int> S;
int dfn[MAXN], low[MAXN], step;
int id[MAXN], scc;

void init()
{
    while(!S.empty())
        S.pop();

    step = 0;
    scc = 1;
    for(int i = 0; i < MAXN; i++)
    {
        id[i] = -1;
        vec[i].clear();
        dfn[i] = low[i] = -1;
    }
}

void addEdge(int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

void tarjan_scc(int n, int father)
{
    dfn[n] = low[n] = ++step;
    S.push(n);
    int flag = 0;
    for(int i = 0; i < vec[n].size(); i++)
    {
        int son = vec[n][i];
        if(son == father && !flag)
        {
            flag = 1;
            continue;
        }

        if(dfn[son] == -1)
        {
            tarjan_scc(son, n);
            low[n] = min(low[n], low[son]);
        }
        else
            low[n] = min(low[n], dfn[son]);
    }

    if(low[n] == dfn[n])
    {
        int tmp;
        do
        {
            tmp = S.top();
            id[tmp] = scc;
            //    cout << tmp << " ";
            S.pop();
        }
        while(!S.empty() && tmp != n);
        scc++;
        //cout << endl << "---------------" << endl;
    }
}

void deal_scc(int n, int &sol)
{
    int u, v;
    int du[MAXN] = {0};
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            u = i, v = vec[i][j];
            if(id[u] == id[v])
                continue;
            else
            {
                du[id[v]]++;
                du[id[u]]++;
            }
        }
    }
    int sum = 0;
    for(int i = 1; i < scc; i++)
    {
        if(du[i] == 2)
            sum++;
    }
    sol = (sum + 1) / 2;
}

int main(void)
{
    int n, m;
    while(scanf("%d %d", &n, &m) == 2)
    {
        init();
        int u, v;
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            addEdge(u, v);
        }
        tarjan_scc(1, 1);
        int sol;
        deal_scc(n, sol);
        printf("%d\n", sol);
    }
    return 0;
}
