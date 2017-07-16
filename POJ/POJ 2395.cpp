#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 2005
#define MAXE 10005

struct Edge
{
    int u;
    int v;
    int w;
} e[MAXE];

int fa[MAXN];

bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
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
    for(int i=0; i<m; i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    sort(e,e+m,cmp);
    int ans=0;
    for(int i=0; i<m; i++)
    {
        int xx=findset(e[i].u);
        int yy=findset(e[i].v);
        if(xx!=yy)
        {
            fa[xx]=yy;
            ans=max(e[i].w,ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}
