#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

int edge[MAXN][MAXN];   //邻接矩阵
int vis[MAXN];  //顶点的访问状态
int dfn[MAXN];  //每个顶点的dfn（深度优先搜索序数）值
int low[MAXN];  //每个顶点的low值
int subnets[MAXN];  //记录每个节点（去掉该节点后剩余）的连通分量个数
int son;    //根节点的子女个数
int nodes;  //记录输入的节点数
int tempdfn;    //记录dfs搜索过程中当前状态下的dfn值

void dfs(int u) //使用tarjan算法求割点（关节点）
{
    for(int v=1; v<=nodes; v++)
    {
        if(edge[u][v])  //u和v两点邻接，在深度优先生成树中的情况有两种：1.v是u的一个子节点（儿子）；2.v是u的祖先，边(u,v)是一条回边
        {
            if(!vis[v]) //即上面的第1种情况
            {
                vis[v]=1;
                tempdfn++;
                dfn[v]=low[v]=tempdfn;
                dfs(v);
                low[u]=min(low[u],low[v]);  //回退的时候计算low的值
                if(low[v]>=dfn[u])  //u点为关节点的充要条件之一
                {
                    //u点为关节点的另一个充要条件
                    if(u!=1)    //如果这个点不是根节点，则记录其子节点数（连通分量数）加一
                        subnets[u]++;
                    if(u==1)    //如果这个点是根节点，则记录根节点的儿子书加一
                        son++;
                }
            }
            else    //若此点已被访问过（即第2种情况）
                low[u]=min(low[u],dfn[v]);
        }
    }
}

void init()
{
    memset(vis,0,sizeof(vis));
    memset(subnets,0,sizeof(subnets));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    son=0;
    dfn[1]=low[1]=1;
    tempdfn=1;
    vis[1]=1;
}

int main()
{
    int kase=1;
    int u,v;
    while(~scanf("%d",&u),u)
    {
        memset(edge,0,sizeof(edge));
        nodes=0;
        scanf("%d",&v);
        nodes=max(nodes,u);
        nodes=max(nodes,v);
        edge[u][v]=edge[v][u]=1;
        while(~scanf("%d",&u),u)
        {
            scanf("%d",&v);
            nodes=max(nodes,u);
            nodes=max(nodes,v);
            edge[u][v]=edge[v][u]=1;
        }
        init();
        dfs(1);
        if(kase>1)
            printf("\n");
        printf("Network #%d\n",kase++);
        if(son>1)
            subnets[1]=son-1;   //先减去1，以便下一步的遍历所有节点的时候统一加上1
        bool flag=false;
        for(int i=1; i<=nodes; i++)
        {
            if(subnets[i])
            {
                flag=true;
                printf("  SPF node %d leaves %d subnets\n",i,subnets[i]+1);
            }
        }
        if(!flag)
            printf("  No SPF nodes\n");
        //printf("\n");
    }
    return 0;
}
