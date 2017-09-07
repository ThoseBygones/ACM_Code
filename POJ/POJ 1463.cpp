#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1510

struct Edge
{
    int to;
    int next;
} e[MAXN<<1];

int head[MAXN];
int dp[MAXN][2];    //dp[i][0/1]表示第i个结点不选/选最小的点覆盖数
int n;
int cnt;

void addEdge(int u,int v)
{
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int u,int fa)
{
    dp[u][0]=0;
    dp[u][1]=1;
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(v!=fa)
        {
            dfs(v,u);
            dp[u][0]+=dp[v][1];
            dp[u][1]+=min(dp[v][0],dp[v][1]);
        }
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=0; i<n; i++)
        {
            int u,num;
            scanf("%d:(%d)",&u,&num);
            while(num--)
            {
                int v;
                scanf("%d",&v);
                addEdge(u,v);
                addEdge(v,u);
            }
        }
        dfs(0,-1);
        printf("%d\n",min(dp[0][0],dp[0][1]));
    }
    return 0;
}
