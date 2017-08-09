#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

//注意：是让原结点编号小的标号尽量小，不是让标号小的原结点编号尽量小因此不能用一般的拓扑排序

priority_queue <int> pq;
vector <int> g[MAXN];

int in[MAXN];
int order[MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[v].push_back(u);
        in[u]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(!in[i])
            pq.push(i);
    }
    int cnt=n;
    while(!pq.empty())
    {
        int u=pq.top();
        pq.pop();
        order[u]=cnt--;
        for(int v=0; v<g[u].size(); v++)
        {
            if(!(--in[g[u][v]]))
                pq.push(g[u][v]);
        }
    }
    for(int i=1; i<n; i++)
        printf("%d ",order[i]);
    printf("%d\n",order[n]);
    return 0;
}
