#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
#define MAXN 10005
#define MAXE 100010
struct Edge
{
    int to;
    int next;
} e[MAXE];
//int g[MAXN][MAXN];
int head[MAXN];
int out[MAXN],in[MAXN];
int dfn[MAXN];									//第一次访问的步数
int low[MAXN];									//子树中最早的步数						//模拟栈
int instack[MAXN];								//是否在栈中
int scc;										//记录连通分量的个数
int dfs_clock;										//记录搜索步数（时间戳）
int belong[MAXN];								//属于哪个连通分量
int n,m;
int cnt;
stack <int> sta;
void init()
{
    scc=dfs_clock=0;
    cnt=0;
    while(!sta.empty())
        sta.pop();
    memset(instack,0,sizeof(instack));
    //memset(g,0,sizeof(g));
    memset(dfn,0,sizeof(dfn));
    memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void tarjan(int u)
{
    dfn[u]=low[u]=++dfs_clock;
    sta.push(u);
    instack[u]=1;
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        scc++;
        while(!sta.empty())
        {
            int temp=sta.top();
            belong[temp]=scc;
            instack[temp]=0;
            sta.pop();
            if(temp==u)
                break;
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
        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            //g[u][v]=1;
            addEdge(u,v);
        }
        for(int i=1; i<=n; i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        int inzero=0,outzero=0; //记录入度为零和出度为零的点的数量
        for(int i=1; i<=n; i++)
        {
            in[i]=out[i]=0;
        }
        for(int i=1; i<=n; i++)				//找连通分量入度与出度
        {
            for(int j=head[i]; ~j; j=e[j].next)
            {
                int v=e[j].to;
                if(belong[i]!=belong[v])
                {
                    in[belong[v]]++;
                    out[belong[i]]++;
                }
            }
        }
        for(int i=1; i<=scc; i++) 			//找入度与出度为0的点
        {
            if(!in[i])
                inzero++;
            if(!out[i])
                outzero++;
        }
        if(scc==1)					//只有1个结点要特判（因为对于任务B显然不需要加边就能实现，而不特判将得到错误的答案0）
            printf("0\n");
        else
            printf("%d\n",max(inzero,outzero));  //任务B的答案为入度和出度为零的点数量的数值大者（什么原因不清楚，但是画图好像是这样的...）
    }
    return 0;
}
