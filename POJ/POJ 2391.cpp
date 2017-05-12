#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 410    //200*2
#define MAXM 1510
#define INF 0x3f3f3f3f
#define LINF 1e15
#define LL long long

struct Edge
{
    int to;
    int next;
    int cap;
} edge[MAXN*MAXN];  //1500条路+200*200拆点后点两两间的路*2（双向）

LL dis[MAXN][MAXN];    //求最短路的邻接矩阵
int head[MAXN]; //前向星
int cur[MAXN];  //当前弧优化
int level[MAXN];    //层数
int now[MAXN],c[MAXN];    //每块草地现在牛的数量和容纳避雨的牛的数量
int num;    //边的数目
int n,m;
int st,ed;  //超级源点、超级汇点
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

int bfs()
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
        return 1;
    return 0;
}

int dfs(int u,int flow)
{
    if(u==ed || flow==0)    //把流推到了T节点（汇点）,结束
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

void Floyd()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
}

void build(LL x)
{
    init();
    for(int i=1; i<=n; i++)
    {
        addEdge(st,i,now[i]);   //超级源点与每块草地上的牛（流入）之间连边
        addEdge(i+n,ed,c[i]); //每块草地上要去避雨的牛（流出）与超级汇点之间连边
    }
    for(int i=1; i<=n; i++)
        addEdge(i,i+n,INF); //每块草地上的牛（流入）与每块草地上要去避雨的牛（流出）之间连边（即拆点，将每块草地拆成两个点）
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(dis[i][j]<=x)
            {
                addEdge(i,j+n,INF);
                addEdge(j,i+n,INF); //牛可以到别的草地去，即在有避雨棚草地上的牛也能到别的草地上去
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        st=0;
        ed=(n<<1)+1;  //拆点，除超级源点和超级汇点外所有点拆成两个点
        int sum=0;  //牛的总数量
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&now[i],&c[i]);
            sum+=now[i];
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                dis[i][j]=LINF;
        }
        for(int i=1; i<=m; i++)
        {
            int u,v,len;
            scanf("%d%d%d",&u,&v,&len);
            if(dis[u][v]>len)
                dis[u][v]=dis[v][u]=len;
        }
        Floyd();
        LL ans=-1;
        LL left=0,right=LINF;
        while(left<=right)  //二分查找能避雨的牛的最大数量
        {
            LL mid=(left+right)/2;
            build(mid);
            int temp=Dinic();
            if(temp>=sum)
            {
                ans=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        if(ans==LINF)
            puts("-1");
        else
            printf("%I64d\n",ans);
    }

    return 0;
}

/*
6 6
10 0
0 3
0 7
3 0
0 2
0 1
1 2 120
5 2 80
5 1 20
5 6 30
6 1 110
4 3 30

ans：-1


10 9
1 0
0 0
0 0
0 1
0 1
0 1
0 1
0 1
0 1
0 1
2 1 10
3 1 4
4 3 2
5 3 5
6 2 11
7 5 1
8 6 7
9 4 1
10 2 10

ans：6
*/
