#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define INF 100000.0
double dis[205],pond[205][205];
int vis[205],n;

struct stone
{
    double x;
    double y;
} s[205];

double dist(stone a,stone b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void dijkstra()
{
    for(int i=1; i<n; i++)
    {
        int k=-1;
        double mmin=INF;
        for(int j=2; j<=n; j++)
        {
            if(vis[j]==0 && dis[j]<mmin)
            {
                mmin=dis[j];
                k=j;
            }
        }
        if(k==-1)
            break;
        vis[k]=1;
        for(int j=1; j<=n; j++)
            if(vis[j]==0 && max(dis[k],pond[k][j])<dis[j])
                dis[j]=max(dis[k],pond[k][j]);
    }
}

int main()
{
    int kase=0;
    while(~scanf("%d",&n) && n)
    {
        kase++;
        for(int i=1; i<=n;i++)
            cin >> s[i].x >> s[i].y;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                pond[i][j]=pond[j][i]=dist(s[i],s[j]);
        for(int i=1; i<=n; i++)
        {
            vis[i]=0;
            dis[i]=pond[1][i];
        }
        vis[1]=1;
        dijkstra();
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",kase,dis[2]);
    }
}


//重写代码：
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define MAXN 205
#define INF 1000000000.0

struct Stone
{
    double x;
    double y;
} s[MAXN*MAXN];

double pond[MAXN][MAXN];    //邻接矩阵
double dis[MAXN];
int vis[MAXN];
int n;

double dist(Stone a,Stone b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void Dijkstra(int t)
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=pond[t][i];
        vis[i]=0;
    }
    dis[t]=0;
    vis[t]=1;
    for(int i=1; i<n; i++)
    {
        double Min=INF;
        int temp=t;
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
            if(!vis[j] && pond[temp][j]<INF && max(dis[temp],pond[temp][j])<dis[j])
            {
                dis[j]=max(dis[temp],pond[temp][j]);
                //printf("%lf\n",dis[j]);
            }
        }
    }
}

int main()
{
    int kase=1;
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        for(int i=1; i<=n; i++)
            scanf("%lf%lf",&s[i].x,&s[i].y);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    pond[i][j]=0;
                else
                    pond[i][j]=pond[j][i]=INF;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                double len=dist(s[i],s[j]);
                if(len<pond[i][j])
                    pond[i][j]=pond[j][i]=len;
            }
        }
        Dijkstra(1);
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",kase++,dis[2]);
    }
    return 0;
}

//G++需将输出的.3lf改成.lf即可AC
