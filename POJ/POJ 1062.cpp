#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define INF 0x3f3f3f3f
using namespace std;

int edge[MAXN][MAXN],p[MAXN],l[MAXN];
int dis[MAXN];
int vis[MAXN];
int m,n;
int ans;

int Dijkstra()
{
    for(int i=1; i<=n; i++)
        dis[i]=p[i];
    for(int i=1; i<n; i++)
    {
        int Min=INF;
        int temp;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis[j]<Min)
            {
                Min=dis[j];
                temp=j;
            }
        }
        vis[temp]=1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis[temp]+edge[temp][j]<dis[j])
                dis[j]=dis[temp]+edge[temp][j];
        }
    }
    return dis[1];
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        memset(p,0,sizeof(p));
        memset(l,0,sizeof(l));
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
                edge[i][j]=INF;
        }
        for(int i=1; i<=n; i++)
        {
            int num;
            scanf("%d%d%d",&p[i],&l[i],&num);
            for(int j=1; j<=num; j++)
            {
                int level,price;
                scanf("%d%d",&level,&price);
                edge[level][i]=price;
            }
        }
        ans=INF;
        for(int i=1; i<=n; i++)
        {
            int minlevel=l[i];
            for(int j=1; j<=n; j++)
            {
                if(l[j]-minlevel>m || l[j]<minlevel)    //关键判断：如果等级差或者等级高低关系不符合交易要求，则直接记为不可交易
                    vis[j]=1;
                else
                    vis[j]=0;
            }
            int sum=Dijkstra();
            ans=min(ans,sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}
