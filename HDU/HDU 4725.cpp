#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 200010 //100000点+100000点化层
#define INF 0x3f3f3f3f
using namespace std;

struct Edge
{
    int v;
    int w;
    int next;
} edge[MAXN*10];

int dis[MAXN];
int vis[MAXN];
int head[MAXN];
int p[MAXN];  //记录每个点在哪个层
int lay[MAXN];  //记录某个层上是否有点
int n,m,c;
int cnt;

void addEdge(int u,int v,int w)
{
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void SPFA()
{
    queue <int> q;
    for(int i=1; i<=2*n; i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    dis[1]=0;
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        vis[temp]=0;
        for(int i=head[temp]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].v;
            int w=edge[i].w;
            if(dis[temp]+w<dis[v])
            {
                dis[v]=dis[temp]+w;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    int kase=1;
    while(t--)
    {
        cnt=0;
        scanf("%d%d%d",&n,&m,&c);
        for(int i=1; i<=2*n; i++)
        {
            head[i]=-1;
            p[i]=0;
            lay[i]=0;
        }
        for(int i=1; i<=n; i++)
        {
            int x;
            scanf("%d",&x);
            p[i]=x;
            lay[x]=1;
        }
        for(int i=1; i<n; i++)
        {
            if(lay[i] && lay[i+1])  //相邻层建边
            {
                addEdge(n+i,n+i+1,c);
                addEdge(n+i+1,n+i,c);
            }
        }
        for(int i=1; i<=n; i++)
        {
            addEdge(n+p[i],i,0);  //层到同层的点建边
            if(p[i]>1)    //点到相邻层建边
                addEdge(i,n+p[i]-1,c);//,cout << i << " " << p[i]-1 << endl;
            if(p[i]<n)
                addEdge(i,n+p[i]+1,c);//,cout << i << " " << p[i]+1 << endl;
        }
        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
            addEdge(v,u,w);
        }
        SPFA();
        if(dis[n]==INF)
            printf("Case #%d: -1\n",kase++);
        else
            printf("Case #%d: %d\n",kase++,dis[n]);
    }
    return 0;
}
