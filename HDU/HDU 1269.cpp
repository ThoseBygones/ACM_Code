//数组模拟栈
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005

struct Node
{
    int v;
    int next;
} edge[MAXN*10];

int head[MAXN]; //头结点数组
int sta[MAXN];    //堆栈数组
int dfn[MAXN]; //深度优先数数组
int low[MAXN];  //该结点或者该结点的的子树结点所能追溯到的最早栈中结点的深度优先数
int belong[MAXN];   //每个结点对应的强连通分量标号数组
int instack[MAXN];  //每个结点是否在堆栈中的标记数组
int n,m;
int cnt;    //邻接表数量
int scnt;   //连通分量标号
int index;  //时间戳
int top;    //栈顶指针

void init()
{
    memset(head,-1,sizeof(head));
    memset(sta,0,sizeof(sta));
    memset(dfn,0,sizeof(dfn));
    memset(belong,0,sizeof(belong));
    memset(instack,0,sizeof(instack));
    top=0;
    cnt=scnt=0;
    index=0;
}

void addEdge(int u,int v)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void tarjan(int u)  //Tarjan算法求有向图的强连通分量
{
    dfn[u]=low[u]=++index;
    sta[top++]=u;   //进栈;
    instack[u]=true;    //标记在栈中
    for(int i=head[u]; i!=-1; i=edge[i].next)   //枚举u的每一条边
    {
        int v=edge[i].v;
        if(!dfn[v])
        {
            tarjan(v);  //dfs搜索
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v]) //如果结点还在栈内
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])  //如果结点是连通分量的根
    {
        scnt++; //连通分量数量+1
        while(top!=0)   //将该连通分量中的每一个结点出栈
        {
            int temp=sta[--top];
            instack[temp]=0;
            belong[temp]=scnt;
            if(temp==u) //直到该连通分量的根结点也出栈时停止
                break;
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m),m,n)
    {
        init();
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
        }
        for(int i=1; i<=n; i++) //枚举每个结点，搜索连通分量
        {
            if(!dfn[i])
                tarjan(i);
        }
        if(scnt==1) //如果只存在一个连通分量
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}


//利用STL栈
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

#define MAXN 10005

struct Node
{
    int v;
    int next;
} edge[MAXN*10];

stack <int> sta;

int head[MAXN]; //头结点数组
int dfn[MAXN]; //深度优先数数组
int low[MAXN];  //该结点或者该结点的的子树结点所能追溯到的最早栈中结点的深度优先数
int belong[MAXN];   //每个结点对应的强连通分量标号数组
int instack[MAXN];  //每个结点是否在堆栈中的标记数组
int n,m;
int cnt;    //邻接表数量
int scnt;   //连通分量标号
int index;  //时间戳

void init()
{
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(belong,0,sizeof(belong));
    memset(instack,0,sizeof(instack));
    while(!sta.empty()) //清空栈
        sta.pop();
    cnt=scnt=0;
    index=0;
}

void addEdge(int u,int v)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void tarjan(int u)  //Tarjan算法求有向图的强连通分量
{
    dfn[u]=low[u]=++index;
    sta.push(u);    //进栈
    instack[u]=true;    //标记在栈中
    for(int i=head[u]; i!=-1; i=edge[i].next)   //枚举u的每一条边
    {
        int v=edge[i].v;
        if(!dfn[v])
        {
            tarjan(v);  //dfs搜索
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v]) //如果结点还在栈内
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])  //如果结点是连通分量的根
    {
        scnt++; //连通分量数量+1
        while(!sta.empty())   //将该连通分量中的每一个结点出栈
        {
            int temp=sta.top();
            instack[temp]=0;
            belong[temp]=scnt;
            sta.pop();
            if(temp==u) //直到该连通分量的根结点也出栈时停止
                break;
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m),m,n)
    {
        init();
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
        }
        for(int i=1; i<=n; i++) //枚举每个结点，搜索连通分量
        {
            if(!dfn[i])
                tarjan(i);
        }
        if(scnt==1) //如果只存在一个连通分量
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
