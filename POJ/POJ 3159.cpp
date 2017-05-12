//SPFA+queue£¨TLE³¬Ê±£¡£©
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 30005
#define MAXM 150005
using namespace std;

struct Children
{
    int u;
    int v;
    int w;
    int next;
} c[MAXM];

int head[MAXN],dis[MAXN],vis[MAXN];
int n,m;

void SPFA()
{
    queue <int> q;
    for(int i=1; i<=n; i++)
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
        for(int i=head[temp]; i!=-1; i=c[i].next)
        {
            if(dis[temp]+c[i].w<dis[c[i].v])
            {
                dis[c[i].v]=dis[temp]+c[i].w;
                if(!vis[c[i].v])
                {
                    vis[c[i].v]=1;
                    q.push(c[i].v);
                }
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
            head[i]=-1;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&c[i].u,&c[i].v,&c[i].w);
            c[i].next=head[c[i].u];
            head[c[i].u]=i;
        }
        SPFA();
        printf("%d\n",dis[n]);
    }
    return 0;
}


//SPFA+stack
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#define INF 0x3f3f3f3f
#define MAXN 30005
#define MAXM 150005
using namespace std;

struct Children
{
    int u;
    int v;
    int w;
    int next;
} c[MAXM];

int head[MAXN],dis[MAXN],vis[MAXN];
int n,m;

void SPFA()
{
    stack <int> s;
    for(int i=1; i<=n; i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    dis[1]=0;
    s.push(1);
    vis[1]=1;
    while(!s.empty())
    {
        int temp=s.top();
        s.pop();
        vis[temp]=0;
        for(int i=head[temp]; i!=-1; i=c[i].next)
        {
            if(dis[temp]+c[i].w<dis[c[i].v])
            {
                dis[c[i].v]=dis[temp]+c[i].w;
                if(!vis[c[i].v])
                {
                    vis[c[i].v]=1;
                    s.push(c[i].v);
                }
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
            head[i]=-1;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&c[i].u,&c[i].v,&c[i].w);
            c[i].next=head[c[i].u];
            head[c[i].u]=i;
        }
        SPFA();
        printf("%d\n",dis[n]);
    }
    return 0;
}
