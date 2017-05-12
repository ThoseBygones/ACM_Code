#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1005
#define INF 0x3f3f3f3f
using namespace std;

int road1[MAXN][MAXN];
int road2[MAXN][MAXN];
int dis1[MAXN];
int dis2[MAXN];
int vis[MAXN];
int n,m,x;

void Dijkstra()
{
    for(int i=1; i<=n; i++)
    {
        dis1[i]=road1[x][i];
        vis[i]=0;
    }
    dis1[x]=0;
    vis[x]=1;
    for(int i=1; i<n; i++)
    {
        int Min=INF;
        int temp=-1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis1[j]<Min)
            {
                temp=j;
                Min=dis1[j];
            }
        }
        vis[temp]=1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis1[temp]+road1[temp][j]<dis1[j])
                dis1[j]=dis1[temp]+road1[temp][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        dis2[i]=road2[x][i];
        vis[i]=0;
    }
    dis2[x]=0;
    vis[x]=1;
    for(int i=1; i<n; i++)
    {
        int Min=INF;
        int temp=-1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis2[j]<Min)
            {
                temp=j;
                Min=dis2[j];
            }
        }
        vis[temp]=1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis2[temp]+road2[temp][j]<dis2[j])
                dis2[j]=dis2[temp]+road2[temp][j];
        }
    }
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&x))
    {
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==j)
                {
                    road1[i][j]=0;
                    road2[i][j]=0;
                }
                else
                {
                    road1[i][j]=INF;
                    road2[i][j]=INF;
                }
            }
        }
        while(m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            road1[u][v]=w;
            road2[v][u]=w;
        }
        Dijkstra();
        int ans=-1;
        for(int i=1; i<=n; i++)
            ans=max(ans,dis1[i]+dis2[i]);
        printf("%d\n",ans);
    }
    return 0;
}
