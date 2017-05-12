#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define MAXN 30010
#define MAXM 150010
#define INF 0x3f3f3f3f

struct Edge
{
    int to;
    int next;
} edge[MAXM];

struct Graph
{
    int to;
    int next;
    int value;
} g[MAXM];

int head1[MAXN];
int dfn[MAXN];
int low[MAXN];
int vis[MAXN];
int belong[MAXN];
int instack[MAXN];  //结点是否在栈中
int head2[MAXN];
int in[MAXN];   //每个点的入度
int out[MAXN];  //每个点的出度
int cfi[MAXN];  //每个点的舒适度指数
int dp[MAXN];   //记录遍历过程中到某个点是所积累的最大舒适度指数
int dis[MAXN];  //求最长路时记录数组
int num;    //边的数量
int cnt;    //强连通分量数量
int dfs_clock;  //时间戳
int n,m;

queue <int> q;
stack <int> s;

void addEdge1(int u,int v)
{
    edge[num].to=v;
    edge[num].next=head1[u];
    head1[u]=num++;
}

void addEdge2(int u,int v,int w)
{
    g[num].to=v;
    g[num].value=w;
    g[num].next=head2[u];
    head2[u]=num++;
}

void tarjan(int u)
{
    dfn[u]=low[u]=++dfs_clock;
    s.push(u);
    instack[u]=1;
    for(int i=head1[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
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
            instack[temp]=0;
            belong[temp]=cnt;
            s.pop();
            if(temp==u)
                break;
        }
    }
}

int spfa(int x)
{
    while(!q.empty())
        q.pop();
    q.push(x);
    vis[x]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head2[u]; i!=-1; i=g[i].next)
        {
            int v=g[i].to;
            dis[v]=max(dis[v],dis[u]+g[i].value);
            if(!vis[v])
            {
                q.push(v);
                vis[v]=1;
            }
        }
    }
    int ans=0;
    for(int i=1; i<=cnt; i++)
    {
        if(!out[i])
            ans=max(ans,dis[i]);
    }
    return ans;
}

void initEdge()
{
    while(!s.empty())
        s.pop();
    memset(dfn,0,sizeof(dfn));
    memset(belong,0,sizeof(belong));
    memset(head1,-1,sizeof(head1));
    memset(instack,0,sizeof(instack));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(cfi,0,sizeof(cfi));
    memset(dp,0,sizeof(dp));
    cnt=dfs_clock=0;
    num=0;
}

void initGraph()
{
    memset(head2,-1,sizeof(head2));
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    num=0;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        initEdge();
        for(int i=1; i<=n; i++)
            scanf("%d",&cfi[i]);
        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge1(u+1,v+1);
        }
        for(int i=1; i<=n; i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        initGraph();
        for(int i=1; i<=n; i++)
        {
            if(cfi[i]>0)
                dp[belong[i]]+=cfi[i];
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=head1[i]; j!=-1; j=edge[j].next)
            {
                int v=edge[j].to;
                if(belong[i]!=belong[v])
                {
                    in[belong[v]]++;
                    out[belong[i]]++;
                    addEdge2(belong[i],belong[v],dp[belong[v]]);
                }
            }
        }
        for(int i=1; i<=cnt; i++)
        {
            if(!in[i])
                addEdge2(0,i,dp[i]);    //入度为0的根节点的cfi值也要计入，因此虚设一个0点为根节点，在0点和该入度为0的根节点之间连一条边
        }
        int ans=spfa(0);    //从虚设的0点开始寻找cfi值最大的最长路
        printf("%d\n",ans);
    }
    return 0;
}
