#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005
#define MAXM 100005

struct Node
{
    int v;
    int next;
    int id; //桥的编号
    bool mark;  //是否为重边的标记
} edge[MAXM*2];

int head[MAXN];
int dfn[MAXN];
int low[MAXN];
int bridge[MAXN*2];   //是桥的边的编号
int tempdfn;
int n,m;
int cnt;
int ans;

void addEdge(int u,int v,int w)
{
    int i;
    for(i=head[u]; i!=-1; i=edge[i].next)
    {
        if(edge[i].v==v)
            break;
    }
    if(i!=-1)   //发现重边
    {
        edge[i].mark=true;
        return ;
    }
    edge[cnt].v=v;
    edge[cnt].mark=false;
    edge[cnt].id=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void tarjan(int u,int fa)
{
    dfn[u]=low[u]=++tempdfn;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            //cout << dfn[u] << "@" << low[v];
            if(dfn[u]<low[v] && !edge[i].mark)
            {
                bridge[ans++]=edge[i].id;
            }
        }
        else
        {
            if(v!=fa)
                low[u]=min(low[u],dfn[v]);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(head,-1,sizeof(head));
        memset(bridge,0,sizeof(bridge));
        cnt=0;
        ans=0;
        tempdfn=0;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v,i);
            addEdge(v,u,i);
        }
        tarjan(1,-1);
        sort(bridge,bridge+ans);
        printf("%d\n",ans);
        if(ans)
        {
            for(int i=0; i<ans; i++)
            {
                if(!i)
                    printf("%d",bridge[i]);
                else
                    printf("% d",bridge[i]);
            }
            printf("\n");
        }
        if(t)
            printf("\n");
    }
    return 0;
}
