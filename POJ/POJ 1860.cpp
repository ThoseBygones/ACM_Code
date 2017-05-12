//邻接表Bellman-Ford
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define INF 1e9
#define eps 1e-5
using namespace std;

double rate[MAXN][MAXN];
double com[MAXN][MAXN];
double dis[MAXN];
int n,m,s;
double v;

bool Bellman_Ford()
{
    memset(dis,0,sizeof(dis));
    dis[s]=v;
    bool flag;
    for(int i=1; i<n; i++)
    {
        flag=false;
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                if((dis[j]-com[j][k])*rate[j][k]-dis[k]>eps)
                {
                    dis[k]=(dis[j]-com[j][k])*rate[j][k];
                    flag=true;
                }
            }
        }
        if(!flag)
            break;
    }
    for(int j=1; j<=n; j++)
    {
        for(int k=1; k<=n; k++)
        {
            if((dis[j]-com[j][k])*rate[j][k]-dis[k]>eps)
            {
                dis[k]=(dis[j]-com[j][k])*rate[j][k];
                v=dis[s];
                return true;
            }
        }
    }
    v=dis[s];
    return false;
}

int main()
{
    while(~scanf("%d%d%d%lf",&n,&m,&s,&v))
    {
        while(m--)
        {
            int u,v;
            double r1,r2,c1,c2;
            scanf("%d%d%lf%lf%lf%lf",&u,&v,&r1,&c1,&r2,&c2);
            rate[u][v]=r1;
            com[u][v]=c1;
            rate[v][u]=r2;
            com[v][u]=c2;
        }
        double v0=v;
        if(Bellman_Ford())
            printf("YES\n");
        //else if(v-v0>eps)   //该判断可去掉，因为只需判断是否存在正环即可，否则根本不可能v>v0
        //    printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}


//邻接矩阵Bellman-Ford
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define INF 1e9
#define eps 1e-5
using namespace std;

double dis[MAXN];
int n,m,s;
double v;
int cnt;

struct Edge
{
    int u;
    int v;
    double r;
    double c;
}e[MAXN*MAXN];

bool Bellman_Ford()
{
    memset(dis,0,sizeof(dis));
    dis[s]=v;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<cnt; j++)
        {
            if((dis[e[j].u]-e[j].c)*e[j].r-dis[e[j].v]>eps)
                dis[e[j].v]=(dis[e[j].u]-e[j].c)*e[j].r;
        }
    }
    for(int j=0; j<cnt; j++)
    {
        if((dis[e[j].u]-e[j].c)*e[j].r-dis[e[j].v]>eps)
            return true;
    }
    return false;
}

int main()
{
    while(~scanf("%d %d %d %lf",&n,&m,&s,&v))
    {
        cnt=0;
        while(m--)
        {
            int a,b;
            double r1,r2,c1,c2;
            scanf("%d %d %lf %lf %lf %lf",&a,&b,&r1,&c1,&r2,&c2);
            e[cnt].u=a;
            e[cnt].v=b;
            e[cnt].r=r1;
            e[cnt++].c=c1;
            e[cnt].u=b;
            e[cnt].v=a;
            e[cnt].r=r2;
            e[cnt++].c=c2;
        }
        if(Bellman_Ford())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
