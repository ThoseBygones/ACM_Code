#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 205
#define MAXM 2005
#define INF 0x3f3f3f3f

//STL
class Hungary_DFS
{
private:
    vector <int> G[MAXM];
    int vis[MAXM];
    int mx[MAXM],my[MAXM];
    int n,m,l;
    int nx,ny;
    int d[MAXN][MAXN];
    int p[MAXM];
    int t[MAXM];

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

    void floyd()
    {
        for(int k = 0; k < n; k++)
        {
            d[k][k] = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

public:
    void init(int n,int m,int l)
    {
        this -> n = n;
        this -> m = m;
        this -> l = l;
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));

    }

    int hungary()
    {
        int res = 0;
        for(int i = 0; i < nx; i++)
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
        nx = l;
        for(int i=0; i<=2*l; i++)
            G[i].clear();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                d[i][j]=INF;
        }
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            d[u][v]=d[v][u]=min(d[u][v],w);
        }
        floyd();
        for(int i=0; i<l; i++)
            scanf("%d%d",&p[i],&t[i]);
        for(int i=0; i<l; i++)
        {
            for(int j=0; j<l; j++)
            {
                if(i!=j && t[i]+d[p[i]][p[j]]<=t[j])
                {
                    G[i].push_back(j+l);
                    G[j+l].push_back(i);
                }
            }
        }
    }
} hungaryDFS;

int main()
{
    int n,m,l;
    while(~scanf("%d%d%d",&n,&m,&l))
    {
        if(n==0 && m==0 && l==0)
            break;
        hungaryDFS.init(n,m,l);
        hungaryDFS.buildGraph();
        int ans=hungaryDFS.hungary();
        printf("%d\n",l-ans);   //二分图最小点覆盖 = n - 最大匹配数
    }
    return 0;
}
