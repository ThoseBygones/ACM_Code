//�ڽӱ�
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 5005

struct Node
{
    int v;
    int next;
} edge[MAXN*2];

bool mp[MAXN][MAXN];    //����֮���Ƿ��Ѿ����ڱ�
int head[MAXN];
int dfn[MAXN];
int low[MAXN];
int bridge[MAXN];
int tempdfn,cnt;
int n,m,ans;

void addEdge(int u,int v)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void tarjan(int u,int fa)
{
    dfn[u]=low[u]=++tempdfn;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(v!=fa)
            low[u]=min(low[u],dfn[v]);
    }
}

int main()
{
    int u,v;
    while(~scanf("%d%d",&n,&m))
    {
        tempdfn=0;
        cnt=0;
        memset(bridge,0,sizeof(bridge));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(head,-1,sizeof(head));
        memset(mp,false,sizeof(mp));
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            if(!mp[u][v])
            {
                addEdge(u,v);
                addEdge(v,u);
                mp[u][v]=mp[v][u]=true;
            }
        }
        tarjan(1,-1);
        ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=head[i]; j!=-1; j=edge[j].next)   //����ͬһ����˫��ͨ�����ϵĶ���
            {
                int w=edge[j].v;
                if(low[w]!=low[i])
                    bridge[low[i]]++;   //����ÿ����Ķ�
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(bridge[i]==1)    //�����Ϊ1�ĵ�
                ans++;
        }
        printf("%d\n",(ans+1)/2);   //��ӱ���Ϊ=(���ж�Ϊ1�Ľڵ���+1)/2
    }
    return 0;
}


//�ڽӾ���
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 5010

int n,m;
bool edge[MAXN][MAXN];
bool vis[MAXN];
int low[MAXN],dfn[MAXN];
int index;
int cnt[MAXN];

void init()
{
    memset(vis,0,sizeof(vis));
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    index=0;
}

void dfs(int u,int fa)
{
    vis[u]=1;
    low[u]=dfn[u]=++index;
    for(int v=1; v<=n; v++)
    {
        if(edge[u][v])
        {
            if(!vis[v])
            {
                dfs(v,u);
                low[u]=min(low[u],low[v]);
            }
            if(vis[v] && v!=fa)
            {
                low[u]=min(low[u],dfn[v]);
            }
        }
    }
}

int main()
{
    int u,v;
    while(~scanf("%d%d",&n,&m))
    {
        memset(edge,0,sizeof(edge));
        while(m--)
        {
            scanf("%d%d",&u,&v);
            edge[u][v]=edge[v][u]=1;
        }
        init();
        dfs(1,1);
        memset(cnt,0,sizeof(cnt));
        for(int i=1; i<=n; i++) 					//����ÿ����Ķ�
        {
            for(int j=1; j<=n; j++)
            {
                if(edge[i][j])
                {
                    if(low[i]!=low[j])
                    {
                        cnt[low[j]]++;
                    }
                }
            }
        }
        int ans=0;				//�����Ϊ1�ĵ�ĸ���
        for(int i=1; i<=n; i++)
        {
            if(cnt[i]==1)
                ans++;
        }
        printf("%d\n",(ans+1)/2);
    }
    return 0;
}
