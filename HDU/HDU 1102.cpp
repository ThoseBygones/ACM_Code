#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int n,m;
int mp[110][110];
int dis[110];
int vis[110];

int prim()
{
    int ans=0;
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    for(int i=1; i<=n; i++)
        dis[i]=mp[1][i];
    for(int i=2; i<=n; i++)
    {
        int Min=INF;
        int temp=0;
        for(int j=2; j<=n; j++)
        {
            if(!vis[j] && dis[j]<Min)
            {
                temp=j;
                Min=dis[j];
                //printf("%d\n",Min);
            }
        }
        ans+=Min;
        vis[temp]=1;
        for(int j=2; j<=n; j++)
        {
            if(!vis[j] && mp[temp][j]<dis[j])
                dis[j]=mp[temp][j];
        }
    }
    return ans;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                scanf("%d",&mp[i][j]);
        }
        scanf("%d",&m);
        int u,v;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            mp[u][v]=mp[v][u]=0;
        }
        int ans=prim();
        printf("%d\n",ans);
    }
    return 0;
}
