#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 100005

vector <int> g1[MAXN],g2[MAXN];
int s[MAXN];
int vis1[MAXN];
int vis2[MAXN];
queue <int> q1,q2;
int n,m;

void bfs1(int x)
{
    vis1[x]=1;
    q1.push(x);
    while(!q1.empty())
    {
        int temp=q1.front();
        q1.pop();
        for(int u=0; u<g1[temp].size(); u++)
        {
            int v=g1[temp][u];
            if(!vis1[v] && s[v]!=1)
            {
                vis1[v]=1;
                q1.push(v);
            }
        }
    }
}

void bfs2(int x)
{
    vis2[x]=1;
    q2.push(x);
    while(!q2.empty())
    {
        int temp=q2.front();
        q2.pop();
        for(int u=0; u<g2[temp].size(); u++)
        {
            int v=g2[temp][u];
            if(s[v]==1)
                vis2[v]=1;  //只要找到1就标记，但是如果访问过就不能再入队！
            if(!vis2[v])
            {
                vis2[v]=1;
                q2.push(v);
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&s[i]);
    for(int i=1; i<=m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g1[u].push_back(v);
        g2[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
    {
        if(s[i]==1)
            bfs1(i);
    }
    for(int i=1; i<=n; i++)
    {
        if(s[i]==2)
            bfs2(i);
    }
    for(int i=1; i<=n; i++)
    {
        if(vis1[i] && vis2[i])
            printf("1\n");
        else
            printf("0\n");
    }
}
