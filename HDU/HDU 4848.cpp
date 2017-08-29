#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <map>
using namespace std;

#define MAXN 35
#define INF 0x3f3f3f3f
#define PII pair
#define MP make_pair
#define LL long long
#define PB push_back
#define MOD 1000000007

int n;
int g[MAXN][MAXN];
int d[MAXN][MAXN];
int vis[MAXN];
int lim[MAXN];  //到达每个星球的deadline
int ans;

void floyd()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}

void dfs(int u,int cnt,int t,int sumt)  //t为到达某个星球的时间，sumt为到达所有星球的总时间
{
    if(cnt==n)
    {
        ans=min(ans,sumt);
        return ;
    }
    if(sumt>ans) //当前方案比目前最优方案耗时长即可停止继续当前方案的搜索
        return ;
    for(int v=2; v<=n; v++)
    {
        if(!vis[v])
        {
            if(t+d[u][v]>lim[v])   //可能去的下一个点中有任何一个没法在deadline内到达，则可以停止搜索
                return ;
        }
    }
    for(int v=2; v<=n; v++)
    {
        if(!vis[v])
        {
            vis[v]=1;
            dfs(v,cnt+1,t+d[u][v],sumt+d[u][v]*(n-cnt));
            vis[v]=0;   //还原现场
        }
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                scanf("%d",&d[i][j]);
        }
        for(int i=2; i<=n; i++)
            scanf("%d",&lim[i]);
        floyd();
        memset(vis,0,sizeof(vis));
        ans=INF;
        dfs(1,1,0,0);
        if(ans==INF)
            puts("-1");
        else
            printf("%d\n",ans);
    }
    return 0;
}
