//最大团问题
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 205

//定理：V*为原图的最大团当且仅当V*为原图G的补图G-中的最大独立集

//邻接矩阵
class Hungary_DFS
{
private:
    int g[MAXN][MAXN];
    int vis[MAXN];
    int mx[MAXN],my[MAXN];
    int m;
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
    void init(int a,int b,int c)
    {
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        nx = a;
        ny = b;
        m = c;
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
        memset(g,1,sizeof(g));
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u][v]=0;  //求补图
        }
    }
} hungaryDFS;

int main()
{
    int kase=1;
    int g,b,m;
    while(~scanf("%d%d%d",&g,&b,&m))
    {
        if(g==0 && b==0 && m==0)
            break;
        hungaryDFS.init(g,b,m);
        hungaryDFS.buildGraph();
        int ans=(g+b)-hungaryDFS.hungary(); //二分图中：最大点独立数（独立集） == n - 最大匹配数
        printf("Case %d: %d\n",kase++,ans);
    }
    return 0;
}
