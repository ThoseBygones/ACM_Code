#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005

struct Edge
{
    int to;
    int cost;
    int next;
} e[MAXN];

int head[MAXN];
int dp[MAXN][2];    //dp[i][0/1]表示以i点为树根（从i点出发）能到最远儿子的距离和到次远儿子的距离
int cnt;
int ans;

void addEdge(int u,int v,int w)
{
    e[cnt].to = v;
    e[cnt].cost = w;
    e[cnt].next = head[u];
    head[u]=cnt++;
}

void dfs(int u,int fa)
{
    dp[u][0] = dp[u][1] = 0;
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v = e[i].to;
        int w = e[i].cost;
        if(v != fa)
        {
            dfs(v, u);
            if(dp[u][0] < dp[v][0] + w) //更新到最远儿子的距离
            {
                dp[u][1] = dp[u][0];    //到最远儿子的距离更新为到次远儿子的距离
                dp[u][0] = dp[v][0] + w;
            }
            else if(dp[u][1] < dp[v][0] + w)    //到最远儿子的距离不需要更新，只需要更新到次远儿子的距离
                dp[u][1] = dp[v][0] + w;
        }
    }
    //到最远儿子的距离 + 到次远儿子的距离 = 树的直径
    ans = max(ans, dp[u][0] + dp[u][1]);    //更新最大值
}

int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    memset(head,-1,sizeof(head));
    cnt=0;
    ans=0;
    int sum=0;
    for(int i=1; i<n; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addEdge(u,v,w);
        addEdge(v,u,w);
        sum+=2*w;   //因为是树，因此如果要回到起点的话每条边都应该被经过两次
    }
    dfs(s,-1);
    printf("%d\n",sum-ans); //使遍历的总路程尽量短，因此求出树的直径（树上最长路），尽量保证直径部分只走一次不重复
    return 0;
}
