#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <map>
using namespace std;

#define INF 0x3f3f3f3f
#define PII pair
#define MP make_pair
#define LL long long
#define PB push_back
#define MOD 1000000007

#define MAXN 55
#define MAXM 2510


//适于稠密图，DFS找增广路快


//邻接矩阵
class Hungary_DFS
{
private:
    int g[MAXM][MAXM];
    int vis[MAXM];
    int mx[MAXM],my[MAXM];
    int n,m;
    int nx,ny;
    char mp[MAXN][MAXN];
    int x[MAXN][MAXN];
    int y[MAXN][MAXN];

    bool dfs(int u)
    {
        for(int v = 1; v < ny; v++)
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
    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
    }

    int hungary()
    {
        int res = 0;
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
        memset(g,0,sizeof(g));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        for(int i=0; i<n; i++)
            scanf("%s",mp[i]);
        getX();
        getY();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mp[i][j]=='*')
                    g[x[i][j]][y[i][j]]=1;
            }
        }
    }

    void getX()
    {
        nx=1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mp[i][j]=='*')
                    x[i][j]=nx;
                if(mp[i][j]=='#')
                    nx++;
            }
            nx++;
        }
    }

    void getY()
    {
        ny=1;
        for(int j=0; j<m; j++)
        {
            for(int i=0; i<n; i++)
            {
                if(mp[i][j]=='*')
                    y[i][j]=ny;
                if(mp[i][j]=='#')
                    ny++;
            }
            ny++;
        }
    }
} hungaryDFS;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        hungaryDFS.init(n,m);
        hungaryDFS.buildGraph();
        int ans=hungaryDFS.hungary();
        printf("%d\n",ans);
    }
    return 0;
}
