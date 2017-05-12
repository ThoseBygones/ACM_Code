#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define MAXN 1610   //化二维坐标为一维坐标，按照从左（西）往右（东）从上（北）往下（南）扫描

struct Edge
{
    int to;
    int next;
} edge1[MAXN*MAXN],edge2[MAXN*MAXN];    //原图和新图

int head1[MAXN];
int head2[MAXN];
int dfn[MAXN];
int low[MAXN];
int belong[MAXN];
int instack[MAXN];
int value[MAXN];    //记录每个点的矿石数量
int dis[MAXN];  //求最长路记录长度的数组
int vis[MAXN];
int sum[MAXN];  //转化为DAG以后，每个点的矿石数量总和
char g[MAXN][MAXN]; //记录地图
int cnt;    //强连通分量数量
int dfs_clock;  //时间戳
int num;    //边的数量
int n,m;

stack <int> s;
queue <int> q;

void addEdge1(int u,int v)
{
    edge1[num].to=v;
    edge1[num].next=head1[u];
    head1[u]=num++;
}

void addEdge2(int u,int v)
{
    edge2[num].to=v;
    edge2[num].next=head2[u];
    head2[u]=num++;
}

void init()
{
    while(!s.empty())
        s.pop();
    while(!q.empty())
        q.pop();
    memset(head1,-1,sizeof(head1));
    memset(head2,-1,sizeof(head2));
    memset(dfn,0,sizeof(dfn));
    memset(belong,0,sizeof(belong));
    memset(instack,0,sizeof(instack));
    memset(value,0,sizeof(value));
    memset(sum,0,sizeof(sum));
    num=cnt=dfs_clock=0;
}

void tarjan(int u)
{
    dfn[u]=low[u]=++dfs_clock;
    s.push(u);
    instack[u]=1;
    for(int i=head1[u]; i!=-1; i=edge1[i].next)
    {
        int v=edge1[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        cnt++;
        while(!s.empty())
        {
            int temp=s.top();
            belong[temp]=cnt;
            instack[temp]=0;
            sum[cnt]+=value[temp];
            s.pop();
            if(temp==u)
                break;
        }
    }
}

void spfa()
{
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(vis));
    q.push(belong[0]);
    vis[belong[0]]=1;
    dis[belong[0]]=sum[belong[0]];
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head2[u]; i!=-1; i=edge2[i].next)
        {
            int v=edge2[i].to;
            if(dis[v]<dis[u]+sum[v])
            {
                dis[v]=dis[u]+sum[v];
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=0; i<n; i++)
            scanf("%s",g[i]);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(g[i][j]!='#')
                {
                    value[i*m+j]=g[i][j]-'0';
                    if(i+1<n && g[i+1][j]!='#') //向下走
                    {
                        addEdge1(i*m+j,(i+1)*m+j);
                        //cout << i*m+j << " - " << (i+1)*m+j << endl;
                    }
                    if(j+1<m && g[i][j+1]!='#') //向右走
                    {
                        addEdge1(i*m+j,i*m+j+1);
                        //cout << i*m+j << " - " << i*m+j+1 << endl;
                    }

                    if(g[i][j]=='*')
                    {
                        int x,y;
                        value[i*m+j]=0;
                        scanf("%d%d",&x,&y);
                        addEdge1(i*m+j,x*m+y);
                        //cout << i*m+j << " - " << x*m+y << endl;
                    }
                }
            }
        }
        for(int i=0; i<n*m; i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        num=0;
        for(int i=0; i<n*m; i++)   //转化为DAG后建立新图
        {
            for(int j=head1[i]; j!=-1; j=edge1[j].next)
            {
                int v=edge1[j].to;
                if(belong[i]!=belong[v])
                    addEdge2(belong[i],belong[v]);
            }
        }
        spfa();
        int ans=0;
        for(int i=1; i<=cnt; i++)
            ans=max(ans,dis[i]);
        printf("%d\n",ans);
    }
    return 0;
}
