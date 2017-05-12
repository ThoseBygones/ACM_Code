#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

struct Homework
{
    int d;
    int s;
} h[MAXN];

int vis[MAXN];

bool cmp(Homework a,Homework b)
{
    if(a.s==b.s)
        return a.d>b.d;
    return a.s>b.s;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&h[i].d);
        for(int i=1; i<=n; i++)
            scanf("%d",&h[i].s);
        sort(h+1,h+n+1,cmp);
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            int j;
            for(j=h[i].d; j>0; j--)
            {
                if(!vis[j])
                {
                    vis[j]=1;
                    break;
                }
            }
            if(j==0)
                ans+=h[i].s;
        }
        printf("%d\n",ans);
    }
    return 0;
}
