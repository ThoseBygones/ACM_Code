#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXM 1005
#define INF 0x3f3f3f3f

int level[MAXN];    //层次网络
int flow[MAXN][MAXN];   //容量网络（可行流量）
int vis[MAXM];  //记录猪圈被哪个顾客打开过
int pigs[MAXM]; //记录每个猪圈里面猪的数量
int maxflow;    //最大流
int m,n;

int bfs()
{
    queue <int> q;
    memset(level,-1,sizeof(level));
    level[n+1]=0;
    q.push(n+1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<=n+1; i++)
        {
            if(level[i]==-1 && flow[i][u])
            {
                level[i]=level[u]+1;
                q.push(i);
            }
        }
        if(u==0)
            return 1;
    }
    return 0;
}

int dfs(int u,int f)    //前驱、前向弧
{
    if(u==n+1)
        return f;
    int tempf=f;
    int tf;
    for(int i=0; i<=n+1 && tempf; i++)
    {
        if(level[i]+1==level[u] && flow[u][i])
        {
            tf=dfs(i,min(flow[u][i],tempf));
            flow[u][i]-=tf;
            flow[i][u]+=tf;
            tempf-=tf;
        }
    }
    return f-tempf;
}

void Dinic()
{
    maxflow=0;
    while(bfs())
        maxflow+=dfs(0,INF);
}

int main()
{
    int k,a,b;
    scanf("%d%d",&m,&n);
    memset(flow,0,sizeof(flow));
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=m; i++)
        scanf("%d",&pigs[i]);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a);
        for(int j=1; j<=a; j++)
        {
            scanf("%d",&k);
            if(!vis[k])
                flow[0][i]+=pigs[k];
            else
                flow[vis[k]][i]=INF; //若该猪圈已被打开过，则可以考虑从别的猪圈把猪调整到这个猪圈中
            vis[k]=i;   //记录最后一个访问该猪圈的顾客编号
        }
        scanf("%d",&b);
        flow[i][n+1]=b; //所有客户结点都与汇点相连
    }
    Dinic();
    printf("%d\n",maxflow);
    return 0;
}
