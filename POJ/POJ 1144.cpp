#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

int edge[MAXN][MAXN];
int vis[MAXN];
int dfn[MAXN];
int low[MAXN];
int subnets[MAXN];
int son;
int index;
int n,ans;

void tarjan(int u)  //tarjanÀ„∑®£∫dfs
{
    dfn[u]=low[u]=++index;
    vis[u]=1;
    for(int v=1; v<=n; v++)
    {
        if(edge[u][v])
        {
            if(!vis[v])
            {
                tarjan(v);
                low[u]=min(low[u],low[v]);
                if(low[v]>=dfn[u] && u!=1)
                    subnets[u]++;
                else if(u==1)
                    son++;
            }
            else
                low[u]=min(low[u],dfn[v]);
        }
    }
}

int main()
{
    int u,v;
    while(~scanf("%d",&n),n)
    {
        memset(edge,0,sizeof(edge));
        memset(vis,0,sizeof(vis));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(subnets,0,sizeof(subnets));
        son=0;
        index=0;
        while(~scanf("%d",&u),u)
        {
            while(getchar()!='\n')
            {
                scanf("%d",&v);
                edge[u][v]=edge[v][u]=1;
            }
        }
        tarjan(1);
        ans=0;
        if(son>1)
            ans++;
        for(int i=2; i<=n; i++)
        {
            if(subnets[i])
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
