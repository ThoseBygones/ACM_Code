#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 755
#define INF 0x3f3f3f3f
using namespace std;

struct Towns
{
    int x;
    int y;
} town[MAXN];

int island[MAXN][MAXN];
int vis[MAXN];
int dis[MAXN];
int pre[MAXN];  //记录跟该点连接的点
int n,m;

void prim()
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=island[1][i];
        pre[i]=1;
    }
    vis[1]=1;
    int temp;
    for(int i=1; i<n; i++)
    {
        int Min=INF;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis[j]<Min)
            {
                temp=j;
                Min=dis[j];
            }
        }
        vis[temp]=1;
        if(island[pre[temp]][temp])  //当两点之间值不为0（即这两点之间之前不存在Highway
            printf("%d %d\n",pre[temp],temp);
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && island[temp][j]<dis[j])
            {
                dis[j]=island[temp][j];
                pre[j]=temp;
            }
        }
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            scanf("%d%d",&town[i].x,&town[i].y);
        for(int i=1; i<=n; i++)
        {
            island[i][i]=INF;
            for(int j=i+1; j<=n; j++)
                island[i][j]=island[j][i]=(town[i].x-town[j].x)*(town[i].x-town[j].x)+(town[i].y-town[j].y)*(town[i].y-town[j].y);
        }
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            island[u][v]=island[v][u]=0;
        }
        prim();
    }
    return 0;
}
