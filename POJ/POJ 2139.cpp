#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 305
#define MAXM 10005
#define INF 0x3f3f3f3f

int c[MAXM];
int d[MAXN][MAXN];
int n,m;

void floyd()
{
    for(int k = 1; k<=n; k++)
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++)
                d[i][j] = min(d[i][j],d[i][k]+d[j][k]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i!=j)
                d[i][j]=INF;
        }
    }
    while(m--)
    {
        int x;
        scanf("%d",&x);
        for(int i=0; i<x; i++)
            scanf("%d",&c[i]);
        for(int i=0; i<x; i++)
        {
            for(int j=i+1; j<x; j++)
            {
                d[c[i]][c[j]]=1;
                d[c[j]][c[i]]=1;
            }
        }
    }
    floyd();
    int Min=INF;
    for(int i=1; i<=n; i++)
    {
        int sum=0;
        for(int j=1; j<=n; j++)
            sum+=d[i][j];
        Min=min(Min,100*sum/(n-1));
    }
    printf("%d\n",Min);
    return 0;
}
