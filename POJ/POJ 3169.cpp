#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 1005
#define MAXM 10005
#define INF 0x3f3f3f3f
using namespace std;

struct Cow
{
    int v;
    int w;
    int next;
} edge[MAXM];

int dis[MAXN];
int vis[MAXN];
int head[MAXN];
int inque[MAXN];    //每个点入队次数
int n,ml,md;
int cnt;

void addEdge(int u,int v,int w)
{
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

bool SPFA()
{
    queue <int> q;
    for(int i=1; i<=n; i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    dis[1]=0;
    q.push(1);
    vis[1]=1;
    inque[1]++;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].v;
            int w=edge[i].w;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    vis[v]=1;
                    inque[v]++;
                    q.push(v);
                    if(inque[v]>=n)
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    while(~scanf("%d%d%d",&n,&ml,&md))
    {
        cnt=0;
        for(int i=1; i<=n; i++)
        {
            head[i]=-1;
            inque[i]=0;
        }
        int u,v,w;
        for(int i=1; i<=ml; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
        }
        for(int i=1; i<=md; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(v,u,-w);
        }
        if(SPFA())
        {
            if(dis[n]==INF)
                printf("-2\n");
            else
                printf("%d\n",dis[n]);
        }
        else
            printf("-1\n");
    }
    return 0;
}
