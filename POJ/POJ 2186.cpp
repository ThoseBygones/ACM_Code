//Kosaraju算法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 10005

vector <int> g1[MAXN];  //正向图
vector <int> g2[MAXN];  //逆图

int vis1[MAXN]; //原图的结点访问记录数组
int vis2[MAXN]; //逆图的结点访问记录数组
int belong[MAXN];   //每个结点属于的连通分量的编号
int order[MAXN];    //记录正向搜索时结点的编号
int out[MAXN];  //转化为DAG（有向无环图后各结点的出度
int ans[MAXN];  //每个结点（包括缩点）包括的结点（强连通分量）的个数
int index;  //缩点后DAG图中结点的个数变量
int cnt; //正向搜索时结点编号变量
int n,m;

void dfs1(int u)    //正向搜索，记录时间戳（结点编号）
{
    vis1[u]=1;
    for(int i=0; i<g1[u].size(); i++)
    {
        int v=g1[u][i];
        if(!vis1[v])
            dfs1(v);
    }
    order[cnt++]=u; //回退时记录结点编号（注意：记录的结点顺序与正向搜索的顺序相反）
}

void dfs2(int u)
{
    vis2[u]=1;
    belong[u]=index;
    for(int i=0; i<g2[u].size(); i++)
    {
        int v=g2[u][i];
        if(!vis2[v])
        {
            dfs2(v);
            ans[index]++;   //逆图能搜索到的点，说明这些点跟起点都同属于一个强连通分量
        }
    }
}

void init()
{
    memset(out,0,sizeof(out));
    memset(vis1,0,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
    index=1;
    cnt=1;
}

void kosaraju()
{
    for(int i=0; i<=n; i++)
        ans[i]=1;   //初始化每个结点都不是缩点（只包含一个结点）
    for(int i=1; i<=n; i++) //正向搜索
    {
        if(!vis1[i])
            dfs1(i);
    }
    for(int i=cnt-1; i>=1; i--) //编好号以后，按照正向搜索的顺序（与记录顺序相反的顺序）搜索逆图
    {
        int v=order[i];
        if(!vis2[v])
        {
            dfs2(v);
            index++;
        }
    }
    for(int i=1; i<=n; i++) //构造DAG图
    {
        for(int j=0; j<g1[i].size(); j++)
        {
            if(belong[i]!=belong[g1[i][j]])
                out[belong[i]]++;
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int u,v;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            g1[u].push_back(v);    //构造正向图
            g2[v].push_back(u);    //构造逆图
        }
        init();
        kosaraju();
        int tot=0;
        int res=0;
        for(int i=1; i<index; i++)  //查找每种颜色出度为0的点或缩点，出度为0唯一
        {
            if(!out[i])
            {
                tot++;
                res=ans[i];
            }
        }
        if(tot>=2)  //有向无环图中唯一出度为0的点，一定可以由任何点出发均可达（由于无环，所以从任何点出发往前走，必然终止于一个出度为0的点）
            res=0;
        printf("%d\n",res);
    }
    return 0;
}

//Tarjan算法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

#define MAXN 10005

int N,M;

struct Edge
{
    int to,next;
} edge[MAXN*5];

int head[MAXN],tol;

void addEdge(int u,int v)
{
    edge[tol].to = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}

//tarjan
int Belong[MAXN];
int dfn[MAXN];
int low[MAXN];
//int stack[MAXN];
int clock,Bcnt;
//int top;
bool instack[MAXN];
int out[MAXN];//记录出度

stack <int> sta;

void tarjan(int u)
{
    int v;
    dfn[u] = low[u] = ++clock;  //时间戳
    //stack[top ++] = u;
    sta.push(u);
    instack[u] = true;
    for(int j = head[u]; j != -1; j = edge[j].next)
    {
        v = edge[j].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(instack[v])
            low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        Bcnt ++;
        while(!sta.empty())
        {
            v = sta.top();
            instack[v] = false;
            Belong[v] = Bcnt;
            sta.pop();
            if(u == v)
                break;
        }
    }
}

int main()
{
    int u,v;
    int a,b;//输入要用到的a,b
    scanf("%d%d",&N,&M);

    // 建图
    tol = 0;
    memset(head,-1,sizeof(head));
    while(M --)
    {
        scanf("%d%d",&a,&b);
        addEdge(a,b);
    }

    //tarjan
    memset(dfn,0,sizeof(dfn));
    //Bcnt = top = clock = 0;
    Bcnt = clock = 0;
    for(u = 1; u <= N; u ++)
        if(!dfn[u])
            tarjan(u);

    //tarjan之后求缩点的出度
    memset(out,0,sizeof(out));
    for(u = 1; u <= N; u ++)
    {
        for(int j = head[u]; j != -1; j = edge[j].next)
        {
            v = edge[j].to;
            if(Belong[u] != Belong[v])
                out[Belong[u]] ++;
        }
    }
    int num = 0,ans = 0,flag;//num记录缩点后出度为0的个数，flag记录入度为0的缩点标号(也就是第几个个联通分量)
    for(int i = 1; i <= Bcnt; i ++)
    {
        if(out[i] == 0)
            num ++,flag = i;
    }
    if(num == 1)//只有一个联通分量
    {
        for(int i = 1; i <= N; i ++)
        {
            if(Belong[i] == flag)//这里计算属于这个连通分量的所有牛
                ans ++;
        }
        printf("%d\n",ans);
    }
    else
        printf("0\n");
    return 0;
}
