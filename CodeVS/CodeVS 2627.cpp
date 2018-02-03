#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int g[MAXN][MAXN];
int vis[MAXN];
int dis[MAXN];
int n;

int prim()
{
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++)
        dis[i]=g[0][i];
    vis[0]=1;
    dis[0]=0;
    int sum=0;
    for(int i=1; i<n; i++)
    {
        int pos=-1;
        int Min=INF;
        for(int j=0; j<n; j++)
        {
            if(!vis[j]&&dis[j]<Min)
            {
                Min=dis[j];
                pos=j;
            }
        }
        sum+=Min;
        vis[pos]=1;
        for(int j=0; j<n; j++)
        {
            if(!vis[j]&&g[pos][j]<dis[j])
                dis[j]=g[pos][j];
        }
    }
    return sum;
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            scanf("%d",&g[i][j]);
    }
    printf("%d\n",prim());
    return 0;
}
