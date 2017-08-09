#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 55
#define MAXE MAXN*MAXN*MAXN*MAXN

//邻接表
class Hungary_DFS
{
private:
    int head[MAXN*MAXN];
    struct Edge
    {
        int to,next;
        Edge(int to,int next):to(to),next(next) {}
        Edge() {}
    } e[MAXE];

    char f[MAXN][MAXN];
    int id[MAXN][MAXN];
    int mx[MAXN*MAXN],my[MAXN*MAXN];
    int vis[MAXN*MAXN];
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
    void init(int r,int c)
    {
        cnt = 0;
        n = r;
        m = c;
    }

    int hungary()
    {
        int res = 0;
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        for(int i = 1; i < nx; i++)
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
        memset(id,0,sizeof(id));
        for(int i=0; i<n; i++)
            scanf("%s",f[i]);
        nx=1;
        for(int i=0; i<n; i++)
        {
            bool flag=false;    //是否连续标记
            for(int j=0; j<m; j++)
            {
                if(f[i][j]=='*')
                {
                    id[i][j]=nx;
                    if(!flag)
                        flag=true;
                }
                else
                {
                    if(flag)
                    {
                        flag=false;
                        nx++;
                    }
                }
            }
            if(flag)
                nx++;
        }
        ny=1;
        for(int j=0; j<m; j++)
        {
            bool flag=false;
            for(int i=0; i<n; i++)
            {
                if(f[i][j]=='*')
                {
                    if(id[i][j])
                        addEdge(id[i][j],ny);
                    if(!flag)
                        flag=true;
                }
                else
                {
                    if(flag)
                    {
                        flag=false;
                        ny++;
                    }
                }
            }
            if(flag)
                ny++;
        }
        /*for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cout << id[i][j] << " ";
            puts("");
        }*/
    }
} hungaryDFS;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    hungaryDFS.init(n,m);
    hungaryDFS.buildGraph();
    int ans=hungaryDFS.hungary();
    printf("%d\n",ans);
    return 0;
}
