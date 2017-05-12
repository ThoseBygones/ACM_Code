#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 20
#define MAXM 2005
#define INF 0x3fffffff

struct Edge
{
    int to;
    int next;
    int cap;
} edge[MAXM];

int head[MAXN]; //前向星
int cur[MAXN];  //优化当前弧
int level[MAXN];    //层数
int num;    //边的数目
int n,m;
int st,ed;
int ans;

void addEdge(int u,int v,int w)
{
    edge[num].to=v;
    edge[num].cap=w;
    edge[num].next=head[u];
    head[u]=num++;
    edge[num].to=u;
    edge[num].cap=0;
    edge[num].next=head[v];
    head[v]=num++;
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
    level[st]=0;
    q.push(st);
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
    if(level[ed]!=-1)
        return true;
    return false;
}

int dfs(int u,int flow)
{
    if(u==ed)    //把流推到了T节点（汇点）,结束
        return flow;
    int tempf=0;
    for(int& i=cur[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(level[u]+1==level[v] && edge[i].cap>0)   //1.倒序追踪找前一个点；2.流量不为负
        {
            int f=dfs(v,min(edge[i].cap,flow));  //可行流流量为整个增广路中最小的弧的增量
            edge[i].cap-=f;
            edge[i^1].cap+=f;
            tempf+=f;
            flow-=f;
            if(!flow)
                break;
        }
    }
    return tempf;
}

void Dinic()
{
    while(bfs())
    {
        for(int i=0; i<=ed; i++)
            cur[i]=head[i];
        ans+=dfs(st,INF);
    }
}

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        ans=0;
        st=0;
        ed=n;
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            addEdge(x,y,c);
        }
        Dinic();
        printf("Case %d: %d\n",kase++,ans);
    }
    return 0;
}
