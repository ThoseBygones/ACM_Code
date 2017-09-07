#include <bits/stdc++.h>
using namespace std;

#define MAXN 300005
#define PII pair<int,int>
#define MP make_pair
#define PB push_back

int vis[MAXN];
int del[MAXN];
vector <PII> g[MAXN];
queue <PII> q;
int n,k,d;
int ans;

void bfs()
{
    while(!q.empty())
    {
        int u=q.front().first;
        int fa=q.front().second;
        q.pop();
        if(vis[u])
            continue;
        vis[u]=1;
        for(int i=0; i<g[u].size(); i++)
        {
            int v=g[u][i].first;
            int id=g[u][i].second;
            if(v!=fa)   //不是环
            {
                if(vis[v])  //该点被访问过
                {
                    del[id]=1;   //目前选择的边不是最短的，则可以删除
                    ans++;
                }
                else
                    q.push(MP(v,u));
            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&k,&d);
    for(int i=1; i<=k; i++)
    {
        int x;
        scanf("%d",&x);
        q.push(MP(x,0));
    }
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(MP(v,i));
        g[v].PB(MP(u,i));
    }
    ans=0;
    bfs();
    printf("%d\n",ans);
    bool flag=true;
    for(int i=1; i<n; i++)
    {
        if(del[i])
        {
            if(flag)
            {
                printf("%d",i);
                flag=false;
            }
            else
                printf(" %d",i);
        }
    }
    puts("");
    return 0;
}
