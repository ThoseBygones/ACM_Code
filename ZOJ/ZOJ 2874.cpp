#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <queue>
#include <cmath>
using namespace std;

#define MAXN 110
#define MAXM 11010   //100*100+500*2
#define INF 1e9+7
#define EPS 1e-6

struct Edge
{
    int to;
    int next;
    double cap;
} edge[MAXM];

int head[MAXN]; //前向星
int cur[MAXN];  //优化当前弧
int level[MAXN];    //层数
int num;    //边的数目
int n,m,s;
int st,ed;

void addEdge(int u,int v,double w)
{
    edge[num].to=v;
    edge[num].cap=w;
    edge[num].next=head[u];
    head[u]=num++;
    edge[num].to=u;
    edge[num].cap=0.0;
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
    //queue <int> q;
    int q[MAXN<<1]; //手写队列
    int fnt,rear;
    fnt=rear=0;
    memset(level,-1,sizeof(level));
    level[st]=0;
    q[rear++]=st;
    while(fnt<rear)
    {
        int u=q[fnt++];
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap>0 && level[v]==-1)   //流量不为零（是前向弧）且弧的终点未被标记过
            {
                level[v]=level[u]+1;
                q[rear++]=v;
            }
        }
    }
    if(level[ed]!=-1)
        return true;
    return false;
}

double dfs(int u,double flow)
{
    if(u==ed || fabs(flow)<=EPS)    //把流推到了T节点（汇点）,结束
        return flow;
    double tempf=0;
    for(int& i=cur[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(level[u]+1==level[v] && edge[i].cap>0)   //1.倒序追踪找前一个点；2.流量不为负
        {
            double f=dfs(v,min(edge[i].cap,flow));  //可行流流量为整个增广路中最小的弧的增量
            edge[i].cap-=f;
            edge[i^1].cap+=f;
            tempf+=f;
            flow-=f;
            if(fabs(flow)<=EPS)
                break;
        }
    }
    return tempf;
}

double Dinic()
{
    double res=0;
    while(bfs())
    {
        for(int i=0; i<=ed; i++)
            cur[i]=head[i];
        res+=dfs(st,INF);
        //cout << res << endl;
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&s);
        init();
        st=0;
        ed=n+m+1;   //把行和列分别看成点
        for(int i=1; i<=n; i++)
        {
            double c;
            scanf("%lf",&c);
            addEdge(st,i,log(c));    //行点为1~n
        }
        for(int i=1; i<=m; i++)
        {
            double c;
            scanf("%lf",&c);
            addEdge(i+n,ed,log(c));  //列点为n+1~n+m
        }
        for(int i=1; i<=s; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v+n,INF);
        }
        double ans=exp(Dinic());
        printf("%.4f\n",ans);   //C++改为%.4lf
    }
    return 0;
}
