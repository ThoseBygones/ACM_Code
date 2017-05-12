#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 505
#define MAXE 250010

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

    struct Scheme
    {
        int t;
        int a,b,c,d;
        Scheme(int t,int a,int b,int c,int d):t(t),a(a),b(b),c(c),d(d) {}
        Scheme() {}
    } s[MAXN];

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

    int dis(int i,int j)
    {
        if(i==j)
            return abs(s[j].c-s[i].a)+abs(s[j].d-s[i].b);
        return abs(s[j].a-s[i].c)+abs(s[j].b-s[i].d);
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
    void init(int x)
    {
        cnt = 0;
        n = x;
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
        for(int i=1; i<=n; i++)
        {
            int h,m;
            scanf("%d:%d %d %d %d %d",&h,&m,&s[i].a,&s[i].b,&s[i].c,&s[i].d);
            s[i].t=h*60+m;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(s[i].t+dis(i,i)+dis(i,j)<s[j].t)    //题目要求at least one minute before the new ride's scheduled departure
                    addEdge(i,j);
            }
        }
    }
} hungaryDFS;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        hungaryDFS.init(n);
        hungaryDFS.buildGraph();
        int ans=n-hungaryDFS.hungary(); //最小路径覆盖 = 点数n - 最大匹配数
        printf("%d\n",ans);
    }
    return 0;
}
