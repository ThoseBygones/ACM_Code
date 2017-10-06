//Dinic最大流求二分图最大匹配
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 210
#define MAXE 100005
#define INF 0x3f3f3f3f

string a[105],t[105]; //Bus tickets, Trolleybus tickets
int n,m;

class Dinic
{
public:
    int d[MAXN];
    int head[MAXN],nxt[MAXE],cur[MAXN];
    struct Edge
    {
        int from,to,cap,flow;
        Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow) {}
        Edge() {}
    } e[MAXE];

    int s,t,cnt;
    int node;
    bool bfs()
    {
        for(int i = 0; i<=t; i++) d[i] = -1;
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(int i = head[x]; ~i; i = nxt[i])
            {
                Edge &ed = e[i];
                if(d[ed.to]==-1&&ed.cap>ed.flow)
                {
                    d[ed.to] = d[x]+1;
                    q.push(ed.to);
                }
            }
        }
        return d[t]!=-1;
    }
    int dfs(int x,int a)
    {
        if(x==t||a==0) return a;
        int flow = 0,f;
        for(; ~cur[x]; cur[x] = nxt[cur[x]])
        {
            Edge &ed = e[cur[x]];
            if(d[ed.to]==d[x]+1&&(f = dfs(ed.to,min(ed.cap-ed.flow,a)))>0)
            {
                flow+=f;
                ed.flow+=f;
                e[cur[x]^1].flow-=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }

    void init()
    {
        cnt = node = 0;
    }

    int maxFlow()
    {
        int flow = 0;
        while(bfs())
        {
            for(int i = 0; i<=t; i++) cur[i] = head[i];
            flow+=dfs(s,INF);
        }
        return flow;
    }

    void buildGraph()
    {
        s = 0;
        t = n+m+1;
        for(int i = 0; i<=t; i++) head[i] = -1;
    }

    void addEdge(int from,int to,int cap)
    {
        e[cnt] = Edge(from,to,cap,0);
        int tmp = head[from];
        head[from] = cnt;
        nxt[cnt++] = tmp;
        e[cnt] = Edge(to,from,0,0);
        tmp = head[to];
        head[to] = cnt;
        nxt[cnt++] = tmp;
    }
} dinic;

bool check1(int x,int y)
{
    int sum1=0,sum2=0;
    for(int i=0; i<3; i++)
        sum1+=a[x][i]-'0';
    for(int i=3; i<6; i++)
        sum2+=t[y][i]-'0';
    if(sum1==sum2)
        return true;
    return false;
}

bool check2(int x,int y)
{
    int sum1=0,sum2=0;
    for(int i=0; i<3; i++)
        sum1+=t[y][i]-'0';
    for(int i=3; i<6; i++)
        sum2+=a[x][i]-'0';
    if(sum1==sum2)
        return true;
    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=m; i++)
        cin >> t[i];
    dinic.init();
    dinic.buildGraph();
    for(int i=1; i<=n; i++)
        dinic.addEdge(dinic.s,i,1);   //bus tickets: 1~n
    for(int i=1; i<=m; i++)
        dinic.addEdge(n+i,dinic.t,1); //trolleybus tickets n+1~n+m
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(check1(i,j))
                dinic.addEdge(i,n+j,1);
            if(check2(i,j))
                dinic.addEdge(i,n+j,1);
        }
    }
    int res=dinic.maxFlow();
    cout << res << endl;
    for(int i=1; i<=n; i++)
    {
        int u=i;
        for(int j=dinic.head[u]; ~j; j=dinic.nxt[j])
        {
            int v=dinic.e[j].to;
            //puts("ok");
            if(dinic.e[j].flow>0)
            {
                if(check1(u,v-n))
                    cout << "AT " << a[u] << " " << t[v-n] << endl;
                else if(check2(u,v-n))
                    cout << "TA " << t[v-n] << " " << a[u] << endl;
            }
        }
    }
    return 0;
}



//匈牙利算法求二分图最大匹配
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

//Hungary（二分图最大匹配）算法（DFS版）

#define MAXN 205
#define MAXE 100005

//邻接矩阵
class Hungary_DFS
{
private:
    int g[MAXN][MAXN];
    int vis[MAXN];
    int mx[MAXN],my[MAXN];
    int n,m;
    int nx,ny;
    string a[MAXN],t[MAXN];

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

    bool check1(int x,int y)
    {
        int sum1=0,sum2=0;
        for(int i=0; i<3; i++)
            sum1+=a[x][i]-'0';
        for(int i=3; i<6; i++)
            sum2+=t[y][i]-'0';
        if(sum1==sum2)
            return true;
        return false;
    }

    bool check2(int x,int y)
    {
        int sum1=0,sum2=0;
        for(int i=3; i<6; i++)
            sum2+=a[x][i]-'0';
        for(int i=0; i<3; i++)
            sum1+=t[y][i]-'0';
        if(sum1==sum2)
            return true;
        return false;
    }

public:
    void init(int n,int m)
    {
        memset(g,0,sizeof(g));
        this -> n = n;
        this -> m = m;
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
        nx = ny = n + m;
        for(int i=1; i<=n; i++)
            cin >> a[i];
        for(int i=1; i<=m; i++)
            cin >> t[i];
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(check1(i,j))
                    g[i][j]=1;
                if(check2(i,j))
                    g[i][j]=1;
            }
        }
    }

    void solve()
    {
        cout << hungary() << endl;
        for(int i=1; i<=n; i++)
        {
            if(mx[i]!=-1)
            {
                if(check1(i,mx[i]))
                    cout << "AT" << " " << a[i] << " " << t[mx[i]] << endl;
                else if(check2(i,mx[i]))
                    cout << "TA" << " " << t[mx[i]] << " " << a[i] << endl;
            }
        }
    }
} hungaryDFS;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    hungaryDFS.init(n,m);
    hungaryDFS.buildGraph();
    hungaryDFS.solve();
    return 0;
}
