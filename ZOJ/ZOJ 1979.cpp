#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 5005

struct Graph
{
    int from;
    int to;
    int next;
} g1[MAXN*10],g2[MAXN*10];    //正向图和逆图

int order[MAXN];    //正向搜索时记录的结点顺序
int head1[MAXN];    //原图的头结点
int head2[MAXN];    //逆图的头结点
int belong[MAXN];   //结点的归属
int out[MAXN];  //转化为DAG后，每个结点或缩点（强连通分量）的出度
int vis[MAXN];
int e;  //边的数量
int num;    //节点数量
int cnt;    //转化为DAG后结点（包括缩点）的数量（强连通分量数量）
int n,m;

void addEdge(int u,int v)
{
    g1[e].from=u;
    g1[e].to=v;
    g1[e].next=head1[u];
    head1[u]=e;
    g2[e].from=v;
    g2[e].to=u;
    g2[e].next=head2[v];
    head2[v]=e++;
}

void dfs1(int u)    //正向搜索，获得时间戳
{
    vis[u]=1;
    for(int i=head1[u]; i!=-1; i=g1[i].next)
    {
        int v=g1[i].to;
        if(!vis[v])
            dfs1(v);
    }
    order[++num]=u;
}

void dfs2(int u)    //逆向搜索，寻找强连通分量并计算个数
{
    vis[u]=1;
    belong[u]=cnt;
    for(int i=head2[u]; i!=-1; i=g2[i].next)
    {
        int v=g2[i].to;
        if(!vis[v])
            dfs2(v);
    }
}

void kosaraju()
{
    num=0;
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            dfs1(i);
    }
    memset(vis,0,sizeof(vis));
    for(int i=n; i>=1; i--)
    {
        int v=order[i];
        if(!vis[v])
        {
            cnt++;
            dfs2(v);
        }
    }
    memset(out,0,sizeof(out));
    for(int i=1; i<=n; i++)
    {
        for(int j=head1[i]; j!=-1; j=g1[j].next)
        {
            if(belong[i]!=belong[g1[j].to])
                out[belong[i]]++;
        }
    }
}

int main()
{
    while(~scanf("%d",&n),n)
    {
        memset(head1,-1,sizeof(head1));
        memset(head2,-1,sizeof(head2));
        e=0;
        scanf("%d",&m);
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
        }
        kosaraju();
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++) //sink点的实质是出度为0的强连通分量中的所有点，因为强连通分量中如果有一个点是汇点，则其他所有点都是汇点（根据强连通分量定义）；若有一个点还能到达分量外的其他点，则不满足要求
        {
            if(!out[belong[i]]) //如果某个点所属的强连通分量出度为零，则该强连通分量满足要求
                vis[i]=1;
        }
        bool flag=true;
        for(int i=1; i<=n; i++)
        {
            if(vis[i])  //发现被标记的顶点
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
