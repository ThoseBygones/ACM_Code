#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1005

int edge[MAXN][MAXN];   //邻接矩阵
int indegree[MAXN]; //每个点的入度
int outdegree[MAXN];    //每个点的出度
int vis[MAXN];
int n,m;

void dfs(int x)
{
    vis[x]=1;
    for(int i=1; i<=n; i++)
    {
        if(edge[x][i] && !vis[i])
            dfs(i);
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        memset(indegree,0,sizeof(indegree));
        memset(outdegree,0,sizeof(outdegree));
        memset(vis,0,sizeof(vis));
        memset(edge,0,sizeof(edge));
        scanf("%d",&m);
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u][v]=edge[v][u]=1;
            indegree[u]++,outdegree[u]++;
            indegree[v]++,outdegree[v]++;
        }
        dfs(1);
        bool flag=true;
        for(int i=1; i<=n; i++)
        {
            if(outdegree[i]!=indegree[i] || !vis[i] || indegree[i]%2)
            {
                flag=false;
                break;
            }
        }
        if(flag)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
