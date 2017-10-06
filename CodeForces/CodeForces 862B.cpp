#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

int color[MAXN];
vector <int> g[MAXN];

void dfs(int u,int fa)
{
    if(color[fa]==1)
        color[u]=2;
    else
        color[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(v!=fa)
            dfs(v,u);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    color[0]=2;
    dfs(1,0);
    LL cnt1=0,cnt2=0;
    for(int i=1; i<=n; i++)
    {
        if(color[i]==1)
            cnt1++;
        else
            cnt2++;
    }
    printf("%I64d\n",cnt1*cnt2-(n-1));
    return 0;
}
