#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

int fa[MAXN];
LL rk[MAXN];

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

void unionset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(rk[xx]>rk[yy])
        fa[xx]=yy;
    else
        fa[yy]=xx;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        fa[i]=i;
        scanf("%I64d",&rk[i]);
    }
    for(int i=1; i<=m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        unionset(u,v);
    }
    LL ans=0;
    for(int i=1; i<=n; i++)
    {
        if(fa[i]==i)
            ans+=rk[i];
    }
    printf("%I64d\n",ans);
    return 0;
}
