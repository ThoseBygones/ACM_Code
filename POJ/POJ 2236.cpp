#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

struct Computer
{
    int x;
    int y;
} c[MAXN];

int fa[MAXN];
int vis[MAXN];  //是否被修好的标记
int n,d;

bool reach(int i,int j)
{
    if((c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y)<=d*d)
        return true;
    return false;
}

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
    if(xx!=yy)
        fa[xx]=yy;
}

int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1; i<=n; i++)
    {
        fa[i]=i;
        vis[i]=0;
    }
    for(int i=1; i<=n; i++)
        scanf("%d%d",&c[i].x,&c[i].y);
    char op[2];
    while(~scanf("%s",op))
    {
        if(op[0]=='O')
        {
            int a;
            scanf("%d",&a);
            vis[a]=1;
            for(int i=1; i<=n; i++)
            {
                if(i!=a && vis[i] && reach(i,a))
                    unionset(i,a);
            }
        }
        if(op[0]=='S')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            int aa=findset(a);
            int bb=findset(b);
            if(aa==bb)
                puts("SUCCESS");
            else
                puts("FAIL");
        }
    }
    return 0;
}
