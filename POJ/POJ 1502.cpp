#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define INF 0x3f3f3f3f
using namespace std;

int edge[MAXN][MAXN];
int dis[MAXN];
int vis[MAXN];
int n;
int ans;

void Dijkstra()
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=edge[1][i];
        vis[i]=0;
    }
    dis[1]=0;
    vis[1]=1;
    for(int i=1; i<n; i++)
    {
        int Min=INF;
        int temp=-1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis[j]<Min)
            {
                temp=j;
                Min=dis[j];
            }
        }
        vis[temp]=1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis[temp]+edge[temp][j]<dis[j])
                dis[j]=dis[temp]+edge[temp][j];
        }
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==j)
                    edge[i][j]=0;
                else
                    edge[i][j]=edge[j][i]=INF;
            }
        }
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                int temp;
                if(scanf("%d",&temp))
                    edge[i][j]=edge[j][i]=temp;
                else
                    scanf("x");
            }
        }
        Dijkstra();
        ans=0;
        for(int i=1; i<=n; i++)
            ans=max(dis[i],ans);
        printf("%d\n",ans);
    }
    return 0;
}
