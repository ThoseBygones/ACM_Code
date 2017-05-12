#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005
#define MAXE 10005

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
    int n,k;
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
        k = b;
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
        while(k--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
        }
    }
} hungaryDFS;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    hungaryDFS.init(n,k);
    hungaryDFS.buildGraph();
    int ans=hungaryDFS.hungary();
    printf("%d\n",ans);
    return 0;
}
