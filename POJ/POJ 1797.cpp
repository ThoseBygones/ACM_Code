#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1005
using namespace std;

int road[MAXN][MAXN];
int dis[MAXN];
int vis[MAXN];
int n,m;

void Dijkstra()
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=road[i][1];
        vis[i]=0;
    }
    dis[1]=0;
    vis[1]=1;
    for(int i=1; i<n; i++)
    {
        int Min=0;
        int temp=-1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis[j]>Min)
            {
                temp=j;
                Min=dis[j];
            }
        }
        vis[temp]=1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis[j]<min(dis[temp],road[temp][j]))
                dis[j]=min(dis[temp],road[temp][j]);
        }
    }
}

int main()
{
    int t;
    int kase=1;
    scanf("%d",&t);
    while(t--)
    {
        memset(road,0,sizeof(road));
        scanf("%d%d",&n,&m);
        while(m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            road[u][v]=road[v][u]=w;
        }
        Dijkstra();
        printf("Scenario #%d:\n%d\n\n",kase++,dis[n]);
    }
    return 0;
}
