///POJ 3159
///此题为最基本最经典的最短路中的差分约束系统问题（给定一定数量的约束条件，求最短路）！！！

///第一次尝试，使用队列优化的spfa，即queue+spfa(spfa+bfs)
///提交至OJ，测试结果：TLE
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
#define N 30005
#define M 150005
using namespace std;

int n,m;
int head[N],dis[N],vis[N];

struct candies
{
    int u;
    int v;
    int w;
    int next;
} c[M];

void spfa()
{
    queue<int> q;
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
        dis[i]=INF;
    dis[1]=0;
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x]; i!=-1; i=c[i].next)
        {
            int y=c[i].v;
            int z=c[i].w;
            if(dis[y]>dis[x]+z)
            {
                dis[y]=dis[x]+z;
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
    }
}

int main()
{
    //while(~scanf("%d%d",&n,&m))
    while(cin >> n >> m)
    {
        for(int i=1; i<=n; i++)
            head[i]=-1;
        for(int i=1; i<=m; i++)
        {
            cin >> c[i].u >> c[i].v >> c[i].w;
            //scanf("%d%d%d",&c[i].u,&c[i].v,&c[i].w);
            c[i].next=head[c[i].u];
            head[c[i].u]=i;
        }
        spfa();
        //printf("%d\n",dis[n]);
        cout << dis[n] << endl;
    }
    return 0;
}

///包括尝试不使用memset、尝试使用scanf代替cin优化以加速，结果仍然TLE！！！


///第二次尝试，使用堆栈优化的spfa，即stack+spfa(spfa+dfs)
///提交至OJ，测试结果：AC
///G++提交结果：Memory: 2952 KB  Time: 516 ms
///C++提交结果：Memory: 2568 KB  Time: 735 ms
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define INF 0x3f3f3f3f
#define N 30005
#define M 150005
using namespace std;

int n,m;
int head[N],dis[N],vis[N];

struct candies
{
    int u;
    int v;
    int w;
    int next;
} c[M];

void spfa()
{
    stack<int> s;
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
        dis[i]=INF;
    dis[1]=0;
    s.push(1);
    vis[1]=1;
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        vis[x]=0;
        for(int i=head[x]; i!=-1; i=c[i].next)
        {
            int y=c[i].v;
            int z=c[i].w;
            if(dis[y]>dis[x]+z)
            {
                dis[y]=dis[x]+z;
                if(!vis[y])
                {
                    vis[y]=1;
                    s.push(y);
                }
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    //while(cin >> n >> m)
    {
        for(int i=1; i<=n; i++)
            head[i]=-1;
        for(int i=1; i<=m; i++)
        {
            //cin >> c[i].u >> c[i].v >> c[i].w;
            scanf("%d%d%d",&c[i].u,&c[i].v,&c[i].w);
            c[i].next=head[c[i].u];
            head[c[i].u]=i;
        }
        spfa();
        printf("%d\n",dis[n]);
        //cout << dis[n] << endl;
    }
    return 0;
}
///注意：使用cin仍然结果为TLE，但是使用scanf以后结果为AC！！！
