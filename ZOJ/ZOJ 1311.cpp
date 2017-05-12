#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

struct Node
{
    int v;
    int next;
} p[MAXN*MAXN];

//int vis[MAXN];
int head[MAXN];
int dfn[MAXN];
int low[MAXN];
int cut[MAXN];
int tempdfn;
int son;
int cnt;
int n,ans;

void addEdge(int u,int v)
{
    p[cnt].v=v;
    p[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int u)
{
    dfn[u]=low[u]=++tempdfn;
    for(int i=head[u]; i!=-1; i=p[i].next)
    {
        int v=p[i].v;
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(u!=1 && low[v]>=dfn[u])
                cut[u]=1;
            else if(u==1)
                son++;
        }
        else
            low[u]=min(low[u],dfn[v]);
    }
}

int main()
{
    int u,v;
    while(~scanf("%d",&n),n)
    {
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(cut,0,sizeof(cut));
        memset(head,-1,sizeof(head));
        cnt=0;
        while(~scanf("%d",&u),u)
        {
            while(getchar()!='\n')
            {
                scanf("%d",&v);
                addEdge(u,v);
                addEdge(v,u);
            }
        }
        tempdfn=0;
        son=0;
        dfs(1);
        ans=0;
        if(son>1)
            ans++;
        for(int i=2; i<=n; i++)
        {
            if(cut[i])
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
