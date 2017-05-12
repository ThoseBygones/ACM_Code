//Bellman-Ford算法：
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAXV 505
#define MAXN 5410   //2500Roads+200Wormholes
#define INF 0x3f3f3f3f

struct farmland
{
    int u;
    int v;
    int len;
} farm[MAXN];

int n,m,k,cnt;
int dis[MAXV];

void addedge(int nu,int nv,int nl)
{
    farm[cnt].u=nu;
    farm[cnt].v=nv;
    farm[cnt].len=nl;
    cnt++;
}

int Bellman_Ford()
{
    for(int i=1; i<=n; i++)
        dis[i]=INF;
    dis[1]=0;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<cnt; j++)
        {
            if(dis[farm[j].v]>dis[farm[j].u]+farm[j].len)
                dis[farm[j].v]=dis[farm[j].u]+farm[j].len;
        }
    }
    for(int j=0; j<cnt; j++)
    {
        if(dis[farm[j].v]>dis[farm[j].u]+farm[j].len)
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        cnt=0;
        int u,v,l;
        for(int i=0; i<m; i++)
        {
            cin >> u >> v >> l;
            addedge(u,v,l);
            addedge(v,u,l);
        }
        for(int i=0; i<k; i++)
        {
            cin >> u >> v >> l;
            addedge(u,v,-l);
        }
        int ans=Bellman_Ford();
        if(ans)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}


//SPFA算法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 505
#define MAXM 2705   //2500Roads+200Wormholes
#define INF 0x3f3f3f3f
using namespace std;

struct Edge
{
    int v;  //边的终点
    int len;    //边的长度
    int next;   //下一个点
} edge[MAXM*2];

int dis[MAXN];
int inq[MAXN];  //判断某个点是否在队列中
int vis[MAXN];
int pre[MAXN];  //某一点的源点
int n,m,w;
int cnt;

queue <int> q;

void addEdge(int u,int v,int l)
{
    edge[cnt].v=v;
    edge[cnt].len=l;
    edge[cnt].next=pre[u];
    pre[u]=cnt++;
}

bool SPFA()
{
    dis[1]=0;
    q.push(1);
    vis[1]++;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        inq[temp]=0;
        for(int i=pre[temp]; i!=-1; i=edge[i].next)
        {
            if(dis[temp]+edge[i].len<dis[edge[i].v])
            {
                dis[edge[i].v]=dis[temp]+edge[i].len;
                if(!inq[edge[i].v])
                {
                    inq[edge[i].v]=1;
                    vis[edge[i].v]++;
                    if(vis[edge[i].v]>=n)   //SPFA算法中，一个点入队次数超过n次，说明有向网中存在负权值回路
                        return true;
                    q.push(edge[i].v);
                }
            }
        }
    }
    return false;
}

int main()
{
    int f;
    scanf("%d",&f);
    while(f--)
    {
        scanf("%d%d%d",&n,&m,&w);
        for(int i=1; i<=n; i++)
        {
            dis[i]=INF;
            inq[i]=0;
            vis[i]=0;
            pre[i]=-1;
        }
        cnt=0;
        for(int i=0; i<m; i++)
        {
            int u,v,l;
            scanf("%d%d%d",&u,&v,&l);
            addEdge(u,v,l);
            addEdge(v,u,l);
        }
        for(int i=0; i<w; i++)
        {
            int u,v,l;
            scanf("%d%d%d",&u,&v,&l);
            addEdge(u,v,-l);
        }
        if(SPFA())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
