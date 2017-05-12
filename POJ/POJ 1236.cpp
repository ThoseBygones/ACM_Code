//tarjan算法
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
#define MAXN 105

int g[MAXN][MAXN];
int out[MAXN],in[MAXN];
int dfn[MAXN];									//第一次访问的步数
int low[MAXN];									//子树中最早的步数						//模拟栈
int instack[MAXN];								//是否在栈中
int cnt;										//记录连通分量的个数
int dfs_clock;										//记录搜索步数（时间戳）
int belong[MAXN];								//属于哪个连通分量
int n;

stack <int> sta;

void init()
{
    cnt=dfs_clock=0;
    while(!sta.empty())
        sta.pop();
    memset(instack,0,sizeof(instack));
    memset(g,0,sizeof(g));
    memset(dfn,0,sizeof(dfn));
}

void tarjan(int u)
{
    dfn[u]=low[u]=++dfs_clock;
    sta.push(u);
    instack[u]=1;
    for(int v=1; v<=n; v++)
    {
        if(g[u][v])
        {
            if(!dfn[v])
            {
                tarjan(v);
                low[u]=min(low[u],low[v]);
            }
            else if(instack[v])
                low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u])
    {
        cnt++;
        while(!sta.empty())
        {
            int temp=sta.top();
            belong[temp]=cnt;
            instack[temp]=0;
            sta.pop();
            if(temp==u)
                break;
        }
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1; i<=n; i++)
        {
            int a;
            while(scanf("%d",&a) && a)
                g[i][a]=1;
        }
        for(int i=1; i<=n; i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        int inzero=0,outzero=0; //记录入度为零和出度为零的点的数量
        for(int i=1; i<=n; i++)
        {
            in[i]=out[i]=0;
        }
        for(int i=1; i<=n; i++)				//找连通分量入度与出度
        {
            for(int j=1; j<=n; j++)
            {
                if(g[i][j] && belong[i]!=belong[j])
                {
                    in[belong[j]]++;
                    out[belong[i]]++;
                }
            }
        }
        for(int i=1; i<=cnt; i++) 			//找入度与出度为0的点
        {
            if(!in[i])
                inzero++;
            if(!out[i])
                outzero++;
        }
        if(cnt==1)					//只有1个结点要特判（因为对于任务B显然不需要加边就能实现，而不特判将得到错误的答案0）
            printf("1\n0\n");
        else
            printf("%d\n%d\n",inzero,max(inzero,outzero));  //任务B的答案为入度和出度为零的点数量的数值大者（什么原因不清楚，但是画图好像是这样的...）
    }
    return 0;
}
*/


//kosaraju算法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 105

int g1[MAXN][MAXN];
int g2[MAXN][MAXN];
int order[MAXN];
int belong[MAXN];
int in[MAXN];
int out[MAXN];
int vis[MAXN];
int n;
int num,cnt;

void dfs1(int u)
{
    vis[u]=1;
    for(int v=1; v<=n; v++)
    {
        if(g1[u][v])
        {
            if(!vis[v])
                dfs1(v);
        }
    }
    order[++num]=u;
}

void dfs2(int u)
{
    belong[u]=cnt;		//记录结点属于哪个连通分量
    vis[u]=1;
    for(int i=1; i<=n; i++)
    {
        if(g2[u][i])
        {
            if(!vis[i])
                dfs2(i);
        }
    }
}

void kosaraju()
{
    memset(vis,0,sizeof(vis));
    num=cnt=0;
    for(int i=1; i<=n; i++)		//第一次搜索将时间戳从小到大排序
    {
        if(!vis[i])
            dfs1(i);
    }
    memset(vis,0,sizeof(vis));
    for(int i=n; i>=1; i--)		//第二次搜索从时间戳大的开始走找连通分量
    {
        int v=order[i];
        if(!vis[v])
        {
            cnt++;		//连通分量个数
            dfs2(v);
        }
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            int a;
            while(scanf("%d",&a) && a)
            {
                g1[i][a]=1;
                g2[a][i]=1;
            }
        }
        kosaraju();
        int inzero=0,outzero=0;
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=1; i<=n; i++)				//找连通分量入度与出度
        {
            for(int j=1; j<=n; j++)
            {
                if(g1[i][j] && belong[i]!=belong[j])
                {
                    in[belong[j]]++;
                    out[belong[i]]++;
                }
            }
        }
        for(int i=1; i<=cnt; i++) 			//找入度与出度为0的点
        {
            if(!in[i])
                inzero++;
            if(!out[i])
                outzero++;
        }
        if(cnt==1)					//只有1个结点要特判
            printf("1\n0\n");
        else
            printf("%d\n%d\n",inzero,max(inzero,outzero));
    }
    return 0;
}
