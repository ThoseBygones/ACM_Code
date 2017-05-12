//直接水过：
#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005
#define MAXM 2005

int a[MAXN];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int ans=0;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ans+=min(a[x],a[y]);
    }
    printf("%d\n",ans);
    return 0;
}


//认真建图：
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 1005
int g[MAXN][MAXN];
int value[MAXN];
int n,m;

struct Edge
{
    int val;
    int id;
} edge[MAXN];

int cmp(Edge a,Edge b)
{
    return a.val>b.val;
}

int main()
{
    memset(g,0,sizeof(g));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&edge[i].val);
        value[i]=edge[i].val;
        edge[i].id=i;
    }
    int u,v;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&u,&v);
        g[u][v]=g[v][u]=1;
    }
    sort(edge+1,edge+n+1,cmp);
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        int v=edge[i].id;
        for(int u=1; u<=n; u++)
        {
            if(g[v][u])
            {
                sum+=value[u];
                g[v][u]=g[u][v]=0;
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}
