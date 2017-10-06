#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int a[MAXN];
set <int> s[MAXN];  //the possible gcd result of every node
vector <int> g[MAXN];

void dfs(int u,int fa,int now)
{
    for(set<int>::iterator it=s[fa].begin(); it!=s[fa].end(); it++)
        s[u].insert(__gcd(a[u],*it));
    s[u].insert(now);   //insert gcd(0,now);
    now=__gcd(now,a[u]);
    s[u].insert(now);
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(v!=fa)
            dfs(v,u,now);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0); //1的父结点不能设为-1，否则后面set遍历会下标越界
    for(int i=1; i<=n; i++)
    {
        if(i==n)
            printf("%d\n",*s[i].rbegin());
        else
            printf("%d ",*s[i].rbegin());
    }
    return 0;
}
