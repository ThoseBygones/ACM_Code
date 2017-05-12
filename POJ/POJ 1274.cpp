#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 405
#define MAXE 40010

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
    int n;
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
        nx = a;
        ny = b;
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
        n = nx;
        for(int u=1; u<=n; u++)
        {
            int num;
            scanf("%d",&num);
            while(num--)
            {
                int v;
                scanf("%d",&v);
                addEdge(u,v);
            }
        }
    }
} hungaryDFS;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        hungaryDFS.init(n,m);
        hungaryDFS.buildGraph();
        int ans=hungaryDFS.hungary();
        printf("%d\n",ans);
    }
    return 0;
}
