#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 1000005
#define INF 1000000000
#define LL long long
using namespace std;

struct Edge
{
    int u;
    int v;
    int w;
    int next;
} edge[MAXN];

int head[MAXN];
int vis[MAXN];
int dis[MAXN];
int n,m;
int cnt;

queue <int> q;

void addEdge(int u,int v,int w)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void SPFA()
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    q.push(1);
    dis[1]=0;
    vis[1]=1;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        vis[temp]=0;
        for(int i=head[temp]; i!=-1; i=edge[i].next)
        {
            if(dis[temp]+edge[i].w<dis[edge[i].v])
            {
                dis[edge[i].v]=dis[temp]+edge[i].w;
                if(!vis[edge[i].v])
                {
                    q.push(edge[i].v);
                    vis[edge[i].v]=1;
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
        LL sum=0;   //一定要long long，因为每段路之间的最大值不超过1000000000
        int u,v,w;

        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
        }
        SPFA();
        for(int i=1; i<=n; i++)
            sum+=dis[i];

        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=0; i<m; i++)
            addEdge(edge[i].v,edge[i].u,edge[i].w);
        SPFA();
        for(int i=1; i<=n; i++)
            sum+=dis[i];

        printf("%lld\n",sum);
    }
    return 0;
}
