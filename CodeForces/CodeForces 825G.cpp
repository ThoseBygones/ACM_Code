//LCA问题
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define INF 0x3f3f3f3f

vector <int> g[MAXN];
int lca[MAXN];

//求某一点到黑点的简单路径上编号最小的点。问题转化为求最近公共祖先（LCA）

void dfs(int u,int fa)
{
    lca[u]=min(u,lca[fa]);
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(v!=fa)
            dfs(v,u);
    }
}

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);

    }
    fill(lca,lca+n,INF);
    int last=0;
    q--;    //处理第一个(t==1的)操作
    int t,z;
    scanf("%d%d",&t,&z);
    int x=(z+last)%n+1;
    dfs(x,0);  //以第一个染成黑色的点作为根结点遍历
    int Min=x;
    while(q--)
    {
        scanf("%d%d",&t,&z);
        x=(z+last)%n+1;
        if(t==1)
            Min=min(lca[x],Min);
        else
        {
            last=min(Min,lca[x]);
            printf("%d\n",last);
        }
    }
    return 0;
}
