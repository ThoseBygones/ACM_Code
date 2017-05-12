#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 205
#define MAXM 205
#define INF 0x3fffffff

struct Edge
{
    int to;
    int next;
    int cap;
} edge[MAXM*MAXM];

int head[MAXN]; //前向星
int level[MAXN];    //层数
int num;    //边的数目
int n,m;
int ans;

void addEdge(int u,int v,int w)
{
    edge[num].to=v;
    edge[num].cap=w;
    edge[num].next=head[u];
    head[u]=num++;
}

void init()
{
    num=0;
    memset(head,-1,sizeof(head));
}

bool bfs()
{
    queue <int> q;
    memset(level,-1,sizeof(level));
    level[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap>0 && level[v]==-1)   //流量不为零（是前向弧）且弧的终点未被标记过
            {
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    if(level[n]!=-1)
        return true;
    return false;
}

int dfs(int u,int flow)
{
    if(u==n)    //把流推到了T节点（汇点）,结束
        return flow;
    int tempf=0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(level[u]+1==level[v] && edge[i].cap>0)   //1.倒序追踪找前一个点；2.流量不为负
        {
            int f=dfs(v,min(edge[i].cap,flow-tempf));  //可行流流量为整个增广路中最小的弧的增量
            edge[i].cap-=f;
            edge[i^1].cap+=f;
            tempf+=f;
        }
    }
    return tempf;
}

void Dinic()
{
    while(bfs())
        ans+=dfs(1,INF);
}

int main()
{
    int kase=1;
    int t;
    while(~scanf("%d%d",&m,&n)) //排水沟条数、排水沟交点数
    {
        init();
        ans=0;
        for(int i=0; i<m; i++)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            addEdge(x,y,c);
            addEdge(y,x,0);
        }
        Dinic();
        printf("%d\n",ans);
    }
    return 0;
}
