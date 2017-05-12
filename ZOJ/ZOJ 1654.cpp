#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1255
#define MAXE 1600005

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

    char g[55][55];
    int row[55][55];    //记录每行能放机器人的区域数
    int col[55][55];    //记录每列能放机器人的区域数
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
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i=0; i<n; i++)
            scanf("%s",g[i]);
        nx = 1; //每行中的每个可放区域放入x集
        ny = 1; //每列中的每个可放区域放入y集
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(g[i][j]=='o' && !row[i][j])
                {
                    for(int k=j; k<m && g[i][k]!='#'; k++)
                        row[i][k]=nx;
                    nx++;
                }
                if(g[i][j]=='o' && !col[i][j])
                {
                    for(int k=i; k<n && g[k][j]!='#'; k++)
                        col[k][j]=ny;
                    ny++;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(g[i][j]=='o' && row[i][j] && col[i][j])
                    addEdge(row[i][j],col[i][j]);
            }
        }
    }
} hungaryDFS;

int main()
{
    int t;
    int kase=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        hungaryDFS.init(n,m);
        hungaryDFS.buildGraph();
        int ans=hungaryDFS.hungary();
        printf("Case :%d\n%d\n",kase++,ans);
    }
    return 0;
}
