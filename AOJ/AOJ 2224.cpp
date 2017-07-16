//求最大生成树的弦
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 10005

struct Pile
{
    int x;
    int y;
} p[MAXN];

struct Fence
{
    int u;
    int v;
    double w;
} e[MAXN*MAXN];

int fa[MAXN];

bool cmp(Fence a,Fence b)
{
    return a.w>b.w;
}

double getDis(int a,int b)
{
    return sqrt((double)((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y)));
}

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        fa[i]=i;
    for(int i=1; i<=n; i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    double sum=0.0;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&e[i].u,&e[i].v);
        e[i].w=getDis(e[i].u,e[i].v);
        sum+=e[i].w;
    }
    sort(e,e+m,cmp);
    double ans=0.0;
    for(int i=0; i<m; i++)
    {
        int xx=findset(e[i].u);
        int yy=findset(e[i].v);
        if(xx!=yy)
        {
            fa[xx]=yy;
            ans+=e[i].w;
        }
    }
    printf("%.3f\n",sum-ans);
    return 0;
}
