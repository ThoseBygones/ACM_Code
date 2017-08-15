#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

vector <int> g[MAXN];
int vis[MAXN];
double ans;
int n;

void dfs(int u,int cnt,double p)
{
    vis[u]=1;
    int sz=g[u].size();
    if(sz==1 && u!=1)
    {
        ans+=p*cnt;
        return ;
    }
    for(int i=0; i<sz; i++)
    {
        int v=g[u][i];
        if(!vis[v])
        {
            if(u==1)
                dfs(v,cnt+1,p/(double)sz);
            else
                dfs(v,cnt+1,p/(double)(sz-1));
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(vis,0,sizeof(vis));
    ans=0.0;
    dfs(1,0,1.0);
    printf("%.15f\n",ans);
    return 0;
}
