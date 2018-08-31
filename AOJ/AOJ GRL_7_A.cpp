/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ:
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x)
{
    return x * x;
}
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 205
#define MAXE 20010

//Hungary（二分图最大匹配）算法（DFS版）
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
    void init(int nx,int ny,int m)
    {
        cnt = 0;
        this -> nx = nx;
        this -> ny = ny;
        this -> m = m;
    }

    int hungary()
    {
        int res = 0;
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
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
        memset(head,-1,sizeof(head));
        n = nx + ny;
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v+nx);
        }
    }

    void solve()
    {
        buildGraph();
        int ans = hungary();
        printf("%d\n",ans);
    }
} hungaryDFS;

int main()
{
    int nx,ny,m;
    scanf("%d%d%d",&nx,&ny,&m);
    hungaryDFS.init(nx,ny,m);
    hungaryDFS.solve();
    return 0;
}



//Hopcroft-Karp（二分图最大匹配）算法

/*将点二分图的点分成两个点集x,y；
首先从所有x的未匹配的点进行bfs，维护x，y距离标号dx,dy；
如果y点是未匹配的点那么就找到一条最短增广路，记录当前长度，大于该长度的结束bfs；
bfs完之后得到最短增广路集，用匈牙利算法对所有允许弧（dy[v]==dx[u]+1）进行增广。
*/

class HopcroftKarp
{
private:
    int head[MAXN];
    struct Edge
    {
        int to,next;
        Edge(int to,int next):to(to),next(next) {}
        Edge() {}
    } edge[MAXE];

    int nx,ny;  //对于要匹配的点，分为x集合的点和y集合的点。nx,ny为两集合中点的数量
    int node;   //总结点数量
    int cnt;
    int mx[MAXN],my[MAXN];  //mx表示与x配对的y编号,my表示与y配对的x编号。即Mx[i]的值表示x集合中i号点的匹配点，My[j]的值就是y集合j点匹配的点
    int dx[MAXN],dy[MAXN];    //这里就是bfs找增广路用的数组，对于u->v可达就有dy[v]=dx[u]+1；dy,dx表示在各自集合里的编号
    int vis[MAXN];  //寻找增广路的标记数组
    int dis;
    int m;


    void addEdge(int u,int v)
    {
        edge[cnt].to=v;
        edge[cnt].next=head[u];
        head[u]=cnt++;
    }

    bool bfs()   //寻找增广路径集，每次只寻找当前最短的增广路
    {
        queue <int> q;
        dis = INF;
        memset(dx,-1,sizeof(dx));
        memset(dy,-1,sizeof(dy));
        for(int i=0; i<nx; i++)
        {
            if(mx[i]==-1)   //将未遍历的节点入队，并初始化次节点距离为0
            {
                q.push(i);
                dx[i]=0;
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(dx[u]>dis)
                break;
            for(int i=head[u]; i!=-1; i=edge[i].next)
            {
                int v = edge[i].to;
                if(dy[v] == -1)
                {
                    dy[v] = dx[u] + 1;
                    if(my[v] == -1) //找到了一条增广路，dis为增广路终点的标号
                        dis = dy[v];
                    else
                    {
                        dx[my[v]] = dy[v]+1;
                        q.push(my[v]);
                    }
                }
            }
        }
        return dis!=INF;
    }

    bool dfs(int u)
    {
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v = edge[i].to;
            if(!vis[v] && dy[v]==dx[u]+1)   //如果该点没有被遍历过并且距离为上一节点+1
            {
                vis[v]=1;
                if(my[v]!=-1 && dy[v]==dis) //u已被匹配且已到所有存在的增广路终点的标号，再递归寻找也必无增广路，直接跳过
                    continue;
                if(my[v]==-1 || dfs(my[v])) //这里特别要注意，Mx[u] == -1 && dfs(u)先后顺序千万不能换，dfs之后Mx[u]就会变化
                {
                    my[v]=u;
                    mx[u]=v;
                    return true;
                }
            }
        }
        return false;
    }

public:
    void init(int nx,int ny,int m)
    {
        cnt = 0;
        memset(mx,-1,sizeof(mx));
        memset(my,-1,sizeof(my));
        this -> nx = nx;
        this -> ny = ny;
        this -> m = m;
    }

    int maxMatch()  //最大匹配
    {
        int ans = 0;
        while(bfs())
        {
            memset(vis,0,sizeof(vis));
            for(int i=0; i<nx; i++)
            {
                if(mx[i]==-1 && dfs(i))
                    ans++;
            }
        }
        return ans;
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        node = nx + ny;
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v+nx);
        }
    }

    void solve()
    {
        buildGraph();
        int ans = maxMatch();
        printf("%d\n",ans);
    }
} hk;

int main()
{
    int nx,ny,m;
    scanf("%d%d%d",&nx,&ny,&m);
    hk.init(nx,ny,m);
    hk.solve();
    return 0;
}
