//KruskalÀ„∑®
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Path
{
    int s;
    int e;
    int len;
} p[5005];

int par[105];

int cmp(Path a,Path b)
{
    return a.len<b.len;
}

int find_set(int x)
{
    if(x!=par[x])
        return find_set(par[x]);
    return par[x];
}

int main()
{
    int n,i,sum,setx,sety;
    while(scanf("%d",&n),n)
    {

        for(i=0; i<n*(n-1)/2; i++)
            scanf("%d%d%d",&p[i].s,&p[i].e,&p[i].len);
        sort(p,p+n*(n-1)/2,cmp);
        for(i=1; i<=n; i++)
            par[i]=i;

        sum=0;
        for(i=0; i<n*(n-1)/2; i++)
        {
            setx=find_set(p[i].s);
            sety=find_set(p[i].e);
            if(setx!=sety)
            {
                par[setx]=sety;
                sum+=p[i].len;
            }
        }
        cout << sum << endl;
    }
    return 0;
}



//PrimÀ„∑®£∫
#include <iostream>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;

int mp[101][101];
int vis[101];
int dis[101],n;
int prim()
{
    for(int i = 2; i <= n; i++)
    {
        vis[i] = 0;
        dis[i] = mp[i][1];
    }
    vis[1] = 1;
    int sum = 0;
    for(int i = 1; i < n; i++)
    {
        int Min = INF;
        int pos;
        for(int j = 1; j <= n; j++)
        {
            if(!vis[j] && dis[j] < Min)
            {
                Min = dis[j];
                pos = j;
            }
        }
        vis[pos] = 1;
        sum += dis[pos];
        for(int j = 1; j <= n; j++)
        {
            if(!vis[j] && dis[j] > mp[pos][j])
                dis[j] = mp[pos][j];
        }
    }
    return sum;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        int u,v,w;
        for(int i = 1; i <= n; i++)
            dis[i] = INF;
        for(int i = 1; i <= (n*(n-1))/2; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            mp[u][v] = mp[v][u] = w;
        }
        printf("%d\n",prim());
    }
    return 0;
}
