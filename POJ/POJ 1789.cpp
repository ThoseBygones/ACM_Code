#include <iostream>
#include <cstdio>
#include <cstring>
#define CODELEN 10
#define MAXN 2005
#define INF 0x3f3f3f3f
using namespace std;

char codes[MAXN][CODELEN];
int truck[MAXN][MAXN];
int dis[MAXN];
int vis[MAXN];
int n;

int prim()
{
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    int tempdis;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            tempdis=0;
            for(int k=0; k<7; k++)
            {
                if(codes[i][k]!=codes[j][k])
                    tempdis++;
            }
            truck[i][j]=truck[j][i]=tempdis;
        }
    }
    int sum=0;
    vis[0]=1;
    for(int i=1; i<n; i++)
        dis[i]=truck[0][i];
    int temp;
    for(int i=1; i<n; i++)
    {
        int Min=INF;
        for(int j=0; j<n; j++)
        {
            if(!vis[j] && dis[j]<Min)
            {
                temp=j;
                Min=dis[j];
            }
        }
        sum+=Min;
        vis[temp]=1;
        for(int j=0; j<n; j++)
        {
            if(truck[temp][j]<dis[j])
                dis[j]=truck[temp][j];
        }
    }
    return sum;
}

int main()
{
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        for(int i=0; i<n; i++)
            scanf("%s",&codes[i]);
        int ans=prim();
        printf("The highest possible quality is 1/%d.\n",ans);
    }
    return 0;
}
