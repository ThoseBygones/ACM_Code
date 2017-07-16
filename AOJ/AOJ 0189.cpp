#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 15

int d[MAXN][MAXN];
int len[MAXN];  //从第i个点出发的单源最短路径长度和
int n,m;

void floyd()
{
    for(int k = 0; k<n; k++)
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
            {
                if(d[i][k]!=-1&&d[j][k]!=-1)
                {
                    if(d[i][j]==-1 || d[i][j]>d[i][k]+d[j][k])
                        d[i][j] = d[i][k] + d[j][k];
                }
            }
}

int main()
{
    while(~scanf("%d",&m),m)
    {
        memset(d,-1,sizeof(d));
        for(int i=0; i<m; i++)
            d[i][i]=0;
        n=0;  //办公室数量
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            d[u][v]=w;
            d[v][u]=w;
            n=max(n,max(u,v)+1);
        }
        floyd();
        memset(len,0,sizeof(len));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                len[i]+=d[i][j];
        }
        int ans=min_element(len,len+n)-len;
        printf("%d %d\n",ans,len[ans]);
    }
    return 0;
}
