#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXE 100005

int dx[4]= {-1,0,0,1};
int dy[4]= {0,-1,1,0};

//适于稠密图，DFS找增广路快
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

    int match[MAXN];
    int vis[MAXN];
    int n,m,k;
    int nx,ny;
    int cnt;
    int mp[MAXN][MAXN];
    int id[MAXN][MAXN];

    void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    bool inMap(int x,int y)
    {
        if(x>=1 && x<=n && y>=1 && y<=m)
            return true;
        return false;
    }

    bool dfs(int u)
    {
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!vis[v])
            {
                vis[v] = true;
                if(match[v] == -1 || dfs(match[v]))
                {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

public:
    void init(int a,int b,int c)
    {
        cnt = 0;
        n = a;
        m = b;
        k = c;
    }

    int hungary()
    {
        int res = 0;
        memset(match, -1, sizeof(match));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(!mp[i][j] && (i+j&1))
                {
                    memset(vis, 0, sizeof(vis));
                    if(dfs(id[i][j]))
                        res++;
                }
            }

        }
        return res;
    }

    void buildGraph()
    {
        memset(mp,0,sizeof(mp));
        memset(id,-1,sizeof(id));
        memset(head,-1,sizeof(head));
        for(int i=1; i<=k; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mp[x][y]=1;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(!mp[i][j])
                    id[i][j]=cnt++;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(!mp[i][j] && (i+j&1))    //只对i+j值为奇数的点进行处理
                {
                    for(int k=0; k<4; k++)
                    {
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(inMap(nx,ny) && !mp[nx][ny])
                            addEdge(id[i][j],id[nx][ny]);
                    }
                }
            }
        }
    }
} hungaryDFS;

int main()
{
    int n,m,k;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        scanf("%d",&k);
        hungaryDFS.init(n,m,k);
        hungaryDFS.buildGraph();
        int ans=hungaryDFS.hungary();
        printf("%d\n",ans);
    }
    return 0;
}
