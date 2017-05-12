#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 125
#define MAXE 15005


//适于稠密图，DFS找增广路快


//邻接矩阵
class Hungary_DFS
{
private:
    int g[MAXN][MAXN];
    int vis[MAXN];
    int mx[MAXN],my[MAXN];
    int n,m;
    int nx,ny;

    bool dfs(int u)
    {
        for(int v = 1; v <= ny; v++)
        {
            if(!vis[v] && g[u][v])
            {
                vis[v] = true;
                if(my[v] == -1 || dfs(my[v]))
                {
                    my[v] = u;
                    mx[u] = v;
                    return true;
                }
            }
        }
        return false;
    }

public:
    void init(int a,int b)
    {
        n = a;
        m = b;
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
    }

    int hungary()
    {
        int res = 0;
        for(int i = 1; i <= nx; i++)
        {
            if(mx[i] == -1)
            {
                memset(vis, 0, sizeof(vis));
                if(dfs(i))
                    res++;
            }
        }
        return res;
    }

    void buildGraph()
    {
        nx = ny = n;
        memset(g,0,sizeof(g));
        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u][v]=1;
        }
    }
} hungaryDFS;

int main()
{
    int t;
    int n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        hungaryDFS.init(n,m);
        hungaryDFS.buildGraph();
        int ans=n-hungaryDFS.hungary(); //最小边覆盖数 = n - 匹配数
        printf("%d\n",ans);
    }
    return 0;
}



#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 125
#define MAXE 15005

//邻接表
class Hungary_DFS
{
private:
    int head[MAXN];
    struct Edge
    {
        int to,next;
        Edge(int to,int next):to(to),next(next) {}
        Edge() {}
    } e[MAXE];

    int mx[MAXN],my[MAXN];
    int vis[MAXN];
    int n,m;
    int nx,ny;
    int cnt;

    void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }


    bool dfs(int u)
    {
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!vis[v])
            {
                vis[v] = true;
                if(my[v] == -1 || dfs(my[v]))
                {
                    my[v] = u;
                    mx[u] = v;
                    return true;
                }
            }
        }
        return false;
    }

public:
    void init(int a,int b)
    {
        cnt = 0;
        n = a;
        m = b;
    }

    int hungary()
    {
        int res = 0;
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        for(int i = 1; i <= nx; i++)
        {
            if(mx[i] == -1)
            {
                memset(vis, 0, sizeof(vis));
                if(dfs(i))
                    res++;
            }
        }
        return res;
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        nx = ny = n;
        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
        }
    }
} hungaryDFS;

int main()
{
    int t;
    int n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        hungaryDFS.init(n,m);
        hungaryDFS.buildGraph();
        int ans=n-hungaryDFS.hungary(); //最小边覆盖数 = n - 匹配数
        printf("%d\n",ans);
    }
    return 0;
}



#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 125
#define MAXE 15005

//STL
class Hungary_DFS
{
private:
    vector <int> G[MAXN];
    int vis[MAXN];
    int mx[MAXN],my[MAXN];
    int n,m;
    int nx,ny;

    bool dfs(int u)
    {
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(!vis[v])
            {
                vis[v] = true;
                if(my[v] == -1 || dfs(my[v]))
                {
                    my[v] = u;
                    mx[u] = v;
                    return true;
                }
            }
        }
        return false;
    }

public:
    void init(int a,int b)
    {
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        n = a;
        m = b;
    }

    int hungary()
    {
        int res = 0;
        for(int i = 1; i <= nx; i++)
        {
            if(mx[i] == -1)
            {
                memset(vis, 0, sizeof(vis));
                if(dfs(i))
                    res++;
            }
        }
        return res;
    }

    void buildGraph()
    {
        nx = ny = n;
        for(int i=1; i<=n; i++)
            G[i].clear();
        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
    }
} hungaryDFS;

int main()
{
    int t;
    int n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        hungaryDFS.init(n,m);
        hungaryDFS.buildGraph();
        int ans=n-hungaryDFS.hungary(); //最小边覆盖数 = n - 匹配数
        printf("%d\n",ans);
    }
    return 0;
}
