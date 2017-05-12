#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 110    //50*2
#define MAXM 2005
#define INF 0x3fffffff

struct Edge
{
    int to;
    int next;
    int cap;
} edge[MAXN*MAXN*2];

int head[MAXN]; //前向星
int cur[MAXN];  //优化当前弧
int level[MAXN];    //层数
int val[MAXN];
int input[MAXN][15];   //输入电脑的情况用0,1,2表示：0——半成品电脑要能工作不能有该部件；1——必须有该部件；2——有没有该部件无所谓。
int output[MAXN][15];  //输出电脑的情况用0,1表示：0——输出电脑对应的部件未装好，1——对应的部件已装好
int g[MAXN][MAXN];  //记录哪两个点之间是连通的，便于最后输出组装路线
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
    memset(g,0,sizeof(g));
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
        //cout << res << endl;
        //system("pause");
    }
    return res;
}

bool check(int x,int y)
{
    if(x==y || y==2)
        return true;
    return false;
}

bool check0(int x)  //判断是否全为1
{
    for(int i=0; i<n; i++)
    {
        if(input[x][i]==1)  //如果全为1就不用处理了
            return false;
    }
    return true;
}

bool check1(int x)  //判断是否全为1
{
    for(int i=0; i<n; i++)
    {
        if(output[x][i]!=1) //如果不为1就说明还没完成
            return false;
    }
    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d",val+i);
        for(int j=0; j<n; j++)
            scanf("%d",&input[i][j]);
        for(int j=0; j<n; j++)
            scanf("%d",&output[i][j]);
    }
    init();
    st=0;
    ed=2*m+1;
    for(int i=1; i<=m; i++) //拆点
    {
        for(int j=1; j<=m; j++)
        {
            if(i==j)
                continue;
            bool flag=true; //检测该电脑是否装好了
            for(int k=0; k<n; k++)
            {
                if(!check(output[i][k],input[j][k]))
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                addEdge(i+m,j,val[i]);  //输出的电脑与输入的电脑连边
                g[i+m][j]=1;
            }
        }
    }
    for(int i=1; i<=m; i++)
    {
        addEdge(i,i+m,val[i]);
        if(check0(i))
            addEdge(st,i,val[i]);   //还未完全装好至符合要求的计算机与超级源点连边
        if(check1(i))
            addEdge(i+m,ed,val[i]); //已经完全装好至符合要求的计算机与超级汇点连边
    }
    int sum=Dinic();
    int cnt=0;
    for(int i=1; i<=m; i++) //遍历网络寻找有几条可行流（即能传送多少电脑）
    {
        for(int j=head[i+m]; j!=-1; j=edge[j].next)
        {
            if(g[i+m][edge[j].to] && edge[j].cap<val[i])
                cnt++;
        }
    }
    printf("%d %d\n",sum,cnt);
    for(int i=1; i<=m; i++) //再次遍历输出可行流
    {
        for(int j=head[i+m]; j!=-1; j=edge[j].next)
        {
            if(g[i+m][edge[j].to] && edge[j].cap<val[i])
                printf("%d %d %d\n",i,edge[j].to,val[i]-edge[j].cap);
        }
    }
    return 0;
}
