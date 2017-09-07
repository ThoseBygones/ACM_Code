#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005

struct Edge
{
    int v,w;
    int next;
} e[MAXN<<1];

int head[MAXN];
int cnt;
int dp[MAXN][3];
//dp[u][0]表示在u的子树下u的最远距离是多少
//dp[u][1]表示在u的子树下（和dp[u][0]不是同一孩子）u的次远距离是多少
//dp[u][2]表示通过u的父亲能走的最远距离是多少

void addEdge(int u,int v,int w)
{
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs1(int u,int fa)  //每个结点子树下的最大和次大
{
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        int w=e[i].w;
        dfs1(v,u);
        if(dp[v][0]+w>=dp[u][0])
        {
            dp[u][1]=dp[u][0];
            dp[u][0]=dp[v][0]+w;
        }
        else if(dp[v][0]+w>dp[u][1])
            dp[u][1]=dp[v][0]+w;
    }
}

void dfs2(int u,int fa)
{
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        int w=e[i].w;
        if(dp[u][0]==dp[v][0]+w)    //说明该路径来自子树
            dp[v][2]=max(dp[u][2],dp[u][1])+w;
        else
            dp[v][2]=max(dp[u][2],dp[u][0])+w;
        dfs2(v,u);
    }
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int v=2; v<=n; v++)
        {
            int u,w;
            scanf("%d%d",&u,&w);
            addEdge(u,v,w);
        }
        memset(dp,0,sizeof(dp));
        dfs1(1,-1);
        dfs2(1,-1);
        for(int i=1; i<=n; i++)
            printf("%d\n",max(dp[i][0],dp[i][2]));
    }
    return 0;
}
