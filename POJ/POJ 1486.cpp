#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

//邻接矩阵
class Hungary_DFS
{
private:
    struct Slides
    {
        int xmin,xmax;
        int ymin,ymax;
    } s[MAXN];

    int g[MAXN][MAXN];
    int vis[MAXN];
    int mx[MAXN],my[MAXN];
    int n;
    int nx,ny;
    int save[MAXN]; //保存原图匹配的情况

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
    void init(int a)
    {
        n = a;
        nx = ny = n;
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
        memset(g,0,sizeof(g));
        for(int i=1; i<=n; i++)
            scanf("%d%d%d%d",&s[i].xmin,&s[i].xmax,&s[i].ymin,&s[i].ymax);
        for(int i=1; i<=n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            for(int j=1; j<=n; j++)
            {
                if(x>s[j].xmin && x<s[j].xmax && y>s[j].ymin && y<s[j].ymax)
                    g[i][j]=1;
            }
        }
    }

    bool deleteEdges()
    {
        for(int i=1; i<=n; i++)
            save[i]=my[i];  //记录匹配情况（每个y集中的点与x集中的哪个点匹配
        bool flag=false;
        for(int i=1; i<=n; i++)
        {
            g[save[i]][i]=0;  //删边
            if(hungary()==n) //再次求最大匹配，如果删除边以后最大匹配数没变，说明该边不是必须边
            {
                g[save[i]][i]=1;
                continue;
            }
            else
            {
                if(flag)
                    printf(" ");
                printf("(%c,%d)",'A'+i-1,save[i]);
                flag=true;
            }
            g[save[i]][i]=1;
        }
        if(flag)
            return true;
        return false;
    }
} hungaryDFS;

int main()
{
    int n;
    int kase=1;
    while(~scanf("%d",&n),n)
    {
        hungaryDFS.init(n);
        hungaryDFS.buildGraph();
        printf("Heap %d\n",kase++);
        int ans=hungaryDFS.hungary();
        bool flag=false;   //必须匹配的边数
        if(ans==n)
            flag=hungaryDFS.deleteEdges();
        if(!flag)
            printf("none");
        puts("");
        puts("");
    }
    return 0;
}
