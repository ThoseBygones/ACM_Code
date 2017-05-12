#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 55
using namespace std;

int par[MAXN],a[MAXN];
int n,m;

int findset(int r)
{
    if(r!=par[r])
        par[r]=findset(par[r]);
    return par[r];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        par[i]=i;
    bool flag=true;
    for(int i=1; i<=m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        a[u]++;
        a[v]++;
        if(a[u]>2 || a[v]>2)
            flag=false;
        int uu=findset(u);
        int vv=findset(v);
        if(uu==vv && (i!=m || i!=n))
            flag=false;
        else
            par[uu]=vv;
    }
    int x,y;
    if(!flag)
        printf("NO\n");
    else
    {
        printf("YES\n");
        printf("%d\n",n-m);
        for(int i=1; i<=n; i++)
        {
            for(int k=1; k<=2; k++)
            {
                for(int j=i+1; j<=n; j++)
                {
                    x=findset(i);
                    y=findset(j);
                    if(a[i]<2 && a[j]<2 && x!=y)
                    {
                        par[x]=y;
                        a[i]++;
                        a[j]++;
                        printf("%d %d\n",i,j);
                    }
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(a[i]<2)
            {
                a[i]++;
                for(int j=i; j<=n; j++)
                {
                    if(a[j]<2)
                    {
                        a[j]++;
                        printf("%d %d\n",i,j);
                    }
                }
            }
        }
    }
    return 0;
}
