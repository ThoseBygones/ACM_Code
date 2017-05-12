//FloydÀ„∑®£∫
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define INF 0x3f3f3f3f
using namespace std;

int edge[MAXN][MAXN];
//int dis[MAXN];
//int vis[MAXN];
int n,a,b;

void Floyd()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(edge[i][j]>edge[i][k]+edge[k][j])
                    edge[i][j]=edge[i][k]+edge[k][j];
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d%d",&n,&a,&b))
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                edge[i][j]=INF;
        }
        for(int i=1; i<=n; i++)
        {
            int m;
            scanf("%d",&m);
            for(int j=0; j<m; j++)
            {
                int x;
                scanf("%d",&x);
                if(!j)
                    edge[i][x]=0;
                else
                    edge[i][x]=1;
            }
        }
        Floyd();
        if(edge[a][b]>=INF)
            printf("-1\n");
        else
            printf("%d\n",edge[a][b]);
    }
    return 0;
}
