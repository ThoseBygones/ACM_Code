#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

struct Node
{
    int v;
    int next;
} p[MAXN*MAXN];

int vis[MAXN];
int dfn[MAXN];
int low[MAXN];
int head[MAXN];
int cut[MAXN];
int son;    //根节点的子女个数
int nodes;  //记录输入的节点数
int tempdfn;    //记录dfs搜索过程中当前状态下的dfn值
int cnt;

void addEdge(int u,int v)
{
    p[cnt].v=v;
    p[cnt].next=head[u];
    head[u]=cnt++;
}

void findCut(int u) //使用tarjan算法求割点（关节点）
{
    dfn[u]=low[u]=tempdfn++;
    for(int i=head[u]; i!=-1; i=p[i].next)
    {
        int v=p[i].v;
        if(!dfn[v]) //即上面的第1种情况
        {
            findCut(v);
            if(u==1)    //如果这个点是根节点，则记录根节点的儿子书加一
                son++;
            else
            {
                if(low[v]<low[u])
                    low[u]=low[v];
                if(low[v]>=dfn[u])
                    cut[u]=true;
            }
        }
        else if(low[u]>=dfn[v])
            low[u]=dfn[v];
    }
}

void dfs(int u)
{
    vis[u]=true;
    for(int i=head[u]; i!=-1; i=p[i].next)
    {
        int v=p[i].v;
        if(!vis[v])
            dfs(v);
    }
}

void init()
{
    memset(cut,0,sizeof(cut));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    son=0;
    dfn[1]=low[1]=1;
    tempdfn=1;
}

int main()
{
    int kase=1;
    int u,v;
    while(~scanf("%d",&u),u)
    {
        memset(head,-1,sizeof(head));
        nodes=0;
        scanf("%d",&v);
        nodes=max(nodes,u);
        nodes=max(nodes,v);
        cnt=0;
        addEdge(u,v);
        addEdge(v,u);
        while(~scanf("%d",&u),u)
        {
            scanf("%d",&v);
            nodes=max(nodes,u);
            nodes=max(nodes,v);
            addEdge(u,v);
            addEdge(v,u);
        }
        init();
        findCut(1);
        if(kase>1)
            printf("\n");
        printf("Network #%d\n",kase++);
        if(son>1)
            cut[1]=true;
        bool flag=false;
        int subnets;
        for(int i=1; i<=nodes; i++)
        {
            if(cut[i])
            {
                flag=true;
                memset(vis,0,sizeof(vis));
                subnets=0;
                vis[i]=1;
                for(int j=head[i]; j!=-1; j=p[j].next)
                {
                    if(!vis[p[j].v])
                    {
                        dfs(p[j].v);
                        subnets++;
                    }
                }
                printf("  SPF node %d leaves %d subnets\n",i,subnets);
            }
        }
        if(!flag)
            printf("  No SPF nodes\n");
    }
    return 0;
}
