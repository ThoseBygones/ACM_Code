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

#define MAXN 1005
#define MAXE 100005


//适于稠密图，DFS找增广路快


//邻接矩阵
class Hungary_DFS
{
private:
    int g[MAXN][MAXN];
    int vis[MAXN];
    int mx[MAXN],my[MAXN];
    int n,k;

    bool dfs(int u)
    {
        for(int v = n+1; v <= 2*n; v++)
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
    void init(int n,int k)
    {
        this -> n = n;
        this -> k = k;
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
    }

    int hungary()
    {
        int res = 0;
        for(int i = 1; i <= n; i++)
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
        {
            int temp;
            scanf("%d",&temp);
            for(int j=temp; j<=n; j+=k)
                g[i][j+n]=g[j+n][i]=1;
        }
    }
} hungaryDFS;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        hungaryDFS.init(n,k);
        hungaryDFS.buildGraph();
        int ans=hungaryDFS.hungary();
        //printf("%d\n",ans);
        if(ans==n)
            puts("Jerry");
        else
            puts("Tom");
    }
    return 0;
}
