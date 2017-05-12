#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 300
#define INF 1e18
using namespace std;

struct Points
{
    double x;
    double y;
} p[MAXN];

double edge[MAXN][MAXN];
double dis[MAXN];
int vis[MAXN];
int cnt;
int sum;

double dist(Points a,Points b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void Dijkstra()
{
    for(int i=1; i<=cnt; i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    dis[1]=0.0;
    for(int i=1; i<cnt; i++)
    {
        double Min=INF;
        int temp=-1;
        for(int j=1; j<=cnt; j++)
        {
            if(!vis[j] && dis[j]<Min)
            {
                Min=dis[j];
                temp=j;
            }
        }
        vis[temp]=1;
        for(int j=1; j<=cnt; j++)
        {
            if(!vis[j] && dis[temp]+edge[temp][j]<dis[j])
                dis[j]=dis[temp]+edge[temp][j];
        }
    }
}

int main()
{
    double v1=10000.0/60.0; //步行速度
    double v2=40000.0/60.0; //地铁速度
    while(scanf("%lf%lf%lf%lf",&p[1].x,&p[1].y,&p[2].x,&p[2].y)==4)
    {
        cnt=2;
        sum=3;
        for(int i=1; i<=MAXN; i++)
        {
            for(int j=1; j<=MAXN; j++)
            {
                if(i==j)
                    edge[i][j]=0;
                else
                    edge[i][j]=INF;
            }
        }
        int x,y;
        while(scanf("%d%d",&x,&y)==2)
        {
            if(x==-1 && y==-1)
            {
                sum=cnt+1;
                continue;
            }
            cnt++;
            p[cnt].x=x;
            p[cnt].y=y;
            if(sum!=cnt)
                edge[cnt-1][cnt]=edge[cnt][cnt-1]=min(edge[cnt-1][cnt],dist(p[cnt-1],p[cnt])/v2);
        }
        for(int i=1; i<=cnt; i++)
        {
            for(int j=1; j<=cnt; j++)
                edge[i][j]=edge[j][i]=min(edge[i][j],dist(p[i],p[j])/v1);
        }
        Dijkstra();
        printf("%.0lf\n",dis[2]);   //G++需把lf改为f
    }
    return 0;
}
