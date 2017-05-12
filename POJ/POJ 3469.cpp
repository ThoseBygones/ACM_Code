#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 40010  //20000*2
#define MAXM 500100 //200000*2+20000*2*2
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
int a[MAXN];
int b[MAXN];

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
    if(!tempf)
        level[u]=-1;
    return tempf;
}

int Dinic()
{
    int res=0;
    while(bfs())
    {
        for(int i=0; i<=ed; i++)
            cur[i]=head[i];
        res+=dfs(st,INF);
    }
    return res;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        st=0;
        ed=n+1;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",a+i,b+i);
            addEdge(st,i,a[i]);
            addEdge(i,st,0);
            addEdge(i,ed,b[i]);
            addEdge(ed,i,0);
        }
        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
            addEdge(v,u,w); //两模块不在同一个core中运行，因此建双向边
        }
        int ans=Dinic();    //最大流=最小割
        printf("%d\n",ans);
    }
    return 0;
}
