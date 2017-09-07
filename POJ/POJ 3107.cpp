//树形dp+树的重心
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 50010
#define INF 0x3f3f3f3f

struct Edge
{
    int to;
    int next;
} e[MAXN<<1];

int head[MAXN];
int dp[MAXN];
int num[MAXN];
int n;
int cnt;

vector <int> ans;

void addEdge(int u,int v)
{
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int u,int fa)
{
    dp[u]=0;
    num[u]=1;
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(v!=fa)
        {
            dfs(v,u);
            num[u]+=num[v];
            dp[u]=max(dp[u],num[v]);
        }
    }
    dp[u]=max(dp[u],n-num[u]);
}

int main()
{
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    cnt=0;
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1,-1);
    int minnum=INF;
    int p=-1;
    for(int i=1; i<=n; i++)
        minnum=min(minnum,dp[i]);
    for(int i=1; i<=n; i++)
    {
        if(dp[i]==minnum)
            ans.push_back(i);
    }
    for(int i=0; i<ans.size(); i++)
    {
        if(!i)
            printf("%d",ans[i]);
        else
            printf(" %d",ans[i]);
    }
    puts("");
    return 0;
}
