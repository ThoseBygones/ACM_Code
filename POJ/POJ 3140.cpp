#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100010
#define LL long long
#define LINF 1LL<<62

struct Edge
{
    int to;
    int next;
} e[MAXN<<1];

int head[MAXN];
LL dp[MAXN];
int cnt;
LL Min;
LL sum;

LL Labs(LL val)
{
    return val<0?-val:val;
}

void addEdge(int u,int v)
{
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int u,int fa)
{
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)
            continue;
        dfs(v,u);
        dp[u]+=dp[v];
        Min=min(Min,Labs((sum-dp[v])-dp[v]));
    }
    //Min=min(Min,Labs((sum-dp[u])-dp[u]));
}

int main()
{
    int kase=1;
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 || m==0)
            break;
        memset(head,-1,sizeof(head));
        cnt=0;
        sum=0;
        Min=LINF;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&dp[i]);
            sum+=dp[i];
        }
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        dfs(1,-1);
        printf("Case %d: %lld\n",kase++,Min);
    }
    return 0;
}
