#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 100005

vector <int> e[MAXN*2];

int color[MAXN*2];
pair <int,int> ans[MAXN];   //每队男女朋友

void addEdge(int u,int v)
{
    e[u].push_back(v);
    e[v].push_back(u);
}

bool bipartite(int u)   //DFS交叉染色判断二分图
{
    for(int i = 0; i<e[u].size(); i++)
    {
        int v = e[u][i];
        if(color[v]==color[u])
            return false;
        if(!color[v])
        {
            color[v] = 3-color[u];
            if(!bipartite(v))
                return false;
        }
    }
    return true;
}

bool checkBipartite(int n)
{
    memset(color,0,sizeof(color));
    bool ok = true;
    for(int i=1; i<=2*n; i++)
    {
        if(!color[i])
        {
            color[i] = 1;
            if(!bipartite(i)) ok = false;
            bipartite(i);
        }
    }
    return ok;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) //每三个人中至少有两个人被染成不同的颜色
    {
        int u=2*i;
        int v=2*i+1;
        addEdge(u,v);
        addEdge(v,u);
    }
    for(int i=1; i<=n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        ans[i]=make_pair(u,v);
        addEdge(u,v);
        addEdge(v,u);
    }
    checkBipartite(n);
    //if(!checkBipartite(n))
    //    puts("-1");
    //else
    //{
        for(int i=1; i<=n; i++)
            printf("%d %d\n",color[ans[i].first],color[ans[i].second]);
    //}
    return 0;
}
