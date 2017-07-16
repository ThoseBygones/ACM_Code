//最大生成树/最大权森林
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 20005
#define MAXE 50005

struct Edge
{
    int u;
    int v;
    int w;
} e[MAXE];

int fa[MAXN];

bool cmp(Edge a,Edge b)
{
    return a.w>b.w;
}

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,r;
        scanf("%d%d%d",&n,&m,&r);
        for(int i=0; i<n+m; i++)
            fa[i]=i;
        for(int i=0; i<r; i++)
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        sort(e,e+r,cmp);
        int ans=0;
        for(int i=0; i<r; i++)
        {
            int xx=findset(e[i].u);
            int yy=findset(e[i].v+n);
            if(xx!=yy)
            {
                fa[xx]=yy;
                ans+=e[i].w;
            }
        }
        printf("%d\n",10000*(n+m)-ans);
    }
    return 0;
}
