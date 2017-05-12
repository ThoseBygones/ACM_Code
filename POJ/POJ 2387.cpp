#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 1005
int path[MAXN][MAXN],dis[MAXN],check[MAXN];
int INF=99999999;

void dijkstra(int n)
{
    int mini,temp;
    memset(check,0,sizeof(check));
    check[1]=1;
    for(int i=1; i<=n-1; i++)
    {
        mini=INF;
        for(int j=1; j<=n; j++)
        {
            if(check[j]==0 && dis[j]<mini)
            {
                mini=dis[j];
                temp=j;
            }
        }
        check[temp]=1;
        for(int k=1; k<=n; k++)
        {
            if(check[k]==0)
                dis[k]=min(dis[k],dis[temp]+path[temp][k]);
        }
    }
    cout << dis[n] << endl;
}

int main()
{
    int t,n,a,b,d;
    while(scanf("%d %d",&t,&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    path[i][j]=0;
                else
                    path[i][j]=INF;
            }
        }
        for(int i=1; i<=t; i++)
        {
            scanf("%d %d %d",&a,&b,&d);
            path[a][b]=path[b][a]=min(d,path[a][b]);
        }
        for(int i=1; i<=n; i++)
            dis[i]=path[1][i];
        dijkstra(n);
    }
    return 0;
}


//ÖØÐ´´úÂë
/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 1005

int t,n;
int lm[MAXN][MAXN];
int dis[MAXN];
int vis[MAXN];

void Dijkstra()
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=lm[1][i];
        vis[i]=0;
    }
    dis[1]=0;
    vis[1]=1;
    for(int i=1; i<n; i++)
    {
        int Min=INF;
        int temp=1;
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
            if(!vis[j] && lm[temp][j]<INF && dis[temp]+lm[temp][j]<dis[j])
                dis[j]=dis[temp]+lm[temp][j];
        }
    }
}

int main()
{
    cin >> t >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j)
                lm[i][j]=0;
            else
                lm[i][j]=lm[j][i]=INF;
        }
    }
    for(int i=0; i<t; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        if(w<lm[u][v])
            lm[u][v]=lm[v][u]=w;
    }
    Dijkstra();
    cout << dis[n] << endl;
    return 0;
}
*/
