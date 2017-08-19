#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

vector <int> g[MAXN];
int d[2][MAXN]; //Alice和Bob从各自的出发点到其余各点的距离。0--Alice，1--Bob

void dfs(int u,int fa,int step,int flag)
{
    if(g[u].size()==1 && u!=1)  //到叶结点且不是根结点
        d[flag][u]=step;    //更新答案后不能返回
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(v!=fa)
            dfs(v,u,step+1,flag);
    }
}

int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1,0,0);
    dfs(x,-1,0,1);
    int ans=0;
    for(int i=2; i<=n; i++)
    {
        if(g[i].size()==1 && d[0][i]>d[1][i])   //该点是叶结点且Alice到达所需时间比Bob长
            ans=max(d[0][i],ans);
    }
    printf("%d\n",ans*2);
    return 0;
}
