#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005
#define MAXE 50005
#define MAXQ 10005
#define LL long long

int fa[MAXN];
int sum[MAXN];
LL ans[MAXQ];
int n,m,q;

struct Node
{
    int u;
    int v;
    int c;
} edge[MAXE];

struct Query
{
    int id;
    int l;
} query[MAXQ];

bool cmp1(Node a,Node b)
{
    return a.c<b.c;
}

bool cmp2(Query a,Query b)
{
    return a.l<b.l;
}

void init()
{
    for(int i=1; i<=n; i++)
    {
        fa[i]=i;
        sum[i]=1;
    }
}

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

int unionset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    int val=0;
    if(xx!=yy)
    {
        fa[yy]=xx;
        val=sum[xx]*sum[yy];
        sum[xx]+=sum[yy];
        sum[yy]=0;
    }
    return val;
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&q))
    {
        init();
        for(int i=1; i<=m; i++)
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].c);
        sort(edge+1,edge+m+1,cmp1);
        for(int i=1; i<=q; i++)
        {
            scanf("%d",&query[i].l);
            query[i].id=i;
        }
        sort(query+1,query+q+1,cmp2);
        LL res=0;
        int p=1;
        for(int i=1; i<=q; i++)
        {
            while(edge[p].c<=query[i].l && p<=m)
            {
                res+=unionset(edge[p].u,edge[p].v);
                p++;
            }
            ans[query[i].id]=res;
        }
        for(int i=1; i<=q; i++)
        printf("%I64d\n",ans[i]);
    }
    return 0;
}
