#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

#define MAXN 5005

struct Node
{
    int to;
    int next;
} edge[MAXN*10];

stack <int> sta;

int head[MAXN];
int dfn[MAXN];
int low[MAXN];
int instack[MAXN];
int belong[MAXN];
int out[MAXN];
int clock;  //时间戳
int e;  //边的数量
int cnt;    //转化为DAG后强连通分量的数量
int n,m;

void addEdge(int u,int v)
{
    edge[e].to=v;
    edge[e].next=head[u];
    head[u]=e++;
}

void tarjan(int u)
{
    low[u]=dfn[u]=++clock;
    sta.push(u);
    instack[u]=1;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        cnt++;
        while(!sta.empty())
        {
            int temp=sta.top();
            instack[temp]=0;
            belong[temp]=cnt;
            sta.pop();
            if(temp==u)
                break;
        }
    }
}

void init()
{
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(instack,0,sizeof(instack));
    memset(out,0,sizeof(out));
    memset(belong,0,sizeof(belong));
    while(!sta.empty())
        sta.pop();
    cnt=0;
    clock=0;
}

int main()
{
    while(~scanf("%d",&n),n)
    {
        memset(head,-1,sizeof(head));
        e=0;
        scanf("%d",&m);
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
        }
        init();
        for(int i=1; i<=n; i++) //求出每个强连通分量
        {
            if(!dfn[i])
                tarjan(i);
        }
        for(int i=1; i<=n; i++) //计算每个结点的出度
        {
            for(int j=head[i]; j!=-1; j=edge[j].next)
            {
                int v=edge[j].to;
                if(belong[i]!=belong[v])
                    out[belong[i]]++;
            }
        }
        bool flag=true;
        for(int i=1; i<=n; i++)
        {
            if(!out[belong[i]])
            {
                if(flag)
                {
                    printf("%d",i);
                    flag=false;
                }
                else
                    printf(" %d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
